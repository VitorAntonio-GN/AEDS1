#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    /*variaveis*/
    char mensagem[81] = {};
    char chaveMensagem[101] = {};
    int tamMensagem = 0;
    int tamChave = 0;

    /*inputs*/
    printf("Mensagem de ate 80 caracteres:\n>> ");
    fgets(mensagem, 81, stdin);
    mensagem[strcspn(mensagem, "\n")] = '\0';

    printf("\nChave de ate 100 caracteres:\n>> ");
    fgets(chaveMensagem, 101, stdin);
    chaveMensagem[strcspn(chaveMensagem, "\n")] = '\0';

    /*atualiza variavel*/
    // -> ex: 17 -> 16 o index, porém como vai-se usar no mod, não é necessário
    tamChave = strlen(chaveMensagem);
    tamMensagem = strlen(mensagem);

    /*criptografia e exibição*/
    // -> adiciona com base na extensão da chave
    printf("\nResultado criptografado: ");
    for(int i = 0; i < tamMensagem; i++)
    {
        mensagem[i] = mensagem[i] ^ chaveMensagem[i % tamChave];
        printf(" %d", (int)mensagem[i]);
    }
    
    /*descriptografia e exibição*/
    printf("\nResultado descriptografado: ");
    for(int i = 0; i < tamMensagem; i++)
    {
        mensagem[i] = mensagem[i] ^ chaveMensagem[i % tamChave];
        printf("%c", mensagem[i]);
    }

    /*estética*/
    printf("\n\n");

    /*fim*/
    return 0;
}