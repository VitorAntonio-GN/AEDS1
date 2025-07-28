#include <stdio.h>

int main(void)
{
    float fahrenheit = 0.0;
    printf("Fahrenheit: ");
    scanf("%f", &fahrenheit);

    float celsius = 5.0 * (fahrenheit - 32.0) / 9.0;

    printf("Celsius: %.5f\n", celsius);
}