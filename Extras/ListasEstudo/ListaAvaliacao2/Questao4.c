/*
4. Receba um vetor de 60 números inteiros e separe os valores em 3
vetores distintos: positivos, negativos e zeros. Exiba todos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir(int vetor[], int index)
{
    for(int i = 0; i < (index + 1); i++)
    {
        if(i == index)
        {
            printf("%d\n", vetor[i]);
        }
        else
        {
            printf("%d, ", vetor[i]);
        }
    }
}

int main(void)
{
    //vetores e variaveis
    int vetorNumeros[60] = {0};
    int vetorPositivos[60] = {0};
    int vetorNegativos[60] = {0};
    int vetorZeros[60] = {0};
    int counterIndexPositivos = 0; //<- O index acaba atiando como contador de variáveis pois sempre será o do posterior
    int counterIndexNegativos = 0;
    int counterIndexZeros = 0;
    int random = 0;
    int sinal = 0;

    //seed do rand
    srand(time(NULL));

    //inputs
    for(int i = 0; i < 60; i++)
    {
        random = rand() % 1001; //de 0 a 1000
        sinal = rand() % 2; //de 0 a 1

        if(sinal == 0)
        {
            random *= -1;
        }
        //else ele se mantém positivo

        vetorNumeros[i] = random;
    }

    //verifações positivo, negativo, zero
    for(int i = 0; i < 60; i++)
    {
        if(vetorNumeros[i] > 0)
        {
            vetorPositivos[counterIndexPositivos] = vetorNumeros[i];
            counterIndexPositivos++;
        }
        else if(vetorNumeros[i] < 0)
        {
            vetorNegativos[counterIndexNegativos] = vetorNumeros[i];
            counterIndexNegativos++;
        }
        else
        {
            vetorZeros[counterIndexZeros] = vetorNumeros[i];
            counterIndexZeros++;
        }
    }

    //printar positivo, negativo, 0
    // - 1 pois é o index do posterior
    printf("Positivos: ");
    imprimir(vetorPositivos, counterIndexPositivos - 1);

    printf("Negativos: ");
    imprimir(vetorNegativos, counterIndexNegativos - 1);

    printf("Zeros: ");
    imprimir(vetorZeros, counterIndexZeros - 1);

    return 0;
}