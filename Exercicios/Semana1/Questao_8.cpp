#include <stdio.h>

int main(void)
{
    int worked_days = 0;
    printf("Worked days: ");
    scanf("%i", &worked_days);

    int brute_worked = 30 * worked_days;

    float liquid_worked = brute_worked * 0.92;

    printf("Liquid salary: $%.2f;\n'Brute' salary: $%.2f;\nIR: $%.2f.", liquid_worked, (float)brute_worked, (brute_worked * 0.08));
}