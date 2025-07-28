/*
8. Escreva um programa que aloque dinamicamente um vetor de Aluno, leia
os dados de alunos.txt e imprima os nomes dos alunos em ordem reversa.
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
    FILE* fileAlunos = NULL;
    char enderecoFileAlunos[] = "alunos.txt";   
    int sumAlunos = 1; //garante a existencia do 1o aluno 
    int indexAlunos = sumAlunos - 1; //formata index

    fileAlunos = fopen(enderecoFileAlunos, "r");
    alunosPtr = realloc(alunosPtr, sumAlunos * sizeof(struct Aluno));

    while((fscanf(fileAlunos, "%d %s %f\n", &alunosPtr[indexAlunos].matricula, &alunosPtr[indexAlunos].nome, &alunosPtr[indexAlunos].nota)) != EOF)
    {
        printf("%d %s %0.2f\n", alunosPtr[indexAlunos].matricula, alunosPtr[indexAlunos].nome, alunosPtr[indexAlunos].nota);

        sumAlunos++; //passa para proximo aluno
        indexAlunos++;  //passa para proximo index

        alunosPtr = realloc(alunosPtr, sumAlunos * sizeof(struct Aluno));
    }

    sumAlunos--; //remove o proximo aluno
    indexAlunos--; //remove o proximo index

    alunosPtr = realloc(alunosPtr, sumAlunos * sizeof(struct Aluno));

    free(alunosPtr);
    fclose(fileAlunos);
    return 0;
}