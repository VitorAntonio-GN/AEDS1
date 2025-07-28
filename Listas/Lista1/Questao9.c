#include <stdio.h>

//Quantidade de múltiplos de 4 entre 100 e 200 com for: conte quantos números múltiplos de 4 existem entre 100 e 200.
int main(void)
{
    //contador da qtd de numeros divisores
    int counternumdiv = 0;

    //cada numero de 100 a 200
    for(int i = 100; i <= 200; i++)
    {
        if(i % 4 == 0)
        {
            printf("\n%d e divisor de 4", i);
            counternumdiv++;
        }
    }

    printf("\n\nExistem %d divisores de 4 entre 100 a 200\n", counternumdiv);

    return 0;
}