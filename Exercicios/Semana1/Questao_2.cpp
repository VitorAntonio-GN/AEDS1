#include <stdio.h>

int main(void)
{
    float celsius = 0.0;
    printf("Celsius: ");
    scanf("%f", &celsius);

    float fahrenheit = (celsius * 9/5) + 32;
    printf("Fahrenheit: %f\n", fahrenheit); 
}