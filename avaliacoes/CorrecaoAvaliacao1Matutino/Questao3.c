/*
Questão 3 – Números Especiais (10 pontos)
Escreva um programa em linguagem C que:
• Peça ao usuário para digitar dois números inteiros positivos A e B,
garantindo que A < B;
• Percorra todos os números no intervalo fechado de A a B e, para cada
número:
1. Verifique se ele é divisível por 3 ou 5, mas não por ambos ao
mesmo tempo;
2. Calcule a soma dos dígitos do número;(lembre-se do exercício
das notas de dinheiro, pode ajudar)
3. Se a soma dos dígitos for par, o número deve ser exibido na tela.
*/

#include <stdio.h>

int main(void)
{
    unsigned int a = 0;
    unsigned int b = 0;
    unsigned int aux = 0;

    do{
        printf("a: ");
        scanf("%u", &a);
        printf("b: ");
        scanf("%u", &b);
    } while(a >= b);

    int div = 0;
    unsigned int copya = 0;
    int digit = 0;
    int sum_digit = 0;
    for(a; a <= b; a++)
    {
        if(a % 3 == 0)
        {
            div++;
        }
        if(a % 5 == 0)
        {
            div++;
        }

        copya = a;
        while(copya >= 1)
        {
            digit = copya % 10;
            sum_digit += digit;
            copya /= 10;
        }

        if(div == 1 && (sum_digit % 2) == 0)
        {
            printf("%u\n", a);
        }

        sum_digit = 0;
        div = 0;
    }
   
    return 0;
}