#include <stdio.h>

int main(void)
{
    float a = 0.0;
    printf("a: ");
    scanf("%f", &a);

    float b = 0.0;
    printf("b: ");
    scanf("%f", &b);

    //pega o floor, se divisão for 3, floor é 0, já se for 2.5, floor é 0.5
    float mod = a / b;
    while (mod > 1 || mod == 1)
    {
        mod--;
    }
    //multiplica pelo divisor para retornar o original
    mod *= b;
    
    float result = ((b * b * b) + a * b) - 2 * b + mod;

    printf("Result: %.2f", result);
}