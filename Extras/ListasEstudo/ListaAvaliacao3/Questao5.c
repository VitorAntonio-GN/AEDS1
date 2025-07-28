/*
5. Crie um programa que permita atualizar o preço de um produto (por
código), lendo de produtos.txt e gravando em produtos_atualizados.txt.
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
    FILE* fileProdutos = NULL;
    char enderecoFileProdutos[] = "produtos.txt";
    int codigoBusca = 0;
    struct Produto produto = {};
    FILE* fileProdutosAtualizados = NULL;
    char enderecoFileProdutosAtualizados[] = "produtosatualizados.txt";

    printf("Digite o codigo: ");
    scanf("%d", &codigoBusca);

    fileProdutos = fopen(enderecoFileProdutos, "r");
    fileProdutosAtualizados = fopen(enderecoFileProdutosAtualizados, "w");

    if(fileProdutos == NULL || fileProdutosAtualizados == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    while((fscanf(fileProdutos, "%d %s %f\n", &produto.codigo, &produto.nome, &produto.preco)) != EOF)
    {
        if(produto.codigo == codigoBusca)
        {
            printf("Digite o novo preco: ");
            scanf("%f", &produto.preco);
        }

        fprintf(fileProdutosAtualizados, "%d %s %0.2f\n", produto.codigo, produto.nome, produto.preco);
    }

    fclose(fileProdutos);
    fclose(fileProdutosAtualizados);

    return 0;
}