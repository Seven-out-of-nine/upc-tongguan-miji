"""Compile the published standalone solutions and run the bundled test cases."""
import argparse
import concurrent.futures
import json
import os
from pathlib import Path
import shutil
import subprocess
import tempfile


def normalized(text):
    """Ignore trailing spaces/blank lines; keep meaningful leading indentation."""
    return '\n'.join(line.rstrip() for line in text.replace('\r\n', '\n').split('\n')).rstrip('\n')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--compiler-dir', type=Path, help='Folder containing gcc and g++')
    parser.add_argument('--only', default='', help='Only check IDs beginning with this prefix')
    parser.add_argument('--jobs', type=int, default=4)
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    tests = json.loads((root / 'tests' / 'cases.json').read_text(encoding='utf-8'))
    tests = {key: value for key, value in tests.items() if key.startswith(args.only)}
    if not tests:
        parser.error('No matching problem IDs')
    compiler_names = {'c': os.environ.get('CC', 'gcc'), 'cpp': os.environ.get('CXX', 'g++')}
    compilers = {}
    for language in {t['language'] for t in tests.values()}:
        name = compiler_names[language]
        if args.compiler_dir:
            path = args.compiler_dir / (name + '.exe' if os.name == 'nt' and not name.endswith('.exe') else name)
            if not path.is_file():
                parser.error('Compiler not found: ' + str(path))
            compilers[language] = str(path)
        else:
            found = shutil.which(name)
            if not found:
                parser.error('Compiler not found: ' + name)
            compilers[language] = found
    with tempfile.TemporaryDirectory(prefix='programming-check-') as temp:
        build = Path(temp)

        def run_one(item):
            ident, spec = item
            language = spec['language']
            exe = build / (ident + ('.exe' if os.name == 'nt' else ''))
            cmd = [compilers[language], '-std=c11' if language == 'c' else '-std=c++11',
                   '-D__USE_MINGW_ANSI_STDIO=1', '-O2', '-Wall', '-Wextra',
                   str(root / spec['source']), '-o', str(exe)]
            if language == 'c':
                cmd.append('-lm')
            compiled = subprocess.run(cmd, capture_output=True, timeout=60)
            if compiled.returncode:
                return ident, 0, ['COMPILE: ' + compiled.stderr.decode('utf-8', errors='replace')]
            env = os.environ.copy()
            env['PATH'] = str(Path(compilers[language]).parent) + os.pathsep + env.get('PATH', '')
            errors = []
            for index, case in enumerate(spec['cases'], 1):
                try:
                    result = subprocess.run([str(exe)], input=case['input'].encode('utf-8'),
                                            capture_output=True, env=env, timeout=10)
                    actual = result.stdout.decode('utf-8', errors='replace')
                    if result.returncode or normalized(actual) != normalized(case['output']):
                        errors.append(f'CASE {index} ({case["reason"]}): expected {case["output"]!r}, got {actual!r}, exit {result.returncode}')
                except subprocess.TimeoutExpired:
                    errors.append(f'CASE {index}: TIMEOUT')
            return ident, len(spec['cases']), errors

        with concurrent.futures.ThreadPoolExecutor(max_workers=max(1, args.jobs)) as executor:
            results = list(executor.map(run_one, tests.items()))
    failed = [(ident, errors) for ident, _, errors in results if errors]
    for ident, errors in failed:
        print(ident)
        for error in errors:
            print('  ' + error)
    total = sum(count for _, count, _ in results)
    print(f'{len(results)} programs, {total} test cases, {len(failed)} failing programs')
    return 1 if failed else 0


if __name__ == '__main__':
    raise SystemExit(main())
