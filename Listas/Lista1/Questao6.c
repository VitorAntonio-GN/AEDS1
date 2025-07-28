#include <stdio.h>

//Fibonacci com while: leia N e mostre os N primeiros termos da sequência de Fibonacci.
//1,1,2,3,5,8,13,21,34,55
int main(void)
{
    unsigned int n = 0;
    printf("\nDigite o n: ");
    scanf("%u", &n);

    unsigned long long int v1 = 1;
    unsigned long long int v2 = 0;
    unsigned long long int aux = v1;

    printf("\n");

    //para cada vez
    unsigned int i = 0;
    while(i < n)
    {
        printf("%llu -> ", v1);

        aux = v1;
        v1 = v1 + v2;
        v2 = aux;

        i++;
    }

    printf("fim\n");

    printf("\n");

    return 0;
}