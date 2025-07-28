#include <stdio.h>

int main(void)
{
    float a = 0.0;
    printf("\na: ");
    scanf("%f", &a);

    float b = 0.0;
    printf("b: ");
    scanf("%f", &b);

    //switch
    float a_to_b = 0.0;
    float b_to_a = 0.0;

    if(a == 0.0)
    {
        a_to_b = b;
        b_to_a = 0.0;
    }
    else if(b == 0.0)
    {
        b_to_a = a;
        a_to_b = 0.0;
    }
    else
    {
        a_to_b =  a * (b / a);
        b_to_a = b * (a / b);
    }

    printf("\nSWAP:\na is: %.5f\nb is: %.5f\n\n", a_to_b, b_to_a);
}