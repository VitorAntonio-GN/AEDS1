#include <stdio.h>

//20.Gerador de primos consecutivos com while: peça ao usuário quantos primos deseja ver e mostre os primeiros N primos.
int main(void)
{
    //pega o numero
    unsigned long long int n = 0;
    printf("Quantos primos voce quer ver? ");
    scanf("%llu", &n);
    printf("\n");

    //contador de div
    int countdiv = 0;

    //loop while
    //para cada menor numero, por mais que verifique o contador, ele vai rodando os numeros, e comeca em 1
    unsigned long long int i = 1;
    while(n != 0)
    {
        //para cada divisor de 1 ate o menor numero
        //vai de 1 ate i
        //pega todos os divisores e os conta se == 0 o resto
        unsigned long long int j = 1;
        while(j <= i)
        {
            if(i % j == 0)
            {
                countdiv++;
            }

            j++;
        }

        //se primo printa e depois reseta o contador
        if(countdiv == 2)
        {
            printf("%llu -> ", i);

            //diminui o contador de primos
            n--;
        }

        countdiv = 0;

        //aumenta o menor numero
        i++;
    }

    printf("fim\n\n");

    return 0;
}