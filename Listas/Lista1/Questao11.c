#include <stdio.h>

//11.Maior e menor entre 10 números com while: leia 10 números e informe o maior e o menor deles.
int main(void)
{
    //numero
    double num = 0;

    //maior e menor
    double bnum = 0;
    double lnum = 0;

    //loop e contador
    int i = 0;
    while(i < 10)
    {
        //pega o n
        printf("Digite o %do numero: ", (i + 1));
        scanf("%lf", &num);

        //ve se e maior ou menor
        if(num > bnum)
        {
            bnum = num;
        }
        else if(num < lnum)
        {
            lnum = num;
        }

        //passa para o proximo n
        i++;
    }

    printf("\nMaior: %.3lf\nMenor: %.3lf\n\n", bnum, lnum);

    return 0;
}