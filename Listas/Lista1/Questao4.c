#include <stdio.h>
//Múltiplos de 3 e 5 entre dois valores com for: leia dois valores inteiros A e B e exiba todos os números entre A e B que sejam múltiplos de 3 ou 5.

int main(void)
{
    //valor de a
    long long int a = 0;
    printf("\nDigite o valor de a: ");
    scanf("%lld", &a);
    
    //valor de b
    long long int b = 0;
    printf("\nDigite o valor de b: ");
    scanf("%lld", &b);

    //troca os intervalos
    if(a > b)
    {
        long long int aux = a;
        a = b;
        b = aux;
    }

    //contador de divisoes resto 0
    int counterdiv = 0;
    //contador de divisoes
    int counternumdiv = 0;
    //copia de a
    long long int aux_a = a;

    //para cada menor numero de a até b (<=)
    for(aux_a; aux_a <= b; aux_a++)
    {
        //para cada divisor (vai de 3 a 5)
        for(int j = 3; j <= 5; j += 2)
        {
            if(aux_a % j == 0)
            {
                counterdiv++;
            }
        }

        if(counterdiv >= 1)
        {
            counternumdiv++;
            printf("\nO numero %d e disivel por 3 ou 5", aux_a);
        }

        counterdiv = 0;
    }

    printf("\n\nExistem %d numeros divisiveis por 3 ou 5 entre %lld e %lld", counternumdiv, a, b);

    return 0;
}