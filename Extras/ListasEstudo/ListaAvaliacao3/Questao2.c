/*
2. Leia alunos.txt e grave em um novo arquivo aprovados.txt apenas os
alunos com nota maior ou igual a 6.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno{
    char nome[51];
    int matricula;
    float nota;
};

int main(void)
{
    struct Aluno alunos[1] = {};
    FILE* fileAlunos = NULL;
    char enderecoFileAlunos[] = "alunos.txt";
    char enderecoFileAprovados[] = "aprovados.txt";
    FILE* fileAprovados = NULL;

    fileAlunos = fopen(enderecoFileAlunos, "r");
    fileAprovados = fopen(enderecoFileAprovados, "w");

    if(fileAlunos == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    while((fscanf(fileAlunos, "%d %s %f\n", &alunos->matricula, &alunos->nome, &alunos->nota)) != EOF)
    {
        printf("%d %s %0.2f\n", alunos->matricula, alunos->nome, alunos->nota);

        if(alunos->nota >= 6)
        {
            fprintf(fileAprovados, "%d %s %0.2f\n", alunos->matricula, alunos->nome, alunos->nota);
        }
    }

    fclose(fileAlunos);
    return 0;
}