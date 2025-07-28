/*
3. Dado um vetor de 30 inteiros, crie um novo vetor contendo apenas
os valores que são múltiplos de 3 ou 7, sem repetição.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    //Vetores e variaveis
    int vetorNumeros[30] = {0};
    int counterDivisor = 0; //<- Quantidade de divisores de 3 ou 7
    int indexDivisor = 0;
    int random = 0;

    //Receber os 30 inputs pelo rand
    srand(time(NULL));
    for(int i = 0; i < 30; i++)
    {   
        random = rand() % 1000 + 1;
        vetorNumeros[i] = random;
    }

    //Verificacao se e multiplo de 3 ou 7 + soma do contador de multiplo de 3 ou 7
    for(int i = 0; i < 30; i++)
    {
        if(vetorNumeros[i] % 3 == 0 || vetorNumeros[i] % 7 == 0)
        {
            counterDivisor++;
        }
    }

    //Verificacao anterior, porem incorpora ao vetor criado
    int vetorDivisores[counterDivisor];

    for(int i = 0; i < 30; i++)
    {
        if(vetorNumeros[i] % 3 == 0 || vetorNumeros[i] % 7 == 0)
        {
            vetorDivisores[indexDivisor] = vetorNumeros[i];
            indexDivisor++;
        }       
    }

    //imprimir o vetor (dava para incorporar ao superior)
    printf("Os divisores por 3 ou 7, nao distintos: ");
    for(int i = 0; i < counterDivisor; i++)
    {
        if(i == (counterDivisor - 1))
        {
            printf("%d\n", vetorDivisores[i]);
        }
        else
        {
            printf("%d, ", vetorDivisores[i]);
        }
    }

    return 0;
}