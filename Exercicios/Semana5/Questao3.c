/*
3. Cálculo de potência (sem usar pow)
Crie uma função chamada potencia que receba dois inteiros base e
expoente, e retorne o resultado da base elevada ao expoente.
Não utilize a função pow() da biblioteca math.h.
Em seguida, leia os dois valores no main() e exiba o resultado chamando
a função.
*/

#include <stdio.h>

int potencia_recursiva(int base, int expoente)
{
    if(expoente == 0)
    {
        return 1;
    }
   
    //retorna base * base * base * ... * 1 <- basicamente para quando o expoente chega em 0 e retorna a multiplicação das bases (estranho de se pensar)
    return base * potencia_recursiva(base, (expoente - 1));
}

int potencia(int base, int expoente)
{
    int basePotencia = 1;

    while(expoente != 0)
    {
        basePotencia *= base;
        expoente--;
    }

    return basePotencia;
}

int main(void)
{
    //input
    int base = 0;
    int expoente = 0;

    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    if(expoente < 0)
    {
        printf("Escolha um expoente >= 0\n");
        return 1;
    }

    //função
    int basePotencia = potencia(base, expoente);

    //printar
    printf("A potencia de %d elevado a %d e: %d\n", base, expoente, basePotencia);

    return 0;
}