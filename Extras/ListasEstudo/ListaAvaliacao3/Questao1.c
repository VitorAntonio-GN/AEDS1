/*
1. Crie uma struct Aluno com nome, matrícula e nota. Alocar dinamicamente
um vetor de Aluno, preencher com N registros e salvar em alunos.txt.
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
    struct Aluno* alunosPtr = NULL;
    int numAlunos = 0;
    char enderecoFileAlunos[] = "alunos.txt"; 
    FILE* fileAlunos = NULL;

    printf("Quantos alunos ira alocar?\n");
    scanf("%d", &numAlunos);

    alunosPtr = (struct Aluno*) realloc(alunosPtr, numAlunos * sizeof(struct Aluno));

    for(int i = 0; i < numAlunos; i++)
    {
        printf("Nome; Matricula; Nota\n");
        scanf("%s%d%f", &alunosPtr[i].nome, &alunosPtr[i].matricula, &alunosPtr[i].nota);
    }

    fileAlunos = fopen(enderecoFileAlunos, "w");

    if(fileAlunos == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    for(int i = 0; i < numAlunos; i++)
    {
        fprintf(fileAlunos, "%d %s %0.2f\n", alunosPtr[i].matricula, alunosPtr[i].nome, alunosPtr[i].nota);
    }

    fclose(fileAlunos);
    free(alunosPtr);  
    return 0;
}