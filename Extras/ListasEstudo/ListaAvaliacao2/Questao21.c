/*
21.Crie um programa que leia uma frase, divida as palavras em um vetor
e ordene apenas as que começam com vogal, mantendo as demais
na posição original.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
    //vetor e string
    char vetorFrase[102] = {0};
    char vogais[6] = {'a', 'e', 'i', 'o', 'u'}; //<- -1 pelo \0
    int counterEspacos = 0;
    int indexColunaMatrizVetor = 0;
    int indexLinhaMatrizVetor = 0;
    int isVogal = 0;
    int counterVogais = 0;
    int indexLinhaMatrizVogal = 0;
    int comparativoMatrizVogal = 0;
    
    //inputs
    fgets(vetorFrase, 102, stdin);

    //pegar tamanho
    int tamVetorFrase = strlen(vetorFrase);

    //Quebra de linha
    vetorFrase[tamVetorFrase - 1] = '\0'; //<- trata a quebra de linha

    //menos o '\n'
    tamVetorFrase--;

    //for para ver quantas linhas tera a matriz
    for(int i = 0; i < tamVetorFrase; i++)
    {
        if(vetorFrase[i] == ' ')
        {
            counterEspacos++;
        }
    }

    //declaração do outro vetor
    char VetorFraseMatriz[counterEspacos + 1][tamVetorFrase + 1];

    //formatar a matriz
    for(int  i = 0; i < counterEspacos + 1; i++)
    {
        for(int j = 0; j < tamVetorFrase + 1; j++)
        {
            VetorFraseMatriz[i][j] = '\0';
        }
    }

    //verificar se é a quebra
    for(int i = 0; i < tamVetorFrase; i++)
    {
        if(vetorFrase[i] == ' ' || vetorFrase[i] == '\0') //<- apesar de que não pega o '\0'
        {
            indexColunaMatrizVetor = 0;
            indexLinhaMatrizVetor++;
        }
        else
        {
            VetorFraseMatriz[indexLinhaMatrizVetor][indexColunaMatrizVetor] = vetorFrase[i];
            indexColunaMatrizVetor++;
        }
    }

    //verificar se começa com vogal
    for(int i = 0; i < counterEspacos + 1; i++) //<- O n° de linhas do vetor é esse, olha cada linha
    {
        //compara a letra com as vogais
        for(int j = 0; j < 5; j++)
        {
            if(VetorFraseMatriz[i][0] == vogais[j] || VetorFraseMatriz[i][0] == (vogais[j] - 32))
            {
                isVogal = 1;
            }
        }

        //verifica se é vogal
        if(isVogal == 1)
        {
            //adiciona ao contador de vogais para declarar o vetor depois
            counterVogais++;
        }
    }

    //declaração do vetor de vogais
    char vetorMatrizFrasesVogais[counterVogais][tamVetorFrase + 1];

    //verifica se é vogal e se for adiciona
    for(int i = 0; i < counterEspacos + 1; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(tolower(VetorFraseMatriz[i][0]) == vogais[j])
            {
                //adiciona a frase ao vetor de vogais
                for(int k = 0; k < tamVetorFrase + 1; k++)
                {
                    vetorMatrizFrasesVogais[indexLinhaMatrizVogal][k] = VetorFraseMatriz[i][k];
                }
                indexLinhaMatrizVogal++;
            }
        }
    }

    //auxiliar para trocar as strings
    int aux[tamVetorFrase + 1];

    //verifica qual vogal tem o maior tamanho
    for(int i = 0; i < counterVogais - 1; i++) //<- é um bubble de vetor, as strings agem como um elemento no strcmp
    {
        for(int j = i + 1; j < counterVogais; j++)
        {
            //compara o 1° <- fixo e o 2° <- nao fixo
            comparativoMatrizVogal = strcmp(vetorMatrizFrasesVogais[i], vetorMatrizFrasesVogais[j]); //<- strcmp retorna o valor em realação ao str1, 1 se ele e maior, -1 se menor, 0 se igual
        
            if(comparativoMatrizVogal < 0)
            {
                //trocar as string (sabemos a coluna do menor (i), precimos trocar)
                for(int k = 0; k > tamVetorFrase + 1; k++)
                {
                    aux[k] = vetorMatrizFrasesVogais[i][k];
                    vetorMatrizFrasesVogais[i][k] = vetorMatrizFrasesVogais[j][k]; 
                    vetorMatrizFrasesVogais[j][k] = aux[k];
                }
            }
        }
    }

    //em tese acabou, eu poderia tratar as letras transformando todas em lower e depois deixando a primeira em maiusculo

    return 0;
}