#include <stdio.h>

//22.Calculadora de MDC com laço while (método de Euclides): leia dois números e calcule o Máximo Divisor Comum usando subtrações ou o algoritmo de Euclides.
int main(void)
{
    //variaveis
    //n2 maior, n1 menor
    unsigned long long int n1 = 0;
    unsigned long long int n2 = 0;
    unsigned long long int aux = 0;

    //input
    printf("Digite o valor 1: ");
    scanf("%llu", &n1);
    printf("Digite o valor 2: ");
    scanf("%llu", &n2);

    //se n1 > n2
    if(n1 > n2)
    {
        aux = n2;
        n2 = n1;
        n1 = aux;
    }

    //variaveis para o loop
    unsigned long long int dividendo = n2;
    unsigned long long int divisor = n1;
    unsigned long long int resto = 0;

    //loop
    //quando resto e zero, divisor e o mdc
    while(resto != 0)
    {
        resto = dividendo % divisor;
        dividendo = divisor;
        resto = divisor;
    }

    printf("\nO MDC entre %llu e %llu e: %llu\n\n", n1, n2, divisor);

    return 0;
}