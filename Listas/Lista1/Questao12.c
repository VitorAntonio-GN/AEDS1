#include <stdio.h>

//12.Segundo maior número com for: peça N números (N ≥ 2) e descubra o segundo maior entre eles.
int main(void)
{
    //numero
    int n = 0;
    printf("Digite n: ");
    scanf("%d", &n);

    //sai se nao for pelo menos 2
    if(n < 2)
    {
        printf("\nDigite pelo menos 2 numeros\n");
        return 1;
    }

    //numero, maior e 2o maior
    double num = 0;
    double biggest = 0;
    double secbiggest = 0;

    printf("\n");
    
    //loop
    for(int i = 0; i < n; i++)
    {
        printf("Digite o %do numero: ", (i + 1));
        scanf("%lf", &num);

        if(num > biggest)
        {
            secbiggest = biggest;
            biggest = num;
        }
        else if(num > secbiggest)
        {
            secbiggest = num;
        }
        else if(i == 0)
        {
            biggest = num;
        }
        else if(i == 1)
        {
            secbiggest = num;
        }
    }

    printf("\nMaior: %.3lf\n2o maior: %.3lf\n", biggest, secbiggest);

    return 0;
}