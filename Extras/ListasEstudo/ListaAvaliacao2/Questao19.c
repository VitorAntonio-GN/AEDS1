/*
19.Implemente uma função que receba uma string e uma letra, e conte
quantas vezes essa letra aparece, ignorando
maiúsculas/minúsculas.
*/

#include <stdio.h>

int contarRepetido(char letra, char string[])
{
    if(letra >= 'A' && letra <= 'Z')
    {
        letra += 32;
    }

    int counterRepetido = 0;
    int i = 0;
    while(string[i] != '\n')
    {
        if(string[i] == letra || string[i] == (letra - 32))
        {
            counterRepetido++;
        }

        i++;
    }

    return counterRepetido;
}

int main(void)
{
    char letra = 0;
    char string[52] = {0};
    int counterRepetido = 0;

    fgets(string, 52, stdin);
    scanf("%c", &letra);

    counterRepetido = contarRepetido(letra, string);

    printf("%d letras %c estao na string\n", counterRepetido, letra);

    return 0;
}