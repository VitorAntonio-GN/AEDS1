#include <stdio.h>

//12.Segundo maior número com for: peça N números (N ≥ 2) e descubra o segundo maior entre eles.
int main(void)
{  
    //varriaveis
    int n = 0;
    double num = 0;
    double biggest = 0;
    double scbiggest = 0;

    printf("Digite n: ");
    scanf("%d", &n);

    //retorna se nao for pelo menos 2
    if(n < 2)
    {
        printf("\nDigite pelo menos 2 numeros\n\n");
        return 1;
    }

    //1o
    printf("Digite o 1o numero: ");
    scanf("%lf", &biggest);

    //2o
    printf("Digite o 2o numero: ");
    scanf("%lf", &num);

    if(num > biggest)
    {
        scbiggest = biggest;
        biggest = num;
    }
    else
    {
        scbiggest = num;
    }

    //loop for
    for(int i = 2; i < n; i++)
    {
        printf("Digite o %do numero: ", (i + 1));
        scanf("%lf", &num);

        if(num > biggest)
        {
            scbiggest = biggest;
            biggest = num;
        }
        else
        {
            scbiggest = num;
        }
    }

    printf("\n\nMaior: %.3lf\n2o maior: %.3lf\n", biggest, scbiggest);

    return 0;
}