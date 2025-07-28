#include <stdio.h>

int main()
{
    int age = 0;
    int true = 1;

    printf("Digite: \"2025\" para quebrar o loop, não inclua as aspas\n\n");

    while(true)
    {
        printf("Digite a idade do atleta: ");
        scanf("%d", &age);

        if(age >= 5 && age <= 7)
        {
            printf("Intantil A\n\n");
        }
        else if(age >= 8 && age <= 10)
        {
            printf("Infantil B\n\n");
        }
        else if(age >= 11 && age <= 13)
        {
            printf("Juvenil A\n\n");
        }
        else if(age >= 14 && age <= 17)
        {
            printf("Juvenil B\n\n");
        }
        else if(age >= 18 && age <= 25)
        {
            printf("Sênior\n\n");
        }
        else if(age == 2025)
        {
            break;
        }
        else
        {
            printf("Atleta sem categoria\n\n");
        }
    }

    printf("\nO programa parou\n\n");

    return 0;
}