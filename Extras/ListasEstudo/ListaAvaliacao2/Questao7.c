/*
7. Verifique se uma matriz 5x5 é simétrica, se sua diagonal principal
está ordenada e se os elementos abaixo dela são todos negativos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    //vetores e variaveis
    int vetorMatriz[5][5] = {0};
    int random = 0;
    int isSimetrica = 1;
    int counterSimetrica = 1;
    int isOredenadaCrescente = 1;
    int isOrdenadaDescrescente = 1;
    int vetorOrdenada[5] = {0};
    int counterIndexOrdenada = 0;
    int isNegativaAbaixo = 1;

    //input
    srand(time(NULL));
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            random = rand() % 30 + 1;

            vetorMatriz[i][j] = random;
        }
    }

    //for até a metade (simetrica) <- mesma coisa do exercicio anterior, levemente diferente
    //+ if i==j (verificar se a diagonal principal está ordenada)
    //+ if (j < i > 0)
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(vetorMatriz[i][j] != vetorMatriz[4 - i][4 - j] && counterSimetrica <= 12) //o index máximo dessa matriz é 4, 4
            {
                isSimetrica = 0;
                counterSimetrica++;
            }

            if(i == j)
            {
                vetorOrdenada[counterIndexOrdenada] = vetorMatriz[i][j];
                counterIndexOrdenada++;

                for(int k = 0; k < (counterIndexOrdenada - 1); k++)
                {
                    if(vetorOrdenada[k] > vetorOrdenada[k + 1] && isOredenadaCrescente == 1) //1° > 2° e crescente estiver true (é menor, é decrescente)
                    {
                        isOredenadaCrescente = 0;
                    }
                    else if(vetorOrdenada[k] < vetorOrdenada[k + 1] && isOrdenadaDescrescente == 1) // 1° < 2° e decrescente true (é maior, é crescente)
                    {
                        isOrdenadaDescrescente = 0;
                    }
                }
            } // ^^ redundante era so colocar para i e j >= 1 e verificar se > ou < que anterior

            if(j < i && vetorMatriz[i][j] >= 0)
            {
                isNegativaAbaixo = 0;
            }
        }
    }

    //printar
    if(isNegativaAbaixo == 0)
    {
        printf("Nao e negativa abaixo\n");
    }
    else
    {
        printf("E negativa abaixo\n");
    }

    if(isOredenadaCrescente == 1 && isOrdenadaDescrescente == 1)
    {
        printf("Sua diagonal princial e composta por numeros iguais\n");
    }
    else if(isOredenadaCrescente == 1)
    {
        printf("E ordenada crescente\n");
    }
    else if(isOrdenadaDescrescente == 1)
    {
        printf("E ordenada decrescente\n");
    }
    else
    {
        printf("Nao e ordenada\n");
    }

    if(isSimetrica == 0)
    {
        printf("Nao e simetrica\n");
    }
    else
    {
        printf("E simetrica\n");
    }

    return 0;
}