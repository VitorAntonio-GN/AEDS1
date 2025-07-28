/*
10.Leia uma matriz 7x7 e substitua cada elemento pela diferença entre
ele e a média de seus vizinhos (direita, esquerda, cima e baixo).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    //vetor e variaveis
    float vetorMatriz[7][7][2] = {0};
    float sumVizinhos = 0;
    int counterSumVizinhos = 0;
    float random = 0;
    int indexITeste = 0;
    int indexJTeste = 0;
    int isPossivelIndex = 1;
    float mediaSomaVizinhos = 0;

    //input
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            random = rand() % 1 + 1;

            vetorMatriz[i][j][0] = random;
        }
    }

    //verificação para cada elemento e media (para cada linha e coluna, como feito)
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            //verifica superior, inferior, direita e esquerda
            for(int k = 0; k < 4; k++)//<- for interno para essas 4 verificações
            {
                //com base no presente
                indexITeste = i;
                indexJTeste = j;
                isPossivelIndex = 1;

                //verificação se é possivel usar os laterais (cada 1, sao 4 vezes)
                if(k == 0)
                {
                    indexITeste--;
                }
                else if(k == 1)
                {
                    indexITeste++;
                }
                else if(k == 2)
                {
                    indexJTeste++;
                }
                else
                {
                    indexJTeste--;
                }

                if(indexITeste < 0 || indexJTeste < 0 || indexITeste > 6 || indexJTeste > 6)
                {
                    isPossivelIndex = 0;
                }

                //se é possivel, soma à soma e acrescenta ao constador
                if(isPossivelIndex == 1)
                {
                    sumVizinhos += vetorMatriz[i][j][0]; //<- soma dos vizinhos
                    counterSumVizinhos++; //<- qtd de vizinhos
                }
            }
            //a média da soma dos vizinhos vai para trás na matriz
            mediaSomaVizinhos = sumVizinhos / counterSumVizinhos; //<- media das laterais
            vetorMatriz[i][j][1] = mediaSomaVizinhos; // <- acrescenta atrás (i e j fixos, fora do loop dos 4 testes)

            //reseta a soma do vizinhos e o contador dos vizinhos <- 1 diferente para cada numero
            sumVizinhos = 0;
            counterSumVizinhos = 0;
        }
    }

    //printar a segunda matriz
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(j == 6 && i != 6)
            {
                printf(" %.2f \n", vetorMatriz[i][j][1]);
                printf("___|___|___|___|___|___|___\n");
            }
            else if(j == 6)
            {
                printf(" %.2f \n", vetorMatriz[i][j][1]);                
            }
            else
            {
                printf(" %.2f |", vetorMatriz[i][j][1]);
            }
        }
    }

    return 0;
}