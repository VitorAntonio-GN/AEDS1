/*
8. Dada uma matriz 8x8 com números inteiros, calcule a soma dos
elementos de cada linha e armazene em um vetor. Em seguida,
ordene o vetor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    //vetor e variaveis
    int vetorMatriz[8][8];
    int sumLinhaMatriz = 0;
    int vetorSomaMatriz[8] = {0};    
    int random = 0;
    int aux = 0;

    //input
    srand(time(NULL));
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            random = rand() % 30 + 1;
            vetorMatriz[i][j] = random;
        }
    }

    //for para soma
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            sumLinhaMatriz += vetorMatriz[i][j];

            //se for a ultima coluna <- menos otimizado, poderia sem embaixo, mas é otimo para leitura
            if(j == 7)
            {
                vetorSomaMatriz[i] = sumLinhaMatriz;
                sumLinhaMatriz = 0;
            }
        }
    }

    //ordenar vetor
    for(int i = 0; i < (8 - 1); i++)
    {
        for(int j = i + 1; j < 8; j++)
        {
            if(vetorSomaMatriz[j] > vetorSomaMatriz[i])
            {
                aux = vetorSomaMatriz[i];
                vetorSomaMatriz[i] = vetorSomaMatriz[j];
                vetorSomaMatriz[j] = aux;
            }
        }
    }

    //printar vetor
    printf("A soma das linhas e: ");
    for(int i = 0; i < 8; i++)
    {
        if(i == 7)
        {
            printf("%d\n", vetorSomaMatriz[i]);
        }
        else
        {
            printf("%d, ", vetorSomaMatriz[i]);
        }
    }

    return 0;
}