#include <stdio.h>

int main(void)
{ 
    float brute_salary = 0.0;
    printf("'Brute' salary: ");
    scanf("%f", &brute_salary);

    float bonus = brute_salary * 0.05;
    float impost = brute_salary * 0.07;

    float liquid_salary = brute_salary - impost + bonus;

    printf("The liquid salary is: %.2f;\nThe bonus is: %.2f;\nThe impost is: %.2f.", liquid_salary, bonus, impost);
}