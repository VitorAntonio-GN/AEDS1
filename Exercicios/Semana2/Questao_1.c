#include <stdio.h>

int main()
{
    int user = 0;
    printf("Usuário: ");
    scanf("%d", &user);

    int passw = 0;
    printf("Senha: ");
    scanf("%d", &passw);

    if(user == 675483 && passw == 67453)
    {
        printf("Usuário Válido");
    }
    else if(user == 145627 && passw == 89234)
    {
        printf("Usuário Válido");
    }
    else if(user == 98782 && passw == 89132)
    {
        printf("Usuário Válido");
    }
    else
    {
        printf("Usuário Inválido");
    }
}