/*
2. Matriz: Jogo de Caça ao Tesouro
Implemente um programa em C que simula um jogo de "caça ao tesouro"
em uma matriz 5x5. O programa deve:

• Criar uma matriz 5x5 e inicializá-la com zeros.
• Sorteie aleatoriamente 3 posições diferentes da matriz e coloque
nelas o número 1, indicando que há um “tesouro” escondido.
• O jogador terá 10 tentativas para encontrar os 3 tesouros. A cada
tentativa, ele deve digitar uma linha e uma coluna:
o Se encontrar um tesouro, exibir "Tesouro encontrado!" e marcar a
posição como 2.
o Se não encontrar, exibir "Nada aqui!" e marcar como -1.
• Após 10 tentativas ou após os 3 tesouros serem encontrados:
o Mostrar a matriz final, onde:
▪ 2 indica tesouro encontrado.
▪ -1 indica tentativa sem sucesso.
▪ 1 indica tesouro não encontrado.
▪ 0 indica local não visitado.

• Use rand() e srand(time(NULL)) para sortear as posições.
• Garanta que os 3 tesouros sejam colocados em posições diferentes.
• Não deixe o jogador jogar na mesma posição duas vezes.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    //declarar a matriz nula
    int malha[5][5] = {(0,0,0,0,0),(0,0,0,0,0),(0,0,0,0,0),(0,0,0,0,0),(0,0,0,0,0)};

    //aleatorizar 3 tesouros (-1 pois nao pega o rand e nao tem como ser isequal)
    srand(time(NULL));
    int i = 0;
    int j = 0;
    int linha[3] = {-1,-1,-1};
    int coluna[3] = {-1,-1,-1};
    int isequal = 0;

    //while para aleatorizar
    int k = 0;
    while(k != 3)
    {
        i = rand() % 5;
        j = rand() % 5;

        //para cada index dentro da lista
        //no 1° pula
        for(int l = 0; l < k; l++)
        {
            if(linha[l] == i && coluna[l] == j)
            {
                isequal = 1;
            }
        }

        //vericacao se e o primeiro ou nao e igual ao que aleatorizou
        if(k == 0 || isequal == 0)
        {
            linha[k] = i;
            coluna[k] = j;

            malha[i][j] = 1;

            k++;
        }
        else
        {
            isequal = 0;
        }
    }

    //jogo (-1 pois nao pega na range)
    int malhajogo[5][5] = {(0,0,0,0,0),(0,0,0,0,0),(0,0,0,0,0),(0,0,0,0,0),(0,0,0,0,0)};
    int countj = 0;
    int counttesouro = 0;
    int jogadasi[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int jogadasj[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    do
    {
        //malha do jogo
        printf("\n");
        //para cada linha
        for(int m = 0; m < 5; m++)
        {
            //para cada coluna
            for(int n = 0; n < 5; n++)
            {
                if(n != 4 && malhajogo[m][n] < 0)
                {
                    printf(" %d |", malhajogo[m][n]);
                }
                else if(n != 4)
                {
                    printf("  %d |", malhajogo[m][n]);
                }
                else if(n == 4 && malhajogo[m][n] < 0)
                {
                    printf(" %d \n", malhajogo[m][n]);
                }
                else
                {
                    printf("  %d \n", malhajogo[m][n]);
                }
            }

            if(m == 4)
            {
                printf("    |    |    |    |    \n");
            }
            else
            {
                printf("____|____|____|____|____\n");
            }
        }

        //jogada
        do
        {
            printf("\n%d° Tentativa: \n", (countj + 1));
            printf("Escolha a linha: ");
            scanf("%d", &i);
            printf("Escolha a coluna: ");
            scanf("%d", &j);
        } while((i > 5 || i < 1) || (j > 5 || j < 1));

        //ajustar o index das linhas (para poder mexer com as matrizes)
        i--;
        j--;

        //se for o primeiro ou se ja foi jogado
        if(countj == 0)
        {
            jogadasi[countj] = i;
            jogadasj[countj] = j;
        }
        else
        {
            //perde 1 de range pois o countj está adiantado para o index desta jogada
            for(int o = 0; o < countj; o++)
            {
                if(jogadasi[o] == i && jogadasj[o] == j)
                {
                    isequal = 1;
                }
            }
        }

        if(isequal == 0)
        {
            jogadasi[countj] = i;
            jogadasj[countj] = j;

            if(malha[i][j] == 1)
            {
                malhajogo[i][j] = 2;
                malha[i][j] = 2;
                counttesouro++;

                printf("\nTesouro encontrado!\n");
            }
            else
            {
                malhajogo[i][j] = -1;
                malha[i][j] = -1;

                printf("\nNada aqui!\n");
            }

            countj++;
        }
        else
        {
            isequal = 0;

            printf("\nLinha e coluna ja jogada\n");
        }

    } while(countj < 10 && counttesouro != 3);

    //malha final
    printf("\nResultado final:\n");
    //para cada linha
    for(int m = 0; m < 5; m++)
    {
        //para cada coluna
        for(int n = 0; n < 5; n++)
        {
            if(n != 4 && malha[m][n] < 0)
            {
                printf(" %d |", malha[m][n]);
            }
            else if(n != 4)
            {
                printf("  %d |", malha[m][n]);
            }
            else if(n == 4 && malha[m][n] < 0)
            {
                printf(" %d \n", malha[m][n]);
            }
            else
            {
                printf("  %d \n", malha[m][n]);
            }
        }

        if(m == 4)
        {
            printf("    |    |    |    |    \n");
        }
        else
        {
            printf("____|____|____|____|____\n");
        }
    }
    printf("\nOnde:\n2 -> Tesouro encontrado\n-1 -> Tentativa sem sucesso\n1 -> Tesouro nao encontrado\n0 -> Local nao visitado\n\n");
    return 0;
}