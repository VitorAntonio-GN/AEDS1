/*
9. Faça um programa que leia clientes.txt e use realloc para permitir
adicionar mais clientes ao vetor, gravando o novo conjunto em
clientes_atualizado.txt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cliente{
    int id;
    char nome[51];
    char sobrenome[51];
};

int main(void)
{
    FILE* fileClientes = NULL;
    FILE* fileClientesAtualizados = NULL;
    char enderecoFileClientes[] = "clientes.txt";
    char enderecoFileClientesAtualizados[] = "clientesatualizados.txt";
    struct Cliente* clientesPtr = NULL;
    int sumClientes = 1; //garante o 1o cliente
    int indexCliente = sumClientes - 1; //formata index
    int opcaoEscolhida = 0;

    /*Abrir arquivo*/
    fileClientes = fopen(enderecoFileClientes, "r");
    fileClientesAtualizados = fopen(enderecoFileClientesAtualizados, "w");

    if(fileClientes == NULL || fileClientesAtualizados == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    /*Realocar struct*/
    clientesPtr = realloc(clientesPtr, sumClientes * sizeof(struct Cliente));

    /*Ler e realocar arquivo*/
    while((fscanf(fileClientes, "%d %s\n", &clientesPtr[indexCliente].id, &clientesPtr[indexCliente].nome, &clientesPtr[indexCliente].sobrenome)) != EOF)
    {
        sumClientes++; //passa para o proximo cliente
        indexCliente++; //passa para o proximo index

        clientesPtr = realloc(clientesPtr, sumClientes * sizeof(struct Cliente)); //realoca para o proximo
    }

    /*alocar novos clientes*/
    printf("Alocacao de novos clientes\n");
    while(1)
    {
        printf("Id; Nome\n");
        scanf("%d%s%s", &clientesPtr[indexCliente].id, &clientesPtr[indexCliente].nome, &clientesPtr[indexCliente].sobrenome); //já está no próximo cliente, devido ao código anterior

        sumClientes++; //passa proximo
        indexCliente++; //passa proximo

        printf("Digite -1 se quiser parar: ");
        scanf("%d", &opcaoEscolhida);
        if(opcaoEscolhida == -1) break;
    }

    /*retirar as excessões*/
    sumClientes--;
    indexCliente--; //<- estavam no próximo

    clientesPtr = realloc(clientesPtr, sumClientes * sizeof(struct Cliente));

    /*gravar clientes em clientesatualizados.txt*/
    for(int i = 0; i < sumClientes; i++)
    {
        fprintf(fileClientesAtualizados, "%d %s %s\n", &clientesPtr[i].id, &clientesPtr[i].nome, &clientesPtr[i].sobrenome);
    }

    /*Encerramento*/
    fclose(fileClientes);
    fclose(fileClientesAtualizados);
    free(clientesPtr);
    return 0;
}