/*
14.Faça um programa que leia uma string de até 100 caracteres e grave em
saida.txt quantos caracteres e quantas vogais ela possui.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    FILE* fileSaida = NULL;
    char enderecoFileSaida[] = "saida.txt";
    int sumCaracteres = 0;
    int sumVogais = 0;
    char stringLida[102] = {};
    char vogais[] = "aeiou";

    fgets(stringLida, 102, stdin);
    stringLida[strlen(stringLida) - 1] = '\0'; //retira o \n
    sumCaracteres = strlen(stringLida); //atualiza o total

    for(int i = 0; i < strlen(stringLida); i++) //em cada char
    {
        for(int j = 0; j < 5; j++) //verifica se e vogal e soma
        {
            if(tolower(stringLida[i]) == vogais[j])
            {
                sumVogais++;
            }
        }

        if(stringLida[i] == ' ') //se for espaco retira o caractere
        {
            sumCaracteres--;
        }
    }
    
    //Obs: se fosse pegar as consoantes, ela é o total de caracteres - vogais.

    fileSaida = fopen(enderecoFileSaida, "w");

    if(fileSaida == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    fprintf(fileSaida, "Caracteres: %d\nVogais: %d\n", sumCaracteres, sumVogais);
    fclose(fileSaida);
    return 0;
}