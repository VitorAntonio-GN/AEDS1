/*
5. Leia dois vetores de 15 posições e gere um terceiro vetor com os
elementos que estão presentes em ambos, sem duplicatas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    //variaveis e vetores
    float vetorNumeros1[15][2] = {0};
    float vetorNumeros2[15][2] = {0};
    float vetorAmbos[15] = {0};
    int counterIndexAmbos = 0;
    int random = 0;

    //input vetores
    srand(time(NULL));

    for(int i = 0; i < 15; i++)
    {
        random = rand() % 10 + 1;

        vetorNumeros1[i][0] = random;
        vetorNumeros1[i][1] = 1;
    }

    for(int i = 0; i < 15; i++)
    {
        random = rand() % 10 + 1;

        vetorNumeros2[i][0] = random;
        vetorNumeros2[i][1] = 1;
    }

    //numeros distintos em ambos os vetores
    for(int i = 0; i < (15 - 1); i++)
    {
        for(int j = (i + 1); j < 15; j++)
        {
            if(vetorNumeros1[i][0] == vetorNumeros1[j][0] && vetorNumeros1[i][1] != 0 && vetorNumeros1[j][1] != 0)
            {
                vetorNumeros1[j][1] = 0;
                vetorNumeros1[i][1] += 1;
            }
        }
    }

    for(int i = 0; i < (15 - 1); i++)
    {
        for(int j = (i + 1); j < 15; j++)
        {
            if(vetorNumeros2[i][0] == vetorNumeros2[j][0] && vetorNumeros2[i][1] != 0 && vetorNumeros2[j][1] != 0)
            {
                vetorNumeros2[j][1] = 0;
                vetorNumeros2[i][1] += 1;
            }
        }
    }

    //verificacao se há igual
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 15; j++)
        {
            if(vetorNumeros1[i][0] == vetorNumeros2[j][0] && vetorNumeros1[i][1] != 0 && vetorNumeros2[j][1] != 0)
            {
                vetorAmbos[counterIndexAmbos] = vetorNumeros1[i][0];
                counterIndexAmbos++;
            }
        }
    }

    //printar iguais
    printf("Vetor de repetidos: ");
    for(int i = 0; i < counterIndexAmbos; i++) //<- sem -1 pois o index é sempre o do proximo
    {
        if(i == (counterIndexAmbos - 1))
        {
            printf("%.2f\n", vetorAmbos[i]);
        }
        else
        {
            printf("%.2f, ", vetorAmbos[i]);
        }
    }

    return 0;
}