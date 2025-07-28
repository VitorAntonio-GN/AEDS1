#include <stdio.h>

//17.Simulador de saque com while: peça um valor e calcule o menor número de notas (100, 50, 20, 10, 5, 2, 1) para compor esse valor.
int main(void)
{
    unsigned long long int value = 0;
    printf("Qual o valor para troco? ");
    scanf("%llu", &value);

    //printa se houver resultado na divisao pela nota e retorna o valor como
    // -... resto, assim, se a divisao resultar em 0, o resto sera o propio valor
    while(1)
    {
        printf("\nNotas de 100: %llu", (value / 100));
        value = value % 100;

        printf("\nNotas de 50: %llu", (value / 50));
        value = value % 50;

        printf("\nNotas de 20: %llu", (value / 20));
        value = value % 20;

        printf("\nNotas de 10: %llu", (value / 10));
        value = value % 10;

        printf("\nNotas de 5: %llu", (value / 5));
        value = value % 5;

        printf("\nNotas de 2: %llu", (value / 2));
        value = value % 2;

        printf("\nNotas de 1: %llu\n\n", (value / 1));

        //sair do loop
        break;
    }

    return 0;
}