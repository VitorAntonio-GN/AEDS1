/*
15.Escreva uma função que receba um vetor dinâmico de inteiros e substitua
cada valor pela soma dos vizinhos. Grave o vetor final em
transformado.txt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gravar_vizinhos(int* vetorInteiroPtr, int tamVetorInteiro)
{
    FILE* fileVizinhos = NULL;
    char enderecoFileVizinhos[] = "transformado.txt";
    int testeEsquerda = 0;
    int testeDireita = 0;
    int somaVizinhos = 0;

    fileVizinhos = fopen(enderecoFileVizinhos, "w");

    for(int i = 0; i < tamVetorInteiro; i++)
    {
        somaVizinhos = 0;
        testeEsquerda = i - 1;
        testeDireita = i + 1;

        if(testeEsquerda > 0)
        {
            somaVizinhos += vetorInteiroPtr[testeEsquerda];
        }

        if(testeDireita < tamVetorInteiro)
        {
            somaVizinhos += vetorInteiroPtr[testeDireita];
        }

        vetorInteiroPtr[i] = somaVizinhos;

        fprintf(fileVizinhos, "%d ", vetorInteiroPtr[i]);
    }

    fclose(fileVizinhos);
    return 0;
}