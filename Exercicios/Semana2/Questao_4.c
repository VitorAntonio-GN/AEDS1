#include <stdio.h>

int main()
{
    double fx = 0;
    double gx = 0;
    double hx = 0;

    double x = 0;
    printf("Digite o valor de x: ");
    scanf("%lf", &x);

    hx = (x * x) + (3 * x) - 20;

    if(hx > 5)
    {
        gx = hx;
    }
    else
    {
        gx = 5;
    }

    if(gx <= 10)
    {
        fx = 10;
    }
    else
    {
        fx = x + (2 * x * x);
    }

    printf("f(x) = %.3lf", fx);
}