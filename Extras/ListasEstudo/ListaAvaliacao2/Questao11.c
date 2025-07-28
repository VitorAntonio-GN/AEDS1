/*
11.Escreva uma função que receba uma string e substitua cada
consoante por ‘#’ e cada vogal pelo número de sua posição na
palavra.
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    //vetor e variaveis
    char vogais[6] = {'a', 'e', 'i', 'o', 'u'};
    char palavra[51] = {0}; //<- pensar em 51 - '\0'
    int isVogal = 0;
    int quantidadeLetrasPalavra = 0;

    //input 
    printf("Digite a string: ");
    fgets(palavra, 51, stdin);

    quantidadeLetrasPalavra = strlen(palavra) - 1; //<- Esqueci de ver a real quantidade de palavras (inclui o '\0', por isso eu o retirei)

    //verificação
    for(int i = 0; i < quantidadeLetrasPalavra; i++) //<- 51 - 1 = 50 ("\0") - 1 = 49 ("...")
    {
        for(int j = 0; j < 5; j++)
        {
            if(palavra[i] == vogais[j] || palavra[i] == (vogais[j] - 32))
            {
                isVogal = 1;
            }
        }

        if(isVogal == 1)
        {
            palavra[i] = i + 1;
        }
        else
        {
            palavra[i] = '#';
        }

        isVogal = 0; //<- Esqueci do resetador
    }

    //printar resultado
    printf("Palavra: ");
    for(int i = 0; i < quantidadeLetrasPalavra; i++)
    {
        if(palavra[i] != '#')
        {
            printf(" %d ", (int)palavra[i]);
        }
        else
        {
            printf(" # ");
        }
    }
    printf("\n");

    return 0;
}