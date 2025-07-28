/*
18.Desenvolva uma função que receba uma matriz NxN e retorne
verdadeiro se todas as diagonais secundárias forem formadas por
múltiplos de 5.
*/

#include <stdio.h>

int diagonalsecundaria(int linhas, int colunas, int matriz[linhas][colunas]) //<- nao entendi muito bem
{
    int controle = 0;
    int EhFormada = 1;

    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            if(j == ((colunas - 1) - controle)) //<- esqueci de ser o index
            {
                if(matriz[i][j] % 5 != 0)
                {
                    EhFormada = 0;
                }

                controle++;
            }
        }
    }

    return EhFormada;
}

int main(void)
{
    //inputs
    int linhasMatriz = 0;
    int colunasMatriz = 0;
    int isDiagonalSecundaria = 0;

    printf("Linhas: ");
    scanf("%d", &linhasMatriz);
    printf("Colunas: ");
    scanf("%d", &colunasMatriz);

    //vetores e variaveis
    int matrizNumeros[linhasMatriz][colunasMatriz];

    isDiagonalSecundaria = diagonalsecundaria(linhasMatriz, colunasMatriz, matrizNumeros);

    if(isDiagonalSecundaria == 1)
    {
        printf("Sua diagonal secundaria e composta por multiplos de 5\n");
    }

    return 0;
}