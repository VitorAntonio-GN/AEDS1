#include <stdio.h>

int main(void)
{
    float peso = 0.0;
    float altura = 0.0;

    printf("Altura: ");
    scanf("%f", &altura);

    printf("Peso: ");
    scanf("%f", &peso);

    float imc = peso / (altura * altura);
    printf("Imc: %.5f\n", imc);
}