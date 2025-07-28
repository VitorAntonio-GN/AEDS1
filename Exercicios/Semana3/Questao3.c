#include <stdio.h>

int main()
{
    double num1 = 0;
    double num2 = 0;
    double result = 0;

    int operation = 0;
    do
    {
        printf("Escolha a opção:\n1 - Soma de 2 números.\n2 - Diferença entre 2 números (maior pelo menor).\n3 - Produto entre 2 números.\n4 - Divisão entre 2 números (o denominador não pode ser zero)\n");
        printf("Obs: Na divisâo, o 1° número é o numerador, o 2° número é o denominador\n\n");
        printf("-----------------------------------\n\n");

        printf("Opção escolhida: "); 
        scanf("%d", &operation);

        if(operation < 1 || operation > 4)
        {
            printf("\n-----------------------------------\n\n");
            printf("ERRO: Opção inválida\n");
            printf("\n-----------------------------------\n\n");
        }
    } while(operation < 1 || operation > 4 );

    printf("\n-----------------------------------\n\n");

    printf("Número 1: ");
    scanf("%lf", &num1);
    printf("Número 2: ");
    scanf("%lf", &num2);

    //soma
    if(operation == 1)
    {
        result = num1 + num2;
    }

    //diferença maior menor
    else if(operation == 2)
    {
        if(num1 >= num2)
        {
            result = num1 - num2;
        }
        else
        {
            result = num2 - num1;
        }
    }

    //produto
    else if(operation == 3)
    {
        result = num1 * num2;
    }

    //divisao
    else
    {
        if(num2 == 0)
        {
            printf("\n-----------------------------------\n");

            printf("\nDenominador inválido\n\n");
            return 1;
        }

        result = num1 / num2;
    }

    //resultado
    printf("\n-----------------------------------\n");

    printf("\nResultado: %.2lf\n\n", result);

    return 0;
}