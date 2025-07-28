#include <stdio.h>

//13.Soma apenas dos ímpares de 1 até N com for: Calcule a soma de todos os números ímpares de 1 até N.
int main(void)
{
    //numero final
    unsigned long long int n = 0;
    printf("Digite n: ");
    scanf("%llu", &n);

    //soma
    unsigned long long sum = 0;

    //loop for
    //o primeiro impar comeca em 1 e vai de 2 em 2
    //de i ate n
    unsigned long long int i = 1;
    for(i; i <= n; i += 2)
    {
        sum += i;
    }

    printf("\nA soma dos numeros impares de 1 ate %llu e %llu\n", n, sum);

    return 0;
}