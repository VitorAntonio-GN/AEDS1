/*
2. Matriz usando ASCII: (10 pontos)
Receba uma matriz 6x6 de caracteres (letras do alfabeto, maiúsculas ou
minúsculas).
1. Converta todos os caracteres para valores ASCII e armazene em uma
segunda matriz.
2. Calcule a média geral dos valores.
3. Crie uma nova matriz seguindo os critérios:
o Células da diagonal principal recebem os valores acima da média,
em ordem decrescente.
o Células da diagonal secundária recebem os valores iguais à média,
se existirem; caso não, use zeros.
o O restante das posições deve ser preenchido com os valores
abaixo da média, em ordem crescente.
4. Reconverta os valores para caracteres (onde possível) e imprima a nova
matriz formatada
*/

#include <stdio.h>

int main(void)
{
    //variaveis
    char matrizChar[6][6] = {};
    int matrizInt[6][6] = {};
    float sumMedia = 0;
    float media = 0;
    int aux = 0;
    float matrizFloat[6][6] = {};
    int counterUsoMaiores = 0;
    int usouMaior = 0;
    int counterUsoMenores = 0;
    int contadorAtual = 0;
    int usouMenor = 0;
    int controleDS = 0;
    float auxChar = 0;

    //input
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            scanf("%c", &matrizChar[i][j]);
        }
    }

    //nova matriz 
    for(int  i = 0; i < 6; i++)
    {
        for(int  j = 0; j < 6 ; j++)
        {
            matrizInt[i][j] = matrizChar[i][j]; 
        }
    }

    //media geral
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            sumMedia += matrizChar[i][j];
        }
    }
    media = sumMedia / 36;
    
    //ordenação da matriz para uso dos termos
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            for(int k = 0; k < 6; k++)
            {
                for(int l = 0; l < 6; l++)
                {
                    if(matrizInt[k][l] > matrizInt[i][j]) //<- resulta em uma ordenação decrescente
                    {
                        aux = matrizInt[i][j];
                        matrizInt[i][j] = matrizInt[k][l];
                        matrizInt[k][l] = aux;
                    }
                }
            }
        }
    }

    //matriz float
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            //se for DP
            if(i == j)
            {
                //reseta o contador e o verificador para procurar um novo termo
                contadorAtual = 0;
                usouMaior = 0;

                //procura um maio que a média disponível
                for(int k = 0; k < 6; k++)
                {
                    for(int l = 0; l < 6; l++)
                    {
                        //se for usável, atualiza o uso e da break
                        if(matrizInt[k][l] > media && contadorAtual >= counterUsoMaiores)
                        {
                            //conta como já usado //tranfere o valor //marca como achado //para a busca interna
                            counterUsoMaiores = contadorAtual;
                            matrizFloat[i][j] = matrizInt[k][l];
                            usouMaior = 1;
                            break;
                        }

                        //passa para o próximo número (o 1o o contador é 0, e vai aumentando até o numero em que ja foi usado)
                        contadorAtual++;
                    }

                    //se já achou, break
                    if(usouMaior == 1)
                    {
                        break;
                    }
                }
            }
            else if(j == (5 - controleDS) && j != '\n' && j != ' ')
            {
                //atualiza o controle
                controleDS++;

                //tranfere o valor da media
                matrizFloat[i][j] = media;
            }
            else if(j == (5 - controleDS))
            {
                //atualiza o controle
                controleDS++;

                //transfere o valor 0
                matrizFloat[i][j] = 0;
            }
            else //<- valores abaixo da média
            {
                //reseta o contador para a busca do valor e o verificador de uso
                contadorAtual = 0;
                usouMenor = 0;

                //procura por um número abaixo da média pelo final da matriz ordenada
                for(int k = 5; k >= 0; k--)
                {
                    for(int l = 5; l >= 0; l--)
                    {
                        if(matrizInt[k][l] < media && contadorAtual >= counterUsoMenores)
                        {
                            //atualiza o contador dos números já usados (por "passagem" de numeros) //atualiza valor //atualiza verificador //break interno
                            counterUsoMenores = contadorAtual;
                            matrizFloat[i][j] = matrizInt[k][l];
                            usouMenor = 1;
                            break;
                        }
                    }

                    //se já achou, break
                    if(usouMenor == 1)
                    {
                        break;
                    }
                }
            }
        }
    }

    /*Minha interpretação:
    (Onde possível) -> Valores em que são intervalos caracteres (mesmo sendo float, basta apenas converter)*/

    //reconverter e printar para caractere //verifica por cada elemento na matriz
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            //para facilitar condicionais
            auxChar = matrizFloat[i][j];

            //se possível, converta e printe, senão, printe
            if((auxChar >= 'a' && auxChar <= 'z') || (auxChar >= 'A' && auxChar <= 'Z'))
            {
               printf(" %c ", (char)(int)auxChar); 
            }
            else
            {
                printf(" %.2f ", auxChar);
            }

            //cuida das quebras
            if(j == 5)
            {
                printf("\n");
            }
        }
    }

    return 0;
}