/*
1. Contar vogais e consoantes
Escreva um programa em C que leia uma string (palavra ou frase) digitada
pelo usuário e conte quantas vogais e quantas consoantes ela possui.
Ignore espaços e considere apenas letras do alfabeto.
Exemplo: entrada: "Exemplo de Texto" → saída: Vogais: 6 | Consoantes: 8
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    //vetores
    char vogais[11] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    char texto[301];

    //input vetor
    printf("Digite um texto de ate 300 caracteres: ");
    fgets(texto, 301, stdin);

    //teste
    //printf("%d", strlen(texto));
    //resultado -> Com o input "Bom" ele printou 4, ou seja: 'B' 'o' 'm' e '\0' (4)

    //contadores
    int countconsoantes = 0;
    int countvogais = 0;
    int isvogal = 0;

    //loop for para pega indices, um fixo (vetor de texto <- até strlen?) e outro para comparar (vetor de vogais <- até index 9)
    //(strlen(texto) - 1), pega a quantidade de termos, - 1 pelo index 0, e < pelo '\0'
    //para cada char
    for(int i = 0; i < (strlen(texto) - 1); i++)
    {
        //para cada vogal
        for(int j = 0; j < 10; j++)
        {
            //Se -> for vogal -> Também se -> for uma letra (vogal entra direto no primeiro)
            if(texto[i] == vogais[j])
            {
                countvogais++;
                isvogal = 1;
                break;
            }
        }

        //Se -> nao for vogal mas estiver no intervalo 
        if(isvogal == 0 && ((texto[i] >= 'a' && texto[i] <= 'z') || (texto[i] >= 'A' && texto[i] <= 'Z')))
        {
            countconsoantes++;
        }
        
        //reseta ser vogal
        isvogal = 0;
    }

    //imprimir
    printf("Vogais: %d\nConsoantes: %d\n", countvogais, countconsoantes);

    return 0;
}