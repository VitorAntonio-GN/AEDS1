#include <stdio.h>

//Menu de operações matemáticas com do while: crie um menu para realizar soma, subtração, multiplicação ou divisão entre dois números até o usuário escolher "sair".
int main(void)
{
    //variaveis
    int op = 0;
    double n1 = 0;
    double n2 = 0;

    do{
        do{
            //painel
            printf("\n1 - Soma\n2 - Subtracao\n3 - Multiplicacao\n4 - Divisao\n5 - Sair\n\n");

            //pegar a operacao
            printf("Selecione a operacao: ");
            scanf("%d", &op);

        } while(op > 5 || op < 1);

        //se a opcao for sair
        if(op == 5)
        {
            break;
        }

        //caso nao, automaticamente ira pegar os numeros
        printf("\n");
        printf("Digite o 1o numero: ");
        scanf("%lf", &n1);
        printf("Digite o 2o numero: ");
        scanf("%lf", &n2);
        printf("\n");

        //realiza a operacao
        if(op == 1)
        {
            printf("A soma entre %lf e %lf e aproximadamente: %.2lf\n", n1, n2, (n1 + n2));
        }
        else if(op == 2)
        {
            printf("A subtracao entre %lf e %lf e aproximadamente: %.2lf\n", n1, n2, (n1 - n2));
        }
        else if(op == 3)
        {
            printf("A multiplicacao entre %lf e %lf e aproximadamente: %.2lf\n", n1, n2, (n1 * n2));
        }
        else if(op == 4)
        {
            printf("A divisao entre %lf e %lf e aproximadamente: %.2lf\n", n1, n2, (n1 / n2));
        }

    } while(op != 5);

    return 0;
}