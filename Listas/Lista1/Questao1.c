#include <stdio.h>
//Soma dos divisores de um número com for: leia um número inteiro e calcule a soma de todos os seus divisores (excluindo ele mesmo)

int main(void)
{
    long long int num = 0;
    printf("\nDigite o numero: ");
    scanf("%lld", &num);

    //o primeiro divisor é 1
    int i = 1;
    //soma
    long long int soma = 0;
    for(i; i <= num; i++)
    {
        if(num % i == 0)
        {
            soma += i;
        }
    }

    printf("\nA soma de seus divisores e: %lld\n\n", soma);

    return 0;
}