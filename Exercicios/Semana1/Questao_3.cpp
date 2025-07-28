#include <stdio.h>

int main(void)
{
    float pi = 3.14159;

    float raius = 0.0;
    printf("Raius: ");
    scanf("%f", &raius);

    float perimeter = 2 * pi * raius;

    float area = pi * (raius * raius);

    printf("Area: %.2f\nPerimeter: %.2f\n", area, perimeter);
}