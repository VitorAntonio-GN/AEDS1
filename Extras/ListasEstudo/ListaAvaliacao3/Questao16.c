/*
16.Crie um programa que leia dois vetores de inteiros (alocados
dinamicamente), some elemento a elemento e grave o resultado em
soma.txt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE* fileSoma = NULL;
    char enderecoFileSoma[] = "soma.txt";
    int soma = 0;
    int* vetorInteiro1 = NULL;
    int* vetorInteiro2 = NULL;
    int tamVetor1 = 0;
    int tamVetor2 = 0;

    if(tamVetor1 < tamVetor2)
    {
        vetorInteiro1 = realloc(vetorInteiro1, tamVetor2 * sizeof(int));

        for(int i = tamVetor1; i < tamVetor2; i++)
        {
            vetorInteiro1[i] = 0;
        }
    }
    else if(tamVetor2 < tamVetor1)
    {
        vetorInteiro2 = realloc(vetorInteiro2, tamVetor1 * sizeof(int));

        for(int i = tamVetor2; i < tamVetor1; i++)
        {
            vetorInteiro2[i] = 0;
        }
    }

    fileSoma = fopen(enderecoFileSoma, "w");

    for(int i = 0; i < tamVetor1; i++)
    {
        soma = vetorInteiro1[i] + vetorInteiro2[i];
        fprintf(fileSoma, "%d ", soma);
    }

    fclose(fileSoma);
    return 0;
}