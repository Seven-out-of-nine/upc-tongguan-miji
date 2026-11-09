#include <stdio.h>
#include <string.h>

void read_line(char s[], int size) {
    if (!fgets(s, size, stdin)) { s[0] = '\0'; return; }
    int i = 0;
    while (s[i] && s[i] != '\n') ++i;
    int end = i;
    if (s[i] == '\n' && i > 0 && s[i - 1] == '\r') --end;
    s[end] = '\0';
}
int main(void) {
    const int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    const char check[] = "10X98765432";
    char s[22]; read_line(s, sizeof s);
    int valid = strlen(s) == 18, sum = 0;
    if (valid) {
        for (int i = 0; i < 17; ++i) {
            if (s[i] < '0' || s[i] > '9') { valid = 0; break; }
            sum += (s[i] - '0') * weight[i];
        }
        if (valid && s[17] != check[sum % 11]) valid = 0;
    }
    puts(valid ? "Valid" : "Invalid"); return 0;
}
