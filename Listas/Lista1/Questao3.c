#include <stdio.h>
//Contar quantos primos existem até N com while: leia um número N e mostre quantos números primos existem de 1 até N.

int main(void)
{
    //pega o int para contagem (número primo == natural)
    unsigned long long int num = 0;
    printf("\nDigite o numero primo: ");
    scanf("%llu", &num);

    //contador de divisoes
    int countdiv = 0;
    //contador de primos
    int countprime = 0;

    //para cada menor numero ate n (começa um 1 pois 0 nas é primo)
    //i <= num significa que em algum momento ele vai ser num e rodar o codigo sendo ele
    printf("\n");
    for(int i = 1; i <= num; i++)
    {
        //para cada divisor para verificar o menor numero
        //se for 0 da indeterminaçao, e 1 de inicio
        // j <= i, em algum momento j sera i e rodara o codigo sendo ele
        for(int j = 1; j <= i; j++)
        {
            if(i % j == 0)
            {
                countdiv++;
            }
        }

        if(countdiv == 2)
        {
            countprime++;
            printf("O numero %d e primo\n", i);
        }

        countdiv = 0;
    }

    printf("\nExistem %d numeros primos entre 1 e %llu\n", countprime, num);

    return 0;
}