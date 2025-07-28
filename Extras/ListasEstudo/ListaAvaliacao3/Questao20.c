/*
20.Implemente um vetor de Produto alocado dinamicamente, ordene por
preço e grave em produtos_ordenados.txt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto{
    int id;
    char nome[51];
    float preco;
};

int main(void)
{
    struct Produto* produtosPtr = NULL;
    struct Produto aux = {};
    int N = 0;
    FILE* fileProdutos = NULL;
    char enderecoFileProdutos[] = "produtos_ordenados.txt";

    fputs("Digite N para alocar: ", stdout);
    fscanf(stdin, "%d", &N);

    produtosPtr = (struct Produto*) realloc(produtosPtr, N * sizeof(struct Produto));

    for(int i = 0; i < N - 1; i++)
    {
        for(int j = i + 1 ; j < N; j++)
        {
            if(produtosPtr[i].preco < produtosPtr[j].preco)
            {
                aux = produtosPtr[i];
                produtosPtr[i] = produtosPtr[j];
                produtosPtr[j] = aux;
            }
        }
    }

    fileProdutos = (FILE*) fopen(enderecoFileProdutos, "w");

    if(fileProdutos == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    for(int i = 0; i < N; i++)
    {
        fprintf(fileProdutos, "%d %s %0.2f\n", produtosPtr[i].id, produtosPtr[i].nome, produtosPtr[i].preco);
    }

    fclose(fileProdutos);
    free(produtosPtr);

    return 0;
}