#include <stdio.h>

//15.Números primos entre dois valores com for: peça dois números e exiba todos os primos entre eles.
int main(void)
{
    //numeros
    unsigned long long int n1 = 0;
    unsigned long long int n2 = 0;
    unsigned long long int aux = 0;
    int countdiv = 0;
    int countprime = 0;

    //input
    printf("Digite o n1: ");
    scanf("%llu", &n1);

    printf("Digite o n2: ");
    scanf("%llu", &n2);

    //se estiver invertido
    if(n1 > n2)
    {
        aux = n1;
        n1 = n2;
        n2 = aux;
    }

    //para cada numero entre n1 e n2
    //aux = menor
    aux = n1;
    for(aux; aux <= n2; aux++)
    {  
        //para cada divisor
        for(int i = 1; i <= aux; i++)
        {
            if(aux % i == 0)
            {
                countdiv++;
            }
        }

        if(countdiv == 2)
        {
            printf("\n%llu e primo", aux);
            countprime++;
        }

        countdiv = 0;
    }

    printf("\n\nExistem %d primos entre %llu e %llu\n", countprime, n1, n2);

    return 0;
}