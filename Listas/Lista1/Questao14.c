#include <stdio.h>
#include <math.h>

//14.Verificar se número é palíndromo com while: leia um número inteiro e informe se ele é palíndromo (ex: 121, 1331, 2002).
int main(void)
{
    //pega o numero
    unsigned long long int n = 0;
    printf("\nDigite o numero: ");
    scanf("%llu", &n);
    printf("\n");

    //pega a quantidade de casas decimais
    unsigned long long int copy_n = n;
    int countdh = 0;
    while(copy_n >= 1)
    {
        copy_n /= 10;
        countdh++;
    }

    //variaveis para comparacao
    unsigned long long int n_right = 0;
    unsigned long long int n_left = 0;
    int ispalindrome = 1;

    //loop que pega o da direita e o da esquerda vai atualizando
    int i = 0;
    while(i < (countdh / 2))
    {
        //pega o da direita pela divisao do i e depois pelo mod
        n_right = (n / (unsigned long long int)pow(10, i)) % 10;

        //pega um n grande da esquerda pela divisao do i e depois pelo mod
        n_left =  (n / (unsigned long long int)pow(10, (countdh - 1 - i))) % 10;

        if(n_right != n_left)
        {
            ispalindrome = 0;
            break;
        }

        i++;
    }

    if(ispalindrome == 0)
    {
        printf("Nao e palindromo\n\n");
    }
    else
    {
        printf("E palindromo\n\n");
    }

    return 0;
}