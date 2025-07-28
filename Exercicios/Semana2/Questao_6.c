#include <stdio.h>

int main()
{
    // variaveis do salario
    double salario_hora = 0;
    double h_trabalhadas = 0;
    double h_extras = 0;
    
    // bonus do salario
    double dependentes = 0;

    // inputs
    printf("Digite o salário do empregado por hora trabalhada: ");
    scanf("%lf", &salario_hora);
    printf("Digite o número de horas trabalhadas: ");
    scanf("%lf", &h_trabalhadas);
    printf("Digite o número de horas extras trabalhadas: ");
    scanf("%lf", &h_extras);
    printf("Digite o número de dependentes: ");
    scanf("%lf", &dependentes);

    // cálculo do salário
    double salario = (salario_hora * (h_trabalhadas + h_extras)) + (dependentes * 128.0);
    double salario_imposto = 0;

    
    // IR no salário
    if(salario <= 1434.59)
    {
        salario_imposto = salario;
    }
    else if(salario <= 2150.00)
    {
        salario_imposto = (salario * 0.925);
    }
    else if(salario <= 2866.70)
    {
        salario_imposto = (salario * 0.85);
    }
    else if(salario <= 3582.00)
    {
        salario_imposto = (salario * 0.775);
    }
    else
    {
        salario_imposto = (salario * 0.725);
    }


    // beneficio depós IR
    if(salario_imposto <= 500.0)
    {
        salario_imposto += 180.0;
    }
    else if(salario_imposto <= 1000.0)
    {
        salario_imposto += 120.0;
    }
    else
    {
        salario_imposto += 100.0;
    }


    // salário com IR e bônus do IR
    printf("O salário final do empregado é R$%lf", salario_imposto);
}