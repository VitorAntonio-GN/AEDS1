#include <stdio.h>

int main()
{
    int n = 0;
    int par = 0;
    int impar = 0;

    printf("Digite o %d° número: ", ((par + impar) + 1));
    scanf("%d", &n);

    if (n % 2 == 0)
    {
        par++;
    }
    else
    {
        impar++;
    }
    
    printf("Digite o %d° número: ", ((par + impar) + 1));
    scanf("%d", &n);

    if (n % 2 == 0)
    {
        par++;
    }
    else
    {
        impar++;
    }

    printf("Digite o %d° número: ", ((par + impar) + 1));
    scanf("%d", &n);

    if (n % 2 == 0)
    {
        par++;
    }
    else
    {
        impar++;
    }

    printf("Digite o %d° número: ", ((par + impar) + 1));
    scanf("%d", &n);

    if (n % 2 == 0)
    {
        par++;
    }
    else
    {
        impar++;
    }

    printf("Digite o %d° número: ", ((par + impar) + 1));
    scanf("%d", &n);

    if (n % 2 == 0)
    {
        par++;
    }
    else
    {
        impar++;
    }

    printf("Você digitou %d números pares e %d números ímpares", par, impar);
}