/*
10.Leia clientes.txt, grave apenas os que possuem sobrenome "Silva" em
clientes_silva.txt.
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
    FILE* fileClientesSilva = NULL;
    char enderecoFileClientes[] = "clientes.txt";
    char enderecoFileClientesSilva[] = "clientes_silva.txt";
    struct Cliente cliente = {};

    fileClientes = fopen(enderecoFileClientes, "r");
    fileClientesSilva = fopen(enderecoFileClientesSilva, "w");

    if(fileClientes == NULL || fileClientesSilva == NULL) 
    {
        printf("Erro ao abrir o arquivo\n"); 
        return 1;
    }

    while((fscanf(fileClientes, "%d %s %s\n", &cliente.id, &cliente.nome, &cliente.sobrenome)) != EOF)
    {
        if(strcmp(cliente.sobrenome, "Silva") == 0)
        {
            fprintf(fileClientesSilva, "%d %s %s\n", cliente.id, cliente.nome, cliente.sobrenome);
        }
    }

    fclose(fileClientes);
    fclose(fileClientesSilva);

    return 0;
}