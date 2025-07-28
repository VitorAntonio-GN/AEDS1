/*
3. Crie uma struct Produto com código, nome e preço. Cadastre N produtos
usando alocação dinâmica e grave em produtos.txt.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Produto{
    int codigo;
    char nome[51];
    float preco;
};

int main(void)
{
    struct Produto* produtos = NULL;
    int numProdutos = 0;
    FILE* fileProdutos = NULL;
    char enderecoFileProdutos[] = "produtos.txt";

    printf("Quantos produtos? ");
    scanf("%d", &numProdutos);

    produtos = realloc(produtos, numProdutos * sizeof(struct Produto));
    fileProdutos = fopen(enderecoFileProdutos, "w");

    if(fileProdutos == NULL)
    {
        printf("Erro ao abrir o file\n");
        return 1;
    }

    for(int i = 0; i < numProdutos; i++)
    {
        printf("Codigo; Nome; Preco\n");
        scanf("%d%s%f", &produtos[i].codigo, &produtos[i].nome, &produtos[i].preco);

        fprintf(fileProdutos, "%d %s %0.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco);
    }

    fclose(fileProdutos);
    free(produtos);
    return 0;
}