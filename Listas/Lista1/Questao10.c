#include <stdio.h>

//10.Verificar se número é perfeito com for: um número é perfeito se a soma de seus divisores (exceto ele) é igual a ele. Verifique se um número é perfeito.
int main(void)
{
    //numero
    unsigned long long int num = 0;
    printf("Digite o numero: ");
    scanf("%llu", &num);

    //soma divisores
    int sumdiv = 0;

    //para cada divisor
    //comeca em 1
    //exceto n
    for(int i = 1; i < num; i++)
    {
        if(num % i == 0)
        {
            sumdiv += i;
        }
    }

    if(sumdiv == num)
    {
        printf("\nO numero %llu e um numero perfeito\n", num);
    }
    else
    {
        printf("\nO numero %llu nao e um numero perfeito\n", num);
    }
    
    return 0;
}