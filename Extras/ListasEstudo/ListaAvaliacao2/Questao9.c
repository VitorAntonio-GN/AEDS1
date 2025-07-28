/*
9. Crie uma matriz 9x9 que simule a movimentação de um cavalo no
xadrez. Dado um ponto inicial, marque todas as posições que ele
pode atingir.
*/

//linha e coluna comparativa, verificar se é >0 em i e j -> mostrar como possivel movimentação

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    //vetor e variaveis
    int vetorMatriz[9][9] = {0};
    int aux = 0;
    int random = 0;
    int iCavalo = 0;
    int jCavalo = 0;
    int iCavaloTeste = 0;
    int jCavaloTeste = 0;
    int isPossivelJogada = 1;
    int isJogando = 1;
    
    //input <- linha, coluna do cavalo
    printf("Digite a linha do cavalo: ");
    scanf("%d", &iCavalo);
    printf("Digite a coluna do cavalo: ");
    scanf("%d", &jCavalo);

    iCavalo--;
    jCavalo--;
    vetorMatriz[iCavalo][jCavalo] = 1;

    //para 8 possiveis jogadas <- loop infinito pedindo linha e coluna possiveis <- cria copia, subtrai as linha e colunas das joagadas e compara se possiveis (i e j >= 0)
    while(isJogando == 1)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(j == 8 && i != 8)
                {
                    printf(" %d \n", vetorMatriz[i][j]);
                    printf("___|___|___|___|___|___|___|___|___\n");
                }
                else if( j == 8)
                {
                    printf(" %d \n", vetorMatriz[i][j]);
                }
                else
                {
                    printf(" %d |", vetorMatriz[i][j]);
                }
            }
        }


        //8 possiveis joagadas
        printf("\nPossiveis jogadas: ");
        for(int i = 0; i < 8; i++)
        {
            iCavaloTeste = iCavalo;
            jCavaloTeste = jCavalo;
            isPossivelJogada = 1;

            //superior esquerda, superior direita, inferior esquerda, inferior direita, esquerda superior, esquerda inferior, direita superior, direita inferior
            if(i <= 1)
            {
                iCavaloTeste -= 3;

                if(i == 0)
                {
                    jCavaloTeste -= 1;
                }
                else
                {
                    jCavaloTeste += 1;
                }
            }
            else if(i <= 3)
            {
                iCavaloTeste += 3;

                if(i == 2)
                {
                    jCavaloTeste -= 1;
                }
                else
                {
                    jCavaloTeste += 1;
                }
            }
            else if(i <= 5)
            {
                jCavaloTeste -= 3;

                if(i == 4)
                {
                    iCavaloTeste -= 1;
                }
                else
                {
                    iCavaloTeste += 1;
                }
            }
            else
            {
                jCavaloTeste += 3;

                if(i == 6)
                {
                    iCavaloTeste -= 1;
                }
                else
                {
                    iCavaloTeste += 1;
                }
            }

            if((iCavaloTeste < 0 || iCavaloTeste > 8) || (jCavaloTeste < 0 || jCavaloTeste > 8)) //<-if ta bugado (erro no codigo)
            {
                isPossivelJogada = 0;
            }

            if(isPossivelJogada	== 1)
            {
                printf("(%d, %d) ", (iCavaloTeste + 1), (jCavaloTeste + 1));
            }
        }

        printf("\nQuer permanecer movimentando? 1 - sim, 0 - nao: ");
        scanf("%d", &isJogando);

        if(isJogando == 0)
        {
            break;
        }

        //movimentação obrigatoria, caso jogar
        vetorMatriz[iCavalo][jCavalo] = 0;

        printf("Digite a linha de movimentacao: ");
        scanf("%d", &iCavalo);
        iCavalo--;

        printf("Digite a coluna de movimentacao: ");
        scanf("%d", &jCavalo);
        jCavalo--;

        vetorMatriz[iCavalo][jCavalo] = 1;
    }

    return 0;
}