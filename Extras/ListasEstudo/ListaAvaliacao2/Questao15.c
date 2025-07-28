/*
15.Leia uma string e verifique se ela contém somente letras minúsculas
e está em ordem alfabética crescente.
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    //vetor e variaveis
    char vetorPalavra[501] = {0};
    char oldChar = 0;
    int tamanhoPalavra = 0;
    int isCrescente = 1;
    int isMinuscula = 1;

    //input
    fgets(vetorPalavra, 501, stdin);

    //pegar o tamanho da string
    tamanhoPalavra = strlen(vetorPalavra);

    //for para verificar se a string é composta apenas de minusculas
    for(int i = 0; i < (tamanhoPalavra - 1); i++) //<- nao pega o \n
    {
        if(vetorPalavra[i] >= 'A' && vetorPalavra[i] <= 'Z')
        {
            vetorPalavra[i] += 32;
            isMinuscula = 0;
        }
    }

    //for para verificar a string é crescente
    for(int i = 0; i < (tamanhoPalavra - 2); i++) //<- nao pega o \n e perde 1 de range
    {
        if(vetorPalavra[i] > vetorPalavra[i + 1])
        {
            isCrescente = 0;
        }
    }

    //verificaçoes
    if(isCrescente == 1)
    {
        printf("E crescente\n");
    }
    if(isMinuscula == 1)
    {
        printf("So tem minuscula\n");
    }

    return 0;
}