#include <stdio.h>

int main()
{
    //variables for scope
    float one_fifteen = 0;
    float sixteen_thirty = 0;
    float thirtyone_fortyfive = 0;
    float fortysix_sixty = 0;
    float sixtyone_plus = 0;
    float total = 0;

    int quantity = 0;
    printf("Quantas idades deseja digitar? ");
    scanf("%d", &quantity);

    int i = 0;
    while(i < quantity)
    {
        //doesnt need scope
        int age = 0;
        printf("Digite a idade da pessoa %d: ", (i + 1));
        scanf("%d", &age);

        if(age >= 1 && age <= 15)
        {
            one_fifteen++;
        }
        else if(age >= 16 && age <= 30)
        {
            sixteen_thirty++;
        }
        else if(age >= 31 && age <= 45)
        {
            thirtyone_fortyfive++;
        }
        else if(age >= 46 && age <= 60)
        {
            fortysix_sixty++;
        }
        else if(age >= 61)
        {
            sixtyone_plus++;
        }
        else
        {
            printf("Idade inválida, não será contada\n");
        }

        i++;
    }

    total = one_fifteen + sixteen_thirty + thirtyone_fortyfive + fortysix_sixty + sixtyone_plus;

    printf("1 a 15 anos - %.2f%%\n", ((one_fifteen / total) * 100));
        
    printf("16 a 30 anos - %.2f%%\n", ((sixteen_thirty / total) * 100));
    
    printf("31 a 45 anos - %.2f%%\n", ((thirtyone_fortyfive / total) * 100));
    
    printf("46 a 60 anos - %.2f%%\n", ((fortysix_sixty / total) * 100));
    
    printf("Mais de 60 anos - %.2f%%\n", ((sixtyone_plus / total) * 100));

    return 0;
}