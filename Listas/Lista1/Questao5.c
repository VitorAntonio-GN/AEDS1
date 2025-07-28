#include <stdio.h>
//Tabuada de 1 a N com for: peça um número N e exiba a tabuada de 1 até N.

int main(void)
{
    //numero
    long long int num = 0;
    printf("\nDigite o numero: ");
    scanf("%lld", &num);

    //resultado
    long long int result = 0;

    printf("\n");

    for(int i = 1; i <= 9; i++)
    {
        result = num * i;

        printf("%lld  *  %d  =  %lld\n", num, i, result);
    }

    printf("\n");

    return 0;
}