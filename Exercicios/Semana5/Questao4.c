/*
4. Verificador de número primo
Implemente uma função chamada ehPrimo(int n) que retorna 1 se n for
primo e 0 caso contrário.
No main(), leia um número inteiro positivo do usuário e utilize a função
para informar se ele é primo ou não.
*/

#include <stdio.h>

int ehPrimo(int n)
{
    //contador de divisoes
    int counterdiv = 0;

    //para cada divisor ate o numero
    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            counterdiv++;
        }
    }

    //se tiver 2 divisores e primo -> senao, nao e
    if(counterdiv == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    //input
    int numero = 0;
    printf("Digite um número: ");
    scanf("%d", &numero);

    //função
    int isprimo = ehPrimo(numero);

    //verificação e print
    if(isprimo == 1)
    {
        printf("O numero %d e primo\n", numero);
    }
    else
    {
        printf("O numero %d nao e primo\n", numero);
    }

    return 0;
}