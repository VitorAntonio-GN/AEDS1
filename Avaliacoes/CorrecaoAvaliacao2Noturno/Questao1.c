/*
1. Cadeia de Operações Matemáticas com Funções Temáticas: “Missão
Espacial” (7,5 pontos)

Você está programando o computador de bordo de uma nave espacial, que
precisa fazer cálculos específicos antes de um salto interestelar.
Tarefa: Leia dois números inteiros e encadeie as funções abaixo, cada uma
representando uma etapa do processo:
1. calcular_combustivel() – retorna a soma dos quadrados dos dois
números.
2. verificar_estabilidade() – subtrai o dobro do menor número do valor
anterior.
3. ajustar_trajetoria() – multiplica o resultado pela diferença entre os dois
números originais.
4. calcular_peso_salto() – calcula a média aritmética entre os dois números e
divide o valor anterior por essa média.
5. codificar_dados() – soma os dígitos do número obtido anteriormente.
6. finalizar_lançamento() – imprime o resultado final com uma frase: "Salto
autorizado com código [resultado]".
Use funções separadas e encadeadas. A main() chama apenas a primeira
(calcular_combustivel()), e cada função chama a próxima.
*/

#include <stdio.h>
#include <math.h>

void finalizar_lancamento(int resultado_anterior)
{
    printf("Salto autorizado com código %d\n", resultado_anterior);
}

void codificar_dados(float resultado_anterior)
{
    float copia_anterior = resultado_anterior;

    while((copia_anterior - floor(copia_anterior)) != 0)
    {
        copia_anterior *= 10;
    }

    int somaDigitos = 0;
    int int_copia_anterior = copia_anterior;

    while(int_copia_anterior != 0)
    {
        somaDigitos += int_copia_anterior % 10;
        int_copia_anterior /= 10;
    }

    finalizar_lancamento(somaDigitos);
}

void calcular_peso_salto(int a, int b, float resultado_anterior)
{
    float media = ((a + b) / 2.0);

    resultado_anterior /= media;

    codificar_dados(resultado_anterior);
}

void ajustar_trajetoria(int a, int b, float resultado_anterior)
{
    resultado_anterior *= (a - b);

    calcular_peso_salto(a, b, resultado_anterior);
}

void verificar_estabilidade(int a, int b, float resultado_anterior)
{
    if(a < b)
    {
        resultado_anterior -= (2 * a);
    }
    else
    {
        resultado_anterior -= (2 * b);
    }

    ajustar_trajetoria(a, b, resultado_anterior);
}

void calcular_combustivel(int a, int b)
{
    float resultado = (a * a) + (b * b);

    verificar_estabilidade(a, b, resultado);
}

int main(void)
{
    int a = 0, b = 0;

    scanf("%d %d", &a, &b);

    calcular_combustivel(a, b);

    return 0;
}