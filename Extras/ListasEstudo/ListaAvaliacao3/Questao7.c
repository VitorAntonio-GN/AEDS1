/*
7. Leia funcionarios.txt, filtre os funcionários com salário acima de R$
5.000,00 e grave em diretoria.txt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Funcionario{
    int id;
    char nome[51];
    float salario;
    char data[11];
};

int main(void)
{
    FILE* fileFuncionarios = NULL;
    FILE* fileDiretoria = NULL;
    char enderecoFileFuncionarios[] = "funcionarios.txt";
    char enderecoFileDiretoria[] = "diretoria.txt";
    struct Funcionario funcionario = {};
    float salarioDiretoria = 5000;

    fileDiretoria = fopen(enderecoFileDiretoria, "w");
    fileFuncionarios = fopen(enderecoFileFuncionarios, "r");

    if(fileDiretoria == NULL || fileFuncionarios == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    while((fscanf(fileFuncionarios, "%d %s %f %s\n", &funcionario.id, &funcionario.nome, &funcionario.salario, &funcionario.data)) != EOF)
    {
        if(funcionario.salario > 5000)
        {
            fprintf(fileDiretoria, "%d %s %0.2f %s\n", funcionario.id, funcionario.nome, funcionario.salario, funcionario.data);
        }
    }

    fclose(fileDiretoria);
    fclose(fileFuncionarios);
    return 0;
}