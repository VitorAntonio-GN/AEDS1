/*
Questão 4 – Relatório de Vendas Semanais (10 pontos)
Implemente um programa que simule o registro de vendas diárias de uma loja
durante 4 semanas (28 dias).
• Use um laço externo para representar as semanas (1 a 4);
• Use um laço interno para representar os 7 dias de cada semana;
• Leia o valor das vendas de cada dia, quando valor de entrada de uma
venda for 0 isso indica que não tem mais vendas naquele dia;
• Calcule e mostre:
1. O total de vendas de cada semana;
2. A média de vendas semanal;
3. A maior venda registrada no mês e em que dia/semana ocorreu;
4. A menor venda registrada no mês e em que dia/semana ocorreu;
5. O total geral vendido no mês.
*/

#include <stdio.h>

int main(void)
{
    //por venda
    float vendas = 0;
    //por venda dia
    float sum_vendas = 0;
    //por venda semana
    float sum_vendas_semana = 0;
    //por venda total
    float sum_vendas_total = 0;
    //maior e menor
    float bvendas = 0;
    float lvendas = 0;
    int bsem = 1;
    int lsem = 1;
    int bday = 1;
    int lday = 1;
    
    //OBS: Na questão não citou nada sobre dia útil, então a média contará até os dias que nao venderam nada
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            while(1)
            {
                printf("O valor da venda no %d° dia: ", (j + 1));
                scanf("%f", &vendas);

                if(vendas <= 0)
                {
                    break;
                }

                sum_vendas += vendas;
                sum_vendas_semana += vendas;
                sum_vendas_total += vendas;
            }

            if(i == 0 && j == 0)
            {
                bvendas = sum_vendas;
                lvendas = sum_vendas;
            }
            else if(sum_vendas > bvendas)
            {
                bvendas = sum_vendas;
                bsem = (i + 1);
                bday = (i * 7) + (j + 1);
            }
            else if(sum_vendas < lvendas)
            {
                lvendas = sum_vendas;
                lsem = (i + 1);
                lday = (i * 7) + (j + 1);
            }

            sum_vendas = 0;
        }

        printf("\nTotal de vendas da %d° semana: R$%f", (i + 1), sum_vendas_semana);
        printf("\nMedia de vendas semanal da %d° semana: R$%f\n\n", (i + 1), (sum_vendas_semana / 7));
            
        sum_vendas_semana = 0;
    }

    printf("A maior venda, de R$ %f, aconteceu na semana %d°, dia %d", bvendas, bsem, bday);
    printf("\nA menor venda, de R$ %f, aconteceu na semana %d°, dia %d", lvendas, lsem, lday);

    printf("\nO total geral vendido no mes e: R$ %f", sum_vendas_total);
    printf("\nA media do total geral por semana e: R$ %f", (sum_vendas_total / 4));
    printf("\nA media do total geral por dia e: R$ %f", (sum_vendas_total / 28));
    printf("\n\n");
    return 0;
}