#include <stdio.h>

/*25.Verificação de números amigos com for: dois números são amigos se a soma dos divisores de um é igual ao outro 
e vice-versa (ex: 220 e 284). Verifique se dois números são amigos.*/
int main(void)
{
    //variaveis
    unsigned long long int n1 = 0;
    unsigned long long int n2 = 0;

    //inputs
    printf("Digite o primeiro valor: ");
    scanf("%llu", &n1);
    printf("Digite o segundo valor: ");
    scanf("%llu", &n2);

    //variaveis dos divisores
    unsigned long long int sumn1 = 0;
    unsigned long long int sumn2 = 0;

    //para cada divisor de n1
    for(int i = 1; i <= n1; i++)
    {
        if(n1 % i == 0)
        {
            sumn1 += i;
        }
    }

    //para cada divisor de n2
    for(int j = 1; j <= n2; j++)
    {
        if(n2 % j == 0)
        {
            sumn2 += j;
        }
    }

    //se e amigo ou nao
    if(sumn1 == sumn2)
    {
        printf("\nOs numeros %llu e %llu sao amigos e a soma de seus divisores e: %llu\n\n", n1, n2, sumn1);
    }
    else
    {
        printf("\nOs numeros %llu e %llu nao sao amigos e a soma de seus divisores e, respectivamente: %llu e %llu\n\n", n1, n2, sumn1, sumn2);
    }

    return 0;
}