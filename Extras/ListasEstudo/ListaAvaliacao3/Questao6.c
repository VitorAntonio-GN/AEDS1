/*
6. Implemente um programa com Funcionario (ID, nome, salário, data). Leia
N registros e salve em funcionarios.txt.
*/

struct Funcionario{
    int id;
    char nome[51];
    float salario;
    char data[11];
};

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    struct Funcionario* funcionariosPtr = NULL;
    FILE* fileFuncionarios = NULL;
    char enderecoFileFuncionarios[] = "funcionarios.txt";
    int numFuncionarios = 0;

    printf("Quantos funcionarios? ");
    scanf("%d", &numFuncionarios);

    fileFuncionarios = fopen(enderecoFileFuncionarios, "w");

    if(fileFuncionarios == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    funcionariosPtr = (struct Funcionario*) realloc(funcionariosPtr, numFuncionarios * sizeof(struct Funcionario));

    for(int i = 0; i < numFuncionarios; i++)
    {
        printf("Id; Nome; Salario; Data\n");
        scanf("%d%s%f%s", &funcionariosPtr[i].id, &funcionariosPtr[i].nome, &funcionariosPtr[i].salario, &funcionariosPtr[i].data);
        fprintf(fileFuncionarios, "%d %s %0.2f %s\n", funcionariosPtr[i].id, funcionariosPtr[i].nome, funcionariosPtr[i].salario, funcionariosPtr[i].data);
    }
   
    fclose(fileFuncionarios);
    free(funcionariosPtr);
    return 0;
}