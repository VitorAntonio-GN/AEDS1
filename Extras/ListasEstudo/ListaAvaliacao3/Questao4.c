/*
4. Escreva um programa que leia produtos.txt, encontre o produto mais caro
e exiba seus dados na tela.
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
    struct Produto produto = {};
    struct Produto produtoMaiorPreco = {};

    fileProdutos = fopen(enderecoFileProdutos, "r");

    if(fileProdutos == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    while((fscanf(fileProdutos, "%d %s %f\n", &produto.codigo, &produto.nome, &produto.preco)) != EOF)
    {
        if(produtoMaiorPreco.preco < produto.preco)
        {
            produtoMaiorPreco = produto;
        }
    }

    fclose(fileProdutos);

    printf("%d %s %.02f\n", produtoMaiorPreco.codigo, produtoMaiorPreco.nome, produtoMaiorPreco.preco);

    return 0;
}