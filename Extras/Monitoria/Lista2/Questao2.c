#include <stdio.h>

int main(void)
{
    float total = 0;
    float produtoMaisCaro = 0;
    int indexProdutoMaisCaro = 0;
    float media = 0;
    int sumProdutos = 5;
    float produto = 0;
    
    for(int i = 0; i < 5; i++)
    {
        printf("Informe o valor do produto %d: ", i + 1);
        scanf("%f", &produto);

        total += produto;
        if(produto > produtoMaisCaro)
        {
            produtoMaisCaro = produto;
            indexProdutoMaisCaro = i;
        }
    }
    media = total / sumProdutos;

    printf("\nTotal gasto: R$%0.2f\nValor médio: R$%0.2f\nProduto mais caro: Produto %d (R$%0.2f)\n", total, media, indexProdutoMaisCaro + 1, produtoMaisCaro);

    return 0;
}