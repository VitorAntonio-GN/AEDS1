#include <stdio.h>

int main()
{
    int idade = 0;
    printf("Digite a idade do atleta: ");
    scanf("%d", &idade);

    if(idade >= 5 && idade <= 7)
    {
        printf("Este é um atleta Infantil A");
    }
    else if(idade >= 8 && idade <= 10)
    {
        printf("Este é um atleta Infantil B");  
    }
    else if(idade >= 11 && idade <= 13)
    {
        printf("Este é um atleta Juvenil A");
    }
    else if(idade >= 14 && idade <= 17)
    {
        printf("Este é um atleta Juvenil B");
    }
    else if(idade >= 18 && idade <= 25)
    {
        printf("Este é um atleta Sênior");
    }
    else
    {
        printf("Fora do alcance");
    }

}