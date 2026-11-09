# 一起建设油专通关秘籍

[返回社区首页](README.md) · [发起 Issue](https://github.com/Seven-out-of-nine/upc-tongguan-miji/issues/new/choose) · [查看 Pull Requests](https://github.com/Seven-out-of-nine/upc-tongguan-miji/pulls)

欢迎分享课程资料，也欢迎补充来源、核对答案、改进学习路线和修正文档。一份小的、说明清楚的贡献，就可以帮助后来使用资料的同学。

## 🚀 选择适合你的方式

| 情况 | 从哪里开始 |
| --- | --- |
| 第一次接触 GitHub，只想上传资料 | [首页六步网页教程](README.md#first-upload)，无需安装 Git |
| 会使用 Git，想批量整理文件 | 下方的 Git 操作流程 |
| 想新增课程、讨论整理方式或请人帮忙上传 | [资料分享 Issue](https://github.com/Seven-out-of-nine/upc-tongguan-miji/issues/new?template=share_materials.md) |
| 发现内容错误、文件问题或有社区建议 | [反馈与建议 Issue](https://github.com/Seven-out-of-nine/upc-tongguan-miji/issues/new?template=feedback.md) |

Issue 是交流入口；要让资料进入主仓库，仍需要通过 PR，由维护者审核合并。无需先申请原仓库的写权限。[^fork]

## 🗂️ 放在哪里、怎样命名

同学们提交的课堂笔记、知识总结、错题笔记和复习笔记，统一放在 **`课程名称/笔记分享/`**，不要直接散放在课程根目录或另建并列的笔记目录。可在 `笔记分享/` 内按学年、章节或主题继续分组。

已有课程的课件、习题、历年试题等其他资料，继续沿用现有分类。新增课程时请同时建立课程 README 和 `笔记分享/README.md`，例如：

```text
课程名称/
├── README.md
├── 笔记分享/
├── 复习提纲/
├── 习题与解答/
└── 历年试题/
```

其中 `笔记分享/` 是同学笔记的统一入口，其余分类按资料情况补充，不要求建齐。请保留原有文件和有效链接；新增版本与旧版本不同，说明差异后并列保存即可。

| 内容 | 文件名示例 |
| --- | --- |
| 个人笔记 | `2026-2027_图论_个人复习笔记.pdf` |
| 历年试卷 | `2025-2026_期末_A卷_题目.pdf` |
| 答案或个人解答 | `2025-2026_期末_A卷_个人解答_待核对.pdf` |
| Markdown 知识总结 | `第三章_关系与函数_知识点.md` |

示例学年仅展示命名方式，请填写资料实际对应的年份。优先分享便于直接查看的 PDF、Markdown 和原始课件；需要保留可编辑版本时可以一并上传。

新课程 README 可以从下面几行开始：

```markdown
# 课程名称

## 资料说明

- 内容：这份资料包含哪些章节或题型。
- 适用范围：学年、课程版本或教材版本，不确定可写待补。
- 来源／整理者：作者、公开来源链接或个人整理说明。
- 答案情况：无答案、参考答案或个人演算，注明待核对部分。

## 文件导航

- [资料名称](笔记分享/资料文件名.pdf)
```

## 💻 使用 Git 提交资料

先在网页上 Fork 本仓库。下面以一个新的贡献分支为例，命令中的 `YOUR_USERNAME` 请替换为自己的 GitHub 用户名。`origin` 指向你自己的 Fork，`upstream` 指向本仓库。

### 1. 克隆自己的 Fork 并新建分支

```bash
git clone https://github.com/YOUR_USERNAME/upc-tongguan-miji.git
cd upc-tongguan-miji
git remote add upstream https://github.com/Seven-out-of-nine/upc-tongguan-miji.git
git switch -c materials/discrete-notes
```

如果创建 Fork 时修改了仓库名，请使用自己仓库 **Code** 按钮提供的地址和实际文件夹名。分支名也可换成能说明本次贡献的名称。

### 2. 放入文件、检查并提交

把笔记放进对应课程的 `笔记分享/`，需要时更新笔记目录 README 或课程导航；其他类型的资料放进相应分类。以下路径只是例子，应替换为你实际新增或修改的文件。

```bash
git status --short
git add -- "离散数学/笔记分享/2026-2027_图论_个人复习笔记.pdf" "离散数学/README.md"
git diff --cached --stat
git commit -m "补充离散数学图论复习笔记"
git push -u origin materials/discrete-notes
```

提交前确认文件列表里没有无关文件；图片、PDF 等二进制资料也请先自行打开查看。首次使用 Git 如提示未设置姓名或邮箱，按提示配置自己的提交身份后重试。

### 3. 提交 PR 并跟进

回到 GitHub，向 `Seven-out-of-nine/upc-tongguan-miji` 的 `main` 分支创建 PR，来源选择自己的 Fork 和 `materials/discrete-notes` 分支。按模板说明内容、来源及适用范围。

需要修改时，在同一分支继续提交并 `git push`，已有 PR 会更新，不必为同一批修改反复新开 PR。[^pr]

### 4. 下次贡献前同步

确认工作区没有未提交的修改，再同步主仓库并从最新版本新建一个分支：

```bash
git fetch upstream
git switch main
git merge --ff-only upstream/main
git push origin main
git switch -c materials/next-topic
```

如果 `--ff-only` 提示分支已分叉，先保留自己的修改并开 Issue 求助，或按 Git 提示处理；不要为了同步强行覆盖分支。

## 📝 PR 和 Issue 写什么

PR 尽量围绕一门课或一件事，便于维护者核对。写清以下信息即可，暂时不确定的内容直接说明：

- 哪门课程，新增、更新或纠正了什么。
- 适用的学年、章节、教材或课程版本。
- 资料来源、原作者或个人整理说明，以及是否允许公开分享。
- 是否有答案；是原参考答案还是个人演算；哪些地方仍待核对。

开 Issue 时，资料分享可说明文件类型、大小和建议目录；分享笔记时，目录填写 `课程名称/笔记分享/`；勘误可附文件路径、页码／题号、问题与修改依据。把文件附在 Issue 中便于交流，但附件不会自动成为仓库中的文件。

## 🔧 常见问题

| 问题 | 可以怎样处理 |
| --- | --- |
| 只上传到了自己的仓库 | 再发起 PR，目标选本仓库的 `main` 分支 |
| 提示 `There isn't anything to compare` | 确认已把新文件提交到自己的 Fork，并选中了正确的来源分支 |
| 提示没有权限 | 把文件推到自己的 Fork，再向本仓库提 PR；不要直接推送原仓库 |
| 网页上传提示文件太大 | 网页单文件上限25 MiB；超过这一大小且不超过100 MiB时，可改用 Git；超过100 MiB先开 Issue讨论分享方式[^upload] |
| 一次选择的文件太多 | 网页每次最多上传100个文件，可以分批提交；分批不能解决单个文件过大的问题[^upload] |
| Git 看不到压缩包或临时文件 | 本仓库的 `.gitignore` 默认忽略压缩包和临时文件。优先解压后按课程放入；确有保留原压缩包的需要时，在 PR 中说明，并仅对该文件使用 `git add -f -- "实际路径.zip"` |
| 有资料，但年份、来源或答案不完整 | 如实注明待补充，先开 Issue 交流；不要猜测填写 |
| PR 还没合并 | 看一下是否有维护者留言；合并前资料保留在你的 Fork 中 |

## 🌱 共同维护学习氛围

友善交流，讨论具体内容，尊重不同解法。保留作者署名和资料授权说明，分享自己整理、已获授权或允许公开分享的内容；上传前去除个人学号、联系方式等信息。

欢迎把尚未完善但有价值的整理拿出来讨论，标清不确定之处，也欢迎其他同学接力补充。每个人都可以从一处小改进开始。

[^fork]: GitHub 官方：[从 Fork 创建 Pull Request](https://docs.github.com/en/pull-requests/how-tos/create-pull-requests/creating-a-pull-request-from-a-fork)。
[^pr]: GitHub 官方：[创建 Pull Request 与继续修改](https://docs.github.com/en/pull-requests/how-tos/create-pull-requests/creating-a-pull-request)。
[^upload]: GitHub 官方：[向仓库添加文件及文件大小限制](https://docs.github.com/en/repositories/working-with-files/managing-files/adding-a-file-to-a-repository)。
