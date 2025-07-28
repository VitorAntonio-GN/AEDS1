/*
6. Leia uma matriz 6x6 de inteiros e troque a primeira coluna com a
última, a segunda com a penúltima e assim por diante.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    //vetor e variaveis
    int vetorMatriz[6][6] = {0};
    int random = 0;
    int aux = 0;

    //inputs
    srand(time(NULL));
    for(int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            random = rand() % 100 + 1;

            vetorMatriz[i][j] = random;
        }
    }

    //printar matriz
    printf("Matriz anterior:\n");
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(j == 5)
            {
                printf(" %d \n", vetorMatriz[i][j]);
            }
            else
            {
                printf(" %d |", vetorMatriz[i][j]);
            }
        }
    }

    //for até a metade trocando <- como a metade de uma 6 por 6 é o final da linha tres, então linhas / 2
    for(int i = 0; i < (6 / 2); i++)
    {
        for(int j = 0; j < 6; j++)
        {
            aux = vetorMatriz[i][j];
            vetorMatriz[i][j] = vetorMatriz[5 - i][5 - j]; //vai trocando com os ultimos na medida em que vai aumentando
            vetorMatriz[5 - i][5 - j] = aux;
        }
    }

    //printar matriz
    printf("\nMatriz trocada:\n");
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(j == 5)
            {
                printf(" %d \n", vetorMatriz[i][j]);
            }
            else
            {
                printf(" %d |", vetorMatriz[i][j]);
            }
        }
    }

    return 0;
}