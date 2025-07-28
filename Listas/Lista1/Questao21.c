#include <stdio.h>

/*21.Encontrar todos os pares de números cuja soma seja igual a um valor X com for:
peça um número X e mostre todos os pares (a, b) com 1 ≤ a ≤ b ≤ X tal que a + b = X.*/
int main(void)
{
    //variaveis
    unsigned long long int a = 0;
    unsigned long long int b = 0;
    unsigned long long int aux = 0;

    //input
    printf("Digite a: ");
    scanf("%llu", &a);
    printf("Digite b: ");
    scanf("%llu", &b);

    //troca de valores
    aux = a;
    a = 1;
    b += aux - 1;

    //se b for 0, a sera integro a seria ex: 8 + 0 = 8 (o que nao enquadra no 1 <= a <= b <= x)
    while(b != 0)
    {
        if(a >= b)
        {
            printf("\n1 <= %llu <= %llu <= %llu", a, b, (unsigned long long int)(a + b));
        }
        a++;
        b--;
    }

    printf("\n\nO programa foi feito de forma que um par ex: 4,1 aparecesse apenas uma vez, \ne nao reaparecesse como 1,4");

    return 0;    
}