/*
Questão 2 – Classificação por Índice de Massa Corporal (IMC) (5 pontos)
Escreva um programa em linguagem C que:
• Leia o peso (em kg) e a altura (em metros) de uma pessoa;
• Calcule o Índice de Massa Corporal (IMC) usando a fórmula:

• Classifique o resultado do IMC de acordo com a tabela abaixo:
*/

#include <stdio.h>

int main(void)
{
    float peso = 0;
    float altura = 0;

    printf("Peso: ");
    scanf("%f", &peso);
    printf("Altura: ");
    scanf("%f", &altura);

    float imc = peso / (altura * altura);

    if(imc < 17)
    {
        printf("Muito abaixo do peso\n\n");
    }
    else if(imc <= 18.49)
    {
        printf("Abaixo do peso\n\n");
    }
    else if(imc <= 24.99)
    {
        printf("Peso normal\n\n");
    }
    else if(imc <= 29.99)
    {
        printf("Acima do peso\n\n");
    }
    else if(imc <= 34.99)
    {
        printf("Obesidade I\n\n");
    }
    else
    {
        printf("Obesidade II ou maior\n\n");
    }

    printf("IMC calculado: %.2f\n", imc);

    return 0;
}
