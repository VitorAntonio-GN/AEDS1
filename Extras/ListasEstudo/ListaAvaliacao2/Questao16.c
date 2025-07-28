/*
16.Implemente uma função que receba um vetor de inteiros e retorne a
mediana dos valores.
*/

#include <stdio.h>
#include <math.h>

float mediana(int vetor[], int tamanho)
{
    int aux = 0;
    float medianaLista = 0;
    float indexmediana = 0;

    // Ordena o vetor em ordem crescente
    for(int i = 0; i < tamanho - 1; i++)
    {
        for(int j = i + 1; j < tamanho; j++)
        {
            if(vetor[j] < vetor[i])
            {
                aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
            }
        }
    }

    if (tamanho % 2 == 0)
    {
        medianaLista = (float)(vetor[tamanho/2 - 1] + vetor[tamanho/2]) / 2.0;
    }
    else
    {
        medianaLista = (float)vetor[tamanho/2];
    }

    return medianaLista;
}

int main(void)
{
    //vetores e variaveis
    int vetorLista[6] = {1, 2, 6, 8, 9, 10};
    float medianaLista = 0;
    int tamanho = 6;

    //inputs

    //função mediana (vetor e tamanho)
    medianaLista = mediana(vetorLista, tamanho); 

    //printar a mediana
    printf("Mediana: %.2f", medianaLista);

    return 0;
}