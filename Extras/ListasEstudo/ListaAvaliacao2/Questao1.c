/*
1. Crie um vetor de 100 elementos com valores aleatórios de 1 a 500.
Elimine todos os valores duplicados e exiba o vetor final em ordem
decrescente.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    //"Seed" do rand
    srand(time(NULL));

    //Inicialização vetor e variaveis
    float vetorValores[100][2] = {0};
    float random = 0;
    float aux = 0;
    int totalDistintos = 100;

    //Aleatorização dos valores
    for(int i = 0; i < 100; i++)
    {
        //intervalo de 0-499 (pelo mod de resto de divisao) + 1 = 1-500;
        random = rand() % 500 + 1;

        //atribui numero e quantidade
        vetorValores[i][0] = random;
        vetorValores[i][1] = 1;
    }

    //Verificação iguais
    //Olha o da direita -> O fixo perde 1 de index para não chegar a um index inexistente
    //O index do móvel é o do fixo + 1, para comparar com outros diferente dele e de que ja foram comparados;
    for(int i = 0; i < (100 - 1); i++)
    {
        for(int j = i + 1; j < 100; j++)
        {
            //Ve se e igual e verifica se a quantidade é 0 (já anulado)
            if(vetorValores[i][0] == vetorValores[j][0] && vetorValores[i][1] != 0 && vetorValores[j][1] != 0)
            {
                vetorValores[i][1] += 1;
                vetorValores[j][1] = 0;
                totalDistintos--;
            }
        }
    }

    //Criação do vetor e inserção de diferentes
    float vetorDistintos[totalDistintos];
    int counterIndex = 0;

    for(int i = 0; i < 100; i++)
    {
        if(vetorValores[i][1] != 0)
        {
            vetorDistintos[counterIndex] = vetorValores[i][0];
            counterIndex++;
        }
    }

    //Ordenação da vetor
    //Fixo perde 1 do index para não haver erro devido ao i + 1 -> que implica que so compara com o posterior, assim, os maiores ficam a esquerda -> 15, [5], [10], ... - > 15, [10], 5, [...]
    for(int i = 0; i < (totalDistintos - 1); i++)
    {
        for(int j = i + 1; j < totalDistintos; j++)
        {
            if(vetorDistintos[j] > vetorDistintos[i])
            {
                aux = vetorDistintos[j];
                vetorDistintos[j] = vetorDistintos[i];
                vetorDistintos[i] = vetorDistintos[j];
            }
        }
    }

    //Printar o vetor
    printf("\nOs valores do vetor sao: ");
    for(int i = 0; i < totalDistintos; i++)
    {
        if(i == (totalDistintos - 1))
        {
            printf("%.2f\n", vetorDistintos[i]);
        }
        else
        {
            printf("%.2f, ", vetorDistintos[i]);
        }
    }

    return 0;
}