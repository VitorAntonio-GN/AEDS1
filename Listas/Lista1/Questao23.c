#include <stdio.h>

//23.Número mais frequente em uma sequência com for: peça N números e determine qual aparece mais vezes.
int main(void)
{
    //pega numeros da sequencia
    int n = 0;
    printf("Quantos numeros na sequencia? ");
    scanf("%d", &n);
    printf("\n");

    //declara lista
    int list[n];

    //adiciona valores a lista
    for(int i = 0; i < n; i++)
    {
        printf("Digite o %do numero: ", (i + 1));
        scanf("%d", &list[i]);
    }

    //variaveis comparacao
    int listequal[n];
    int countn = 0;
    int countmoden = 0;
    int moden = 0;
    int countnequal = 0;

    //compara os valores da lista
    //para cada numero
    for(int j = 0; j < n; j++)
    {
        //para cada menor numero
        for(int k = j;  k < n; k++)
        {
            if(list[j] == list[k])
            {
                countn++;
            }
        }

        //se mais se repete
        if(countn > countmoden)
        {
            countnequal = 0;
            countmoden = countn;
            moden = list[j];
        }
        else if(countn == countmoden)
        {
            listequal[countnequal] = list[j];
            countnequal++;
        }

        //reseta contador
        countn = 0;
    }

    //se tiver so um que se repete mais
    if(countnequal == 0)
    {
        printf("\nO numero %d mais se repete na lista %d vezes\n\n", moden, countmoden);
    }
    //caso 2 ou mais se repitam igual
    else
    {
        printf("\nOs numeros: %d, ", moden);
        for(int l = 0; l < countnequal; l++)
        {
            if(l == (countnequal - 1))
            {
                printf("%d ", listequal[l]);
            }
            else
            {
                printf("%d, ", listequal[l]);
            }
        }
        printf("se repetem %d vezes nessa lista\n\n", countmoden);
    }
        
    return 0;
}