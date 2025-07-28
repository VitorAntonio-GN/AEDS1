#include <stdio.h>

int main(void)
{
    int numeroFatoracao = 0;
    int ultimaDivisao = 0;
    int sumDivisao = 0;
    int isPrimeiraDivisao = 1;
    
    printf("Digite um numero: ");
    scanf("%d", &numeroFatoracao);

    printf("Saida: ");
    for(int i = 2; i <= 9; i++)
    {
        if(numeroFatoracao % i == 0) //se for divisivel
        {
            if(ultimaDivisao == i)
            {
                numeroFatoracao /= i;
                sumDivisao++;
                i--; //<- refaz a divisão
            }
            else if(ultimaDivisao == 0)
            {
                numeroFatoracao /= i;
                ultimaDivisao = i;
                sumDivisao = 1;
                i--;
            }
            else if(ultimaDivisao != i && sumDivisao != 1)
            {
                printf("%d^%d*", ultimaDivisao, sumDivisao);
                sumDivisao = 1;
                ultimaDivisao = i;
                i--;
            }
            else
            {
                printf("%d*", ultimaDivisao);
                ultimaDivisao = i;
                i--;
            }
        }
    }

    if(sumDivisao != 1)
    {
        printf("%d^%d\n", ultimaDivisao, sumDivisao);
    }
    else
    {
        printf("%d\n", ultimaDivisao);
    }

    return 0;
}