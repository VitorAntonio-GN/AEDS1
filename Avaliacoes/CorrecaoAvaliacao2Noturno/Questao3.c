/*
3. Manipulação e Comparação de Strings (7,5 pontos)
Crie um programa que trabalhe com 4 palavras digitadas pelo usuário (com até 40
caracteres cada).
1. Valide que as palavras não estejam repetidas.
2. Armazene as palavras em uma matriz de char[4][41].
3. Ordene as palavras em ordem alfabética inversa (Z → A).
4. Considere agora a segunda e a quarta palavra da lista e:
o Verifique se terminam com a mesma letra.
o Conte quantos caracteres são consoantes em posições iguais.
o Informe qual palavra contém mais vogais no total.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //variáveis
    char matrizChar[4][41] = {0};
    int indexPalavra = 0;
    int isIgual = 0;
    char aux[41] = {};
    int strlen4a = 0;
    int strlen2a = 0;
    int lowStrlen = 0;
    char vogais[6] = {'a', 'e', 'i', 'o', 'u', '\0'};
    int isVogal2a = 0;
    int isVogal4a = 0;
    int sumVogal2a = 0;
    int sumVogal4a = 0;

    //input //verificação repetidas
    do
    {
        //reseta
        isIgual = 0;

        //pega a palavra e atribui ao index
        scanf("%s", &matrizChar[indexPalavra]);

        //verifica se é uma palavra repetida
        for(int i = 0; i < indexPalavra; i++)
        {
            if(strcmp(matrizChar[i], matrizChar[indexPalavra]) == 0)
            {
                //é igual //subtrai o index para repetir na próxima
                isIgual = 1;
                indexPalavra--;
            }
        }

        //passa para o próximo index
        indexPalavra++;

    } while(indexPalavra != 4 || isIgual == 1);

    //ordenação
    for(int i = 0; i < 3; i++)
    {
        for(int j = i + 1; j < 4; j++)
        {
            if(strcmp(matrizChar[i], matrizChar[j]) == -1) //<- se a 1a vem antes no alfabeto (-1)
            {
                strcpy(aux, matrizChar[i]);
                strcpy(matrizChar[i], matrizChar[j]);
                strcpy(matrizChar[j], aux);
            }
        }
    }

    //parte responsável pelasverificações entre a 2a e a 4a palavra ordenadas

    //pega o tamanho das palavras
    strlen2a = strlen(matrizChar[1]);
    strlen4a = strlen(matrizChar[3]);

    //verifica se a última é igual
    if(matrizChar[1][strlen2a - 1] == matrizChar[3][strlen4a - 1]) //<- (-1) pelo index
    {
        printf("A ultima letra da 2a e 4a palavras ordenadas sao iguais\n");
    }

    //demarca o menor tamanho da palavra
    if(strlen2a < strlen4a)
    {
        lowStrlen = strlen2a;
    }
    else
    {
        lowStrlen = strlen4a;
    }

    /*Minha interpretação:
    (em posições iguais) -> em possições possiveis a ambos -> lowStrlen
    (quantos são consoantes) -> se a 2a for e a 4a não, será 1, se ambas, será 2, se nenhuma, será 0
    (conte) -> vou printar*/

    //verifica se é consoante ou não e se não for, printa pela posição
    for(int i = 0; i < lowStrlen; i++)
    {
        //reseta para verificação
        isVogal2a = 0;
        isVogal4a = 0;

        //se não for vogal -> é consoante
        for(int j = 0; j < 5; j++) // <- 5 pois o index do \0 é 5 (são 6 termos, 'a', 'e', 'i', 'o', 'u' e '\0', de index 5), assim não o toca <- otimização
        {
            if(tolower(matrizChar[1][i]) == vogais[j])
            {
                isVogal2a = 1;   
            }

            if(tolower(matrizChar[3][i]) == vogais[j])
            {
                isVogal4a = 1;
            }
        }

        //printar de acordo com a posição
        printf("Na %da posicao, existem %d consoantes\n", (i + 1), (2 - isVogal2a - isVogal4a)); // <- 2 por padrão, se for vogal já subtrai e sai automático
    }

    //verificação de qual palavra tem mais vogais //(a outra foi só ate o menor range) //pelo range específico

    //verifica por cada letra
    for(int i = 0; i < strlen2a; i++)
    {
        //reset
        isVogal2a = 0;

        //verificação
        for(int j = 0; j < 6; j++)
        {
            if(tolower(matrizChar[1][i]) == vogais[j])
            {
                isVogal2a = 1;
            }
        }

        //se for vogal, soma
        if(isVogal2a == 1)
        {
            sumVogal2a++;
        }
    }

    //verifica por cada letra
    for(int i = 0; i < strlen4a; i++)
    {
        //reset
        isVogal4a = 0;

        //verificação
        for(int j = 0; j < 6; j++)
        {
            if(tolower(matrizChar[3][i]) == vogais[j])
            {
                isVogal4a = 1;
            }
        }

        //se for vogal, soma
        if(isVogal4a == 1)
        {
            sumVogal4a++;
        }
    }
    
    //verificação e print
    if(sumVogal2a > sumVogal4a)
    {
        printf("A 2a palavra tem mais vogais, com %d, ja a 4a tem %d\n", sumVogal2a, sumVogal4a);
    }
    else if (sumVogal4a > sumVogal2a)
    {
        printf("A 4a palavra tem mais vogais, com %d, ja a 2a tem %d\n", sumVogal4a, sumVogal2a);
    }
    else
    {
        printf("Ambas 4a e 2a palavra tem vogais em quantidades iguais, com %d cada\n", sumVogal2a);
    }

    return 0;
}