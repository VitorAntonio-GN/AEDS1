/*
2. Faça um programa que leia 50 números e informe a maior sequência
crescente contínua dentro do vetor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    //Inicializar variaveis e vetores
    float vetorNumeros[50] = {0};
    int indexInicioMaiorCrescente = 0;
    int indexFinalMaiorCrescente = 0;
    int counterMaiorCrescente = 0;
    int counterCrescente = 1; //<- Começa em 1 pois o 1° número já esta incluso
    int trocouIndex = 0;

    //Variaveis para teste
    srand(time(NULL));
    float random = 0;

    //Pegar 50 inputs
    for(int i = 0; i < 50; i++)
    {
        //Aleatorização para testes
        random = rand() % 1000 + 1;
        vetorNumeros[i] = random;

        //Pega os 50 inputs e atrela ao vetor
        //printf("Digite o %d° valor: ", (i + 1));
        //scanf("%f", &vetorNumeros[i]);
    }

    //Verificar maior sequencia crescente
    //Perde 1 de index, pois no index 48 (49° n°) irá comparar com o index 49 (50° número) -> Fim da comparação
    for(int i = 0; i < (50 - 1); i++)
    {
        if(vetorNumeros[i] < vetorNumeros[i + 1])
        {
            counterCrescente++;
        }
        else
        {
            if(counterCrescente > counterMaiorCrescente)
            {
                counterMaiorCrescente = counterCrescente;
                indexFinalMaiorCrescente = i;
                indexInicioMaiorCrescente = i + 1 - counterCrescente;
                trocouIndex = 1;
            }

            counterCrescente = 1;
        }
    }

    //Se não há sequencia crescente
    if(trocouIndex = 0)
    {
        printf("Nao ha sequencia crescente\n");
        
        return 1;
    }

    //Printar a maior lista crescente
    printf("A maior sequencia crescente e: ");
    for(int i = indexInicioMaiorCrescente; i <= indexFinalMaiorCrescente; i++)
    {
        if(i == indexFinalMaiorCrescente)
        {
            printf("%.2f\n", vetorNumeros[i]);
        }
        else
        {
            printf("%.2f, ", vetorNumeros[i]);
        }
    }

    return 0;
}