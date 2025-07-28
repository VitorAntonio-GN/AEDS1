#include <stdio.h>

//18.Verificação de sequência crescente com for: leia uma sequência de N números e diga se ela está em ordem crescente.
int main(void)
{
    //variaveis
    int n = 0;
    int e_crescente= 1;
    double num = 0;
    double oldnum = 0;

    //valor n
    printf("\nDigite n: ");
    scanf("%d", &n);

    printf("\n");

    //loop da lista
    for(int i = 0; i < n; i++)
    {
        printf("Digite o valor do %do numero: ", (i + 1));
        scanf("%lf", &num);

        if(i == 0)
        {
            //passa o numero e ele vira o anterior
            oldnum = num;
        }
        else if(num < oldnum)
        {
            //nao é crescente e vira anterior
            e_crescente = 0;
            oldnum = num;
        }
        else
        {
            //vira anterior
            oldnum = num;
        }
    }

    //se e crescente ou nao
    if(e_crescente == 1)
    {
        printf("\nA lista e crescente\n\n");
    }
    else
    {
        printf("\nA lista nao e crescente\n\n");
    }

    return 0;
}