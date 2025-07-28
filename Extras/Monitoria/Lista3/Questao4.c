#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Sim, foi proposital ser no mesmo for, me desafiei a usar um for que lê de 2 formas lkkkkkkk*/

int main(void)
{
    /*variaveis*/
    char nomeAutor[61] = {};
    char abntNomeAutor[61] = {};
    char listaPreposicoes[5][4] = {"de", "do", "da", "dos", "das"};
    char auxPreposicao[4] = {};
    int tamNomeAutor = 0;
    int caracteresNomeAutor = 0;
    int buscaDecrescente = 1;
    int imprimirLeitura = 0;

    /*inputs*/
    printf("Digite o nome do(a) autor(a): ");
    fgets(nomeAutor, 61, stdin);
    nomeAutor[strcspn(nomeAutor, "\n")] = '\0';

    /*atualização das variaveis*/
    tamNomeAutor = strlen(nomeAutor);
    caracteresNomeAutor = tamNomeAutor;

    /*formatação e exibição do nome*/
    for(int i = tamNomeAutor - 1; caracteresNomeAutor != 0; buscaDecrescente == 1 ? i-- : i++)
    {
        /*pega o último nome*/
        // -> formata e printa o ultimo nome
        // -> muda a forma de busca e altera o i
        if(nomeAutor[i] == ' ' && buscaDecrescente == 1)
        {
            for(int j = i + 1; j < tamNomeAutor; j++)
            {
                if(nomeAutor[j] >= 'a' && nomeAutor[j] <= 'z') nomeAutor[j] -= 32;
                printf("%c", nomeAutor[j]);
            }
            printf(", ");

            buscaDecrescente = 0;
            imprimirLeitura = 1;
            i = -1; // -> encerra o loop e passa a ser 0
        }

        /*imprime as iniciais dos nomes*/
        else if(imprimirLeitura == 1)
        {
            if(nomeAutor[i] >= 'a' && nomeAutor[i] <= 'z') nomeAutor[i] -= 32; // -> imprime formatado e desativa a impressão
            printf("%c. ", nomeAutor[i]);

            imprimirLeitura = 0;
        }

        /*marca o início de uma nova impressao*/
        else if(nomeAutor[i] == ' ')
        {
            for(int j = i + 1, k = 0; k < 3; j++, k++) 
            {
                auxPreposicao[k] = '\0'; // -> limpa antes de adicionar ou quebrar, para garantir uma verificação limpa

                if(nomeAutor[j] == ' ') break;

                auxPreposicao[k] = nomeAutor[j]; // -> adiciona a suposta preposição ao auxiliar
            }

            imprimirLeitura = 1;
            for(int j = 0; j < 5; j++)
            {
                if(strcmp(auxPreposicao, listaPreposicoes[j]) == 0)
                {
                    imprimirLeitura = 0; // -> se for preposição pula, se não for, permite a impressão
                    break;
                }
            }
        }

        caracteresNomeAutor--; // -> a cada iteração retira um da lista
    }
    printf("\n");

    return 0;
}