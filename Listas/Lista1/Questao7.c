#include <stdio.h>

//Média de números até digitar número negativo com do while: peça números inteiros positivos e calcule a média. O programa para quando for digitado um número negativo.
int main(void)
{
    //numero
    long long int num = 0;
    //soma numero
    double sum = 0;

    //loop e contador da quantidade de números
    int i = 0;
    do{
        printf("\nDigite o %do numero: ", (i + 1));
        scanf("%lld", &num);

        if(num < 0)
        {
            break;
        }

        sum += num;
        i++;
    } while(num >= 0);

    printf("\n\nA media e: %.2lf\n", (sum / i));

    return 0;
}