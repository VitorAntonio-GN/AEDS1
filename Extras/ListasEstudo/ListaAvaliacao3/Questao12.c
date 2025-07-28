/*
12.Implemente um programa que leia N números inteiros, armazene dinamicamente
e grave o maior e menor valor em resultado.txt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int N = 0;
    int* vetorInteirosPtr = NULL;
    FILE* fileResultado = NULL;
    char enderecoFileResultado[] = "resultado.txt";
    int maiorInt = 0;
    int menorInt = 0;

    printf("Digite N: ");
    scanf("%d", &N);

    vetorInteirosPtr = realloc(vetorInteirosPtr, N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", (vetorInteirosPtr + i));
    }

    if(N > 0)
    {
        maiorInt = vetorInteirosPtr[0];
        menorInt = vetorInteirosPtr[0];
    }

    fileResultado = fopen(enderecoFileResultado, "w");

    if(fileResultado == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    for(int i = 0; i < N; i++)
    {
        if(vetorInteirosPtr[i] > maiorInt)
        {
            maiorInt = vetorInteirosPtr[i];
        }
        else if(vetorInteirosPtr[i] < menorInt)
        {
            menorInt = vetorInteirosPtr[i];
        }
    }

    fprintf(fileResultado, "Maior: %d\nMenor: %d\n", maiorInt, menorInt);
    fclose(fileResultado);
    free(vetorInteirosPtr);
    return 0;
}