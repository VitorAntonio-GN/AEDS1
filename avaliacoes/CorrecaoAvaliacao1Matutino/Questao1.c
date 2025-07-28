/*
Questão 1 – Operações Aritméticas (5 pontos)
Escreva um programa em linguagem C que:
• Leia dois números reais fornecidos pelo usuário;
• Calcule a soma dos dois números, imprima o valor da soma;
• Com base na soma, calcule a subtração do segundo número em relação
ao resultado da soma, imprima o valor da subtração;
• Com base no resultado da subtração, calcule a multiplicação desse valor
pelo primeiro número, imprima o valor da multiplicação;
• Por fim, divida o resultado da multiplicação pelo segundo número e mostre
o resultado da divisão, imprima o valor da divisão.
*/

#include <stdio.h>

int main(void)
{
    float a = 0;
    float b = 0;

    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);

    float soma = a + b;
    float subtracao = soma - b;
    float multiplicacao = subtracao * a;
    float divisao = multiplicacao / b;

    printf("Soma: %f\nSubtracao: %f\nMultiplicacao: %f\nDivisao: %f\n\n", soma, subtracao, multiplicacao, divisao);
    return 0;
}