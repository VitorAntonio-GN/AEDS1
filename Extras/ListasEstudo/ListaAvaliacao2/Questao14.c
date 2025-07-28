/*
14.Receba uma string contendo números separados por vírgulas (ex:
"12,45,78"). Extraia os números e calcule a média.
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void) //<- armazenar -48 (números normais)
{
    //vetor e variaveis
    char vetorNumeros[501] = {0};
    int vetorNumero[500] = {0};
    int counterIndexVetorNumero = 0;
    int counterNumeros = 0;
    int sumNumeros = 0;
    int tamanhoVetor = 0;
    float sumMediaNumeros = 0;

    //input
    fgets(vetorNumeros, 501, stdin);

    //pega o tamanho do vetor
    tamanhoVetor = strlen(vetorNumeros);

    //for olhando as virgulas e o \n do fgets
    for(int i = 0; i < tamanhoVetor; i++)
    {
        if(vetorNumeros[i] != ',' && vetorNumeros[i] != '\n')
        {
            vetorNumero[counterIndexVetorNumero] = vetorNumeros[i] - 48;
            counterIndexVetorNumero++;
        }
        else
        {
            for(int j = 0; j < counterIndexVetorNumero; j++)//<- for pegando o numero antes da virgula e multiplicando na base 10 de acordo com o contador, por fim somando
            {
                sumNumeros += vetorNumero[j] * pow(10, counterIndexVetorNumero - 1 - j);
            }

            sumMediaNumeros += sumNumeros;//<- soma o valor a soma da media
            counterNumeros++;//<- acrescente 1 ao contador

            counterIndexVetorNumero = 0;
            sumNumeros = 0;
        }
    }
    
    //imprime a media
    printf("A media e: %.2f\n", sumMediaNumeros/counterNumeros);
}