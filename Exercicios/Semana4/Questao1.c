/*
1. Vetor: Estatísticas de Ocorrências e Análise de Frequência
Escreva um programa em C que leia 30 números inteiros e os armazene em
um vetor. Em seguida, o programa deve:
Verificar e exibir:
• Todos os números distintos digitados.
• Quantas vezes cada número distinto aparece no vetor.

Identificar:
• O número que mais se repete e quantas vezes apareceu.
• O número que menos se repete (mas que apareceu ao menos uma
vez).

Mostrar:
• Todos os números que aparecem exatamente duas vezes.
• Todos os números que aparecem mais de duas vezes.

Exibir os números em ordem crescente (apenas os distintos).
*/

#include <stdio.h>

int main(void)
{
    int valores[30];

    //pegar os valores
    for(int i = 0; i < 30; i++)
    {
        printf("Digite o %d° valor: ", (i + 1));
        scanf("%d", &valores[i]);
    }

    //ordenar os valores
    //para cada fixo (-1 range)
    int aux = 0;
    for(int j = 0; j < 29; j++)
    {
        //para cada 1 depois do fixo
        for(int k = (j + 1); k < 30; k++)
        {
            if(valores[j] > valores[k])
            {
                aux = valores[j];
                valores[j] = valores[k];
                valores[k] = aux;
            }
        }
    }

    //numeros distintos
    int counterd = 1;
    int bnumcounter = 0;
    int lnumcounter = 0;
    int isfirst = 1;
    int valoresminimos[30];
    int counterminimos = 0;
    int valoresmaximos[30];
    int countermaximos = 0;
    int valoresdistindos[30];
    int counterdistintos = 0;
    int valorescountd2[15];
    int counter2 = 0;
    int valorescountdmaiorque2[10];
    int countermaiorque2 = 0;

    printf("\nAs repeticoes sao:\n");
    for(int l = 1; l <= 30; l++)
    {
        if(valores[(l - 1)] != valores[l] || l == 30)
        {
            printf("%d: %d vezes\n", valores[l - 1], counterd);

            valoresdistindos[counterdistintos] = valores[l - 1];
            counterdistintos++;

            if(isfirst == 1)
            {
                isfirst = 0;
                bnumcounter = counterd;
                lnumcounter = counterd;

                valoresminimos[counterminimos] = valores[l - 1];
                valoresmaximos[countermaximos] = valores[l - 1];
                counterminimos++;
                countermaximos++;
            }
            else if(counterd > bnumcounter)
            {
                bnumcounter = counterd;

                countermaximos = 0;
                valoresmaximos[countermaximos] = valores[l - 1];
                countermaximos++;

            }
            else if(counterd < lnumcounter)
            {
                lnumcounter = counterd;

                counterminimos = 0;
                valoresminimos[counterminimos] = valores[l - 1];
                counterminimos++;

            }
            else if(counterd == bnumcounter)
            {
                valoresmaximos[countermaximos] = valores[l - 1];
                countermaximos++;
            }
            else if(counterd == lnumcounter)
            {
                valoresminimos[counterminimos] = valores[l - 1];
                counterminimos++;
            }

            if(counterd == 2)
            {
                valorescountd2[counter2] = valores[l - 1];
                counter2++;
            }
            else if(counterd > 2)
            {
                valorescountdmaiorque2[countermaiorque2] = valores[l -1];
                countermaiorque2++;
            }

            counterd = 1;
        }
        else
        {
            counterd++;
        }
    }

    //obs: nao esta <= pois em algum momento, na forma que esta no script, o valor do counter (funciona como index) nao tera um proximo, mas o index sera o do proximo,
    //o que implica na repetição extra ex: só tem 1 maior, vai sair do indez 0 e vai para o 1, seria iterado 0 e 1, porem é so 1 maior, 
    //assim o < ja retira esse bug pois nao pega a range

    //distintos
    printf("\nOs numeros distintos sao:");
    for(int m = 0; m < counterdistintos; m++)
    {
        printf(" %d;", valoresdistindos[m]);
    }
    printf("\n\n");

    //mais se repete
    printf("O que mais se repete(m) sao(e):");
    for(int n = 0; n < countermaximos; n++)
    {
        printf(" %d,", valoresmaximos[n]);
    }
    printf(" que se repetem %d vezes\n", bnumcounter);

    //menos se repete
    printf("O que menos se repete(m) sao(e):");
    for(int o = 0; o < counterminimos; o++)
    {
        printf(" %d,", valoresminimos[o]);
    }
    printf(" que se repetem %d vezes\n", lnumcounter);
    printf("\n");

    //aparece 2 vezes
    printf("Os que aparecem duas vezes:");
    for(int p = 0; p < counter2; p++)
    {
        printf(" %d;", valorescountd2[p]);
    }
    printf("\n\n");

    //aparece >2 vezes
    printf("Os que aparecem mais que duas vezes:");
    for(int q = 0; q < countermaiorque2; q++)
    {
        printf(" %d;", valorescountdmaiorque2[q]);
    }
    printf("\n\n");

    return 0;
}