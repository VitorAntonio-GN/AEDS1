#include <stdio.h>

int main()
{
    int num = 0;
    double total = 0;
    int counter = 0;
    double avarage = 0;

    for(int i = 0; i < 10; i++)
    {
        printf("%d° Número: ", (i + 1));
        scanf("%d", &num);

        //n/ positivos = negativos e nulo (0)
        if(num <= 0)
        {
            i--;
        }
        else
        {
            total += num;
            counter++;
        }
    }

    avarage = total / counter;
    printf("\nMédia: %.2lf\n", avarage);
}