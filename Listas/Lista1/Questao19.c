#include <stdio.h>

//19.Números primos de Fibonacci com for e if: gere os 20 primeiros termos da sequência de Fibonacci e exiba apenas os que são números primos.
int main(void)
{
    int countdiv = 0;
    unsigned long long int v1 = 1;
    unsigned long long int v2 = 0;
    unsigned long long int aux = 0;

    printf("\n");

    //para cada vez
    for(int i = 0; i < 20; i++)
    {
        //para cada divisor
        for(int j = 1; j <= v1; j++)
        {
            if(v1 % j == 0)
            {
                countdiv++;
            }
        }

        //se e primo
        if(countdiv == 2)
        {
            printf("%llu -> ", v1);
        }

        //fibbonaci
        aux = v1;
        v1 = v1 + v2;
        v2 = aux;

        countdiv = 0;
    }

    printf("fim\n\n");

    return 0;
}