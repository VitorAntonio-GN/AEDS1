/*
11.Crie uma função que receba um ponteiro para vetor de inteiros alocados
dinamicamente e retorne a soma de todos os elementos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int somar_vetor(int* vetorInteiros, int tamVetorInteiros)
{
    int sumVetorInteiros = 0;

    for(int i = 0; i < tamVetorInteiros; i++)
    {
        sumVetorInteiros += *(vetorInteiros + i);
    }

    return sumVetorInteiros;
}