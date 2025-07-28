/*
17.Crie uma função que receba duas palavras e retorne o número de
letras que estão na mesma posição e são iguais.
*/

#include <stdio.h>
#include <string.h>

int letrasiguais(char palavra1[], char palavra2[], int tamanhoVetor)
{
    int counterLetrasIguais = 0;

    for(int i = 0; i < (tamanhoVetor - 1); i++) // <- o -1 vem do '\n'  
    {
        if(palavra1[i] == palavra2[i] || palavra1[i] == (palavra2[i] + 32) || palavra1[i] == (palavra2[i] - 32))
        {
            counterLetrasIguais++;
        }
    }

    return counterLetrasIguais;
}

int main(void)
{
    //vetor e variaveis
    char vetorPalavra1[52] = {0};
    char vetorPalavra2[52] = {0};
    int tamanhoVetorPalavra1 = 0;
    int tamanhoVetorPalavra2 = 0;
    int menorTamanhoVetorPalavra = 0;
    int letrasMesmaPosicao = 0;

    //inputs
    fgets(vetorPalavra1, 52, stdin);
    fgets(vetorPalavra2, 52, stdin);

    //tamanho da str
    tamanhoVetorPalavra1 = strlen(vetorPalavra1);
    tamanhoVetorPalavra2 = strlen(vetorPalavra2);

    //pegar a menor palavra
    if(tamanhoVetorPalavra1 > tamanhoVetorPalavra2)
    {
        menorTamanhoVetorPalavra = tamanhoVetorPalavra2;
    }
    else
    {
        menorTamanhoVetorPalavra = tamanhoVetorPalavra1;
    }

    //chamar a função
    letrasMesmaPosicao = letrasiguais(vetorPalavra1, vetorPalavra2, menorTamanhoVetorPalavra);

    printf("Letras na mesma posicao e iguais: %d\n", letrasMesmaPosicao);

    return 0;
    
}