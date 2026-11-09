#include <stdio.h>

int main(void) {
    double a, b, c; scanf("%lf%lf%lf", &a, &b, &c);
    double average = (a + b + c) / 3.0;
    char grade;
    if (average >= 90) grade = 'A';
    else if (average >= 80) grade = 'B';
    else if (average >= 70) grade = 'C';
    else if (average >= 60) grade = 'D';
    else grade = 'E';
    printf("%c\n", grade); return 0;
}
