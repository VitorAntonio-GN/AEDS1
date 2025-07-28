#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//16.Jogo da adivinhação com do while: o programa gera um número aleatório entre 1 e 100 e o usuário tenta adivinhar até acertar, recebendo dicas.
int main(void)
{
    //aleatorio e numero
    srand(time(0));
    int random = rand() % 100 + 1;
    int n = 0;

    //loop com contador
    int i = 0;
    do{
        printf("\nTente adivinhar o valor entre 1 a 100: ");
        scanf("%d", &n);

        if(n < random)
        {
            printf("Muito baixo\n\n---\n");
        }
        else if(n > random)
        {
            printf("Muito alto\n\n---\n");
        }
        else
        {
            printf("\nAcertou! em %d tentativas\n", (i + 1));
        }

        i++;
    } while(n != random);

    return 0;
}