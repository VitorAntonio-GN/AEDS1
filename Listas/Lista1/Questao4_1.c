#include <stdio.h>
//Múltiplos de 3 e 5 entre dois valores com for: leia dois valores inteiros A e B e exiba todos os números entre A e B que sejam múltiplos de 3 ou 5.

int main(void)
{
    int a = 0;
    printf("\nDigite o valor de a: ");
    scanf("%d", &a);
    
    int b = 0;
    printf("\nDigite o valor de b: ");
    scanf("%d", &b);

    if(a > b)
    {
        int aux = a;
        a = b;
        b = aux;
    }

    printf("\n");

    //cada numero de a até b
    for(a; a <= b; a++)
    {
        if(a % 3 == 0 || a % 5 == 0)
        {
            printf("O numero %d e divisivel por 3 ou 5\n", a);
        }
    }

    printf("\n");

    return 0;
}
