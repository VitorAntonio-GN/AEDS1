/*
2. Verificação de palíndromo
Crie um programa que leia uma palavra e verifique se ela é um
palíndromo, ou seja, se pode ser lida da mesma forma de trás para frente.
Desconsidere letras maiúsculas/minúsculas.
Exemplo: "arara" → palíndromo | "casa" → não é palíndromo
*/

//letra maiscula
//espaço?

#include <stdio.h>
#include <string.h>

int main(void)
{
    //input
    char palavra[301];
    printf("Digite uma palavra com ate 300 caracteres: ");
    fgets(palavra, 301, stdin);

    //contar o input
    //-1 pelo 0 (contagem); -1 pelo '\0' (contagem) (tecnicamente perde 1 do range) <- cola ate eu apender
    int indexmax = strlen(palavra) - 1 - 1;
    int verificacoes = strlen(palavra) / 2;
    int ispalindromo = 1;

    //verificar
    //se é maiúsculo o char ou se tem e espaço <- atualização do código
    for(int j = 0; j < indexmax; j++)
    {
        if(palavra[j] >= 65 && palavra[j] <= 90)
        {
            palavra[j] += 32;
        }
        else if(palavra[j] == ' ')
        {
            printf("Digite uma palavra sem espaco\n");
            return 1;
        }
    }

    //para cada char
    for(int i = 0; i <= verificacoes; i++, indexmax--)
    {
        if(palavra[i] != palavra[indexmax])
        {
            ispalindromo = 0;
            break;
        }
    }

    //printar
    if(ispalindromo == 0)
    {
        printf("Nao e palindromo\n");
    }
    else
    {
        printf("E palindromo\n");
    }

    return 0;
}