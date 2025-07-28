/*
17.Desenvolva um programa que leia uma matriz quadrada de ordem N
(alocada dinamicamente como vetor simples), calcule a soma da diagonal
principal e grave em soma_diag.txt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int* vetorMatrizPtr = NULL;
    int tamVetorMatrizLinha = 0;
    int tamVetorMatrizTotal = 0;
    int somaDiagonalPrincipal = 0;
    FILE* fileSoma = NULL;
    char enderecoFileSoma[] = "soma_diag.txt";
    int indexControleDiagonalPrincipal = 0; // vai de 6 em 6 até o index max

    fputs("Digite N: ", stdout);
    scanf("%d", &tamVetorMatrizLinha);
    tamVetorMatrizTotal = tamVetorMatrizLinha * tamVetorMatrizLinha;

    vetorMatrizPtr = realloc(vetorMatrizPtr, tamVetorMatrizTotal * sizeof(int));

    fileSoma = fopen(enderecoFileSoma, "w");

    if(fileSoma == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    for(indexControleDiagonalPrincipal; indexControleDiagonalPrincipal < tamVetorMatrizTotal; indexControleDiagonalPrincipal += (tamVetorMatrizLinha + 1))
    {
        somaDiagonalPrincipal += vetorMatrizPtr[indexControleDiagonalPrincipal];
    }

    fprintf(fileSoma, "Soma diagonal principal: %d\n", somaDiagonalPrincipal);

    fclose(fileSoma);

    return 0;
}