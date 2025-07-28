#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    /*variaveis*/
    char mensagem[2][51] = {};
    char chaveMensagem[51] = {};
    char pontuacoesMensagem[] = " .,;:?!()—-'\"[]";
    int isPontuacao = 0;

    /*inputs da mensagem e chave*/
    printf("Mensagem de ate 50 caracteres:\n>> ");
    fgets(mensagem[0], 51, stdin);
    mensagem[0][strcspn(mensagem[0], "\n")] = '\0';

    printf("\n\nChave:\n>> ");
    fgets(chaveMensagem, 51, stdin);
    chaveMensagem[strcspn(chaveMensagem, "\n")] = '\0';

    /*verificação se de mesmo tamanho*/
    if(strlen(mensagem[0]) < strlen(chaveMensagem))
    {
        printf("\n\nDigite uma chave menor\n");
        return 1;
    }
    else if(strlen(mensagem[0]) > strlen(chaveMensagem))
    {
        printf("\n\nDigite uma chave maior\n");
        return 1;
    }

    /*criptografia*/
    // -> antes converte minúsculas em maiúsculas
    // -> mantem espaçoes e pontuações
    for(int i = 0; i < strlen(mensagem[0]); i++)
    {
        /*ignora as pontuações*/
        // -> verifica se é pontuação, e se for pula a iteração
        for(int j = 0; j < strlen(pontuacoesMensagem); j++)
        {
            if(mensagem[0][i] == pontuacoesMensagem[j])
            {
                isPontuacao = 1;
                mensagem[1][i] = 1;
                break;
            }
        }

        if(isPontuacao == 1)
        {
            isPontuacao = 0;
            continue;
        }

        /*converte para maiúscula*/
        if(mensagem[0][i] >= 'a' && mensagem[0][i] <= 'z') mensagem[0][i] -= 32;
        else mensagem[1][i] = 2;

        /*criptografa*/
        mensagem[0][i] += chaveMensagem[i];
    }
    printf("\n\nResultado: %s", mensagem[0]);

    /*descriptografar*/
    for(int i = 0; i < strlen(mensagem[0]); i++)
    {
        /*ignora as pontuações*/
        if(mensagem[1][i] == 1) continue;

        /*criptografa*/
        mensagem[0][i] -= chaveMensagem[i];

        /*converte para minúscula se não for maiúscula*/
        if((mensagem[0][i] >= 'A' && mensagem[0][i] <= 'Z') && mensagem[1][i] != 2) mensagem[0][i] += 32;
    }
    printf("\nDescriptografado: %s\n\n", mensagem[0]);

    return 0;
}