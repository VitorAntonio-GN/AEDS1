/*
13.Crie um programa que aloque um vetor de N floats, leia os dados do teclado,
calcule a média e grave em media.txt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    float* vetorFloats = NULL;
    int sumFloats = 1;
    int indexFloats = 0;
    FILE* fileFloats = NULL;
    char enderecoFileFloats[] = "media.txt";
    int opcaoEscolhida = 0;
    float media = 0;

    while(1)
    {
        vetorFloats = realloc(vetorFloats, sumFloats * sizeof(float)); //aloca espaço para guarda
        fscanf(stdin, "%f", &vetorFloats[indexFloats]); //guarda
        media += vetorFloats[indexFloats]; //soma media

        //incrementa para o proximo
        sumFloats++;
        indexFloats++;

        printf("1 para sair\n");
        fscanf(stdin, "%d", &opcaoEscolhida);

        if(opcaoEscolhida == 1)
        {
            break;
        }
    }

    //retira o proximo e termina a media
    sumFloats--;
    indexFloats--;
    media /= sumFloats;

    //abre arquivo
    fileFloats = fopen(enderecoFileFloats, "w");

    if(fileFloats == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    //grava media
    fprintf(fileFloats, "Media: %0.2f\n", media);

    //fecha arquivo e libera memoria
    fclose(fileFloats);
    free(vetorFloats);

    return 0;
}