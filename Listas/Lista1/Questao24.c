#include <stdio.h>
#include <math.h>

//24.Série com aproximação de PI com for: calcule o valor aproximado de PI com a fórmula de Leibniz:
int main(void)
{
    //pega valor de n
    unsigned long long int n = 0;
    printf("Digite quantas vezes ira rodar, mais vezes, mais proximo: ");
    scanf("%llu", &n);

    //variavel para a conta
    double pi = 0;

    //loop para a formula
    for(int i = 0; i < n; i++)
    {
        pi += (pow(-1, i)) / (1 + (2 * i));
    }

    //ainda falta * 4
    pi *= 4;

    printf("\nO valor de pi e: %lf\n\n", pi);

    return 0;
}