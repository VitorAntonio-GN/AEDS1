#include <stdio.h>
//Verificar se um número é primo com for: peça um número positivo e informe se ele é primo.

int main(void)
{
    // primo é natural divisivel por um e por ele mesmo
    unsigned long long int num = 0;
    printf("\nDigite o numero: ");
    scanf("%llu", &num);

    //contador de divisores
    int counter = 0;
    //divisor comeca no 1
    int i = 1;

    //para cada divisor(i)
    for(i; i <= num; i++)
    {
        if(num % i == 0)
        {
            counter++;
        }
    }

    //verificacao para ver se e primo (counter == 2)
    if(counter == 2)
    {
        printf("\nO numero %llu e primo\n\n", num);
    }
    else
    {
        printf("\nO numero %llu nao e primo\n\n", num);
    }

    return 0;
}