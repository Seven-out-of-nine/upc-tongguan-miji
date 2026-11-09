#include <stdio.h>

int main(void) {
    int age, weight; scanf("%d,%d", &age, &weight);
    int lower = age == 1 ? 200 : 300;
    char grade;
    if (weight <= lower) grade = 'B';
    else if (weight <= lower + 100) grade = 'A';
    else grade = 'S';
    printf("%d%d%c\n", age, weight / 100, grade);
    return 0;
}
