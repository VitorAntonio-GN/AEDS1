/*
13.Leia duas strings e verifique se uma é rotação da outra (ex: “abcd” e
“cdab” são rotações).
*/

#include <stdio.h>
#include <string.h>

int main(void) //<- identifiquei 2 modos, pela vetor de repetição do diego e verificação se há dentro, caso 0, não é; por um for que procura o 1° igual e se achar troca por '\n'
                //assim, se não for tudo '\n' (for verificando), não é
{
    //vetor e variaveis
    char vetorString1[501] = {0};
    char vetorString2[501] = {0};
    int counterTamanhoString1 = 0;
    int counterTamanhoString2 = 0;
    int isRotacao = 1;

    //inputs
    fgets(vetorString1, 501, stdin);
    fgets(vetorString2, 501, stdin);

    //pegar o tamanho da str
    counterTamanhoString1 = strlen(vetorString1);
    counterTamanhoString2 = strlen(vetorString2);

    //se tamanho diferente == diferente
    if(counterTamanhoString1 != counterTamanhoString2) //<- há o caso de ser a mesma string, mas seria um for comparando se as letras no mesmo index sao iguais, caso diferente, isesqual = 0
    {
        isRotacao = 0;
    }

    //verifica se sao iguais e marca os iguais
    for(int i = 0; i < counterTamanhoString1; i++)
    {
        for(int j = 0; j < counterTamanhoString1; j++)
        {
            if(vetorString1[i] == vetorString2[j])
            {
                vetorString1[i] = '\n';
                break;
            }
        }
    }

    //se todos forem '\n' é rotação
    for(int i = 0; i < counterTamanhoString1; i++)
    {
        if(vetorString1[i] != '\n')
        {
            isRotacao = 0;
        }
    }

    //printa o ultimo
    if(isRotacao == 0)
    {
        printf("Nao e rotacao\n");
    }
    else
    {
        printf("E rotacao\n");
    }

    return 0;
}