/*
12.Leia uma frase e indique quantas palavras possuem todas as letras
distintas entre si (sem letras repetidas).
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    //vetor e variaveis
    char vetorFrase[501] = {0};
    int counterCaracteresFrase = 0;
    char vetorPalavra[501] = {0};
    int counterIndexPalavra = 0;
    int isIgualCaractere = 0;
    int counterPalavrasDistintas = 0;

    //inputs
    printf("Digite uma frase com ate 500 caracteres: ");
    fgets(vetorFrase, 501, stdin);

    //pegar a quantidade de caracteres usados
    counterCaracteresFrase = strlen(vetorFrase);

    //verificar as frases
    for(int i = 0; i < counterCaracteresFrase; i++) //<- retirar o -1 para abranger quando há \n (erro, a ultima palavra) (<= (abrange pelo <=))
    {
        if(vetorFrase[i] != ' ' && vetorFrase[i] != '\n') //<- se espaço ou fim da string, verifica (false)
        {
            vetorPalavra[counterIndexPalavra] = vetorFrase[i];
            counterIndexPalavra++;
        }
        else
        {
            //verificar letras na palavra
            for(int j = 0; j < counterIndexPalavra - 1; j++) //<- do proximo, o < ja tira a range
            {
                for(int k = j + 1; k < counterIndexPalavra; k++) //verificar as palavras pelo ' '
                {
                    if(vetorPalavra[j] == vetorPalavra[k] || (vetorPalavra[j] - vetorPalavra[k]) == 32 || (vetorPalavra[j] - vetorPalavra[k]) == -32) //<- se o fixo for igual ao comparativo
                    {
                        isIgualCaractere = 1;
                    }               
                }
            }

            if(isIgualCaractere == 0)
            {
                counterPalavrasDistintas++;
            }

            counterIndexPalavra = 0;
        }
    } 
    
    //printar contador de frases distintas
    printf("Palavras com letras distintas: %d\n", counterPalavrasDistintas);
    return 0;
}