#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void gerarDigitosCpf(char cpf[], char doisDigitosCpf[3])
{
    /*variaveis*/
    int mod = 0;

    /*10° digito*/
    // -> busca até o 9° digito e multiplica por pesos
    int soma10 = 0;
    for(int i = 0, j = 10; j > 1; i++, j--)
    {
        soma10 += (cpf[i] - 48) * j;
    }

    mod = soma10 % 11;
    int resultado10 = (mod < 2 ? 0 : 11 - mod) % 10;

    /*11° digito*/
    // -> acrescenta o 10° digito com seu peso
    int soma11 = soma10 + (resultado10 * 2);
    for(int i = 0; i < 9; i++)
    {
        soma11 += cpf[i] - 48;
    }

    mod = soma11 % 11;
    int resultado11 = (mod < 2 ? 0 : 11 - mod) % 10;

    /*armazrna ultimos digitos*/
    doisDigitosCpf[0] = resultado10 + 48;
    doisDigitosCpf[1] = resultado11 + 48;
    doisDigitosCpf[2] = '\0';

    /*fim*/
    return;
}

void limparCpf(char cpf[])
{
    /*variaveis*/
    int indexCpf = strlen(cpf) - 1;
    int controleFormatacao = 0;

    /*verificador*/
    // -> busca por '-' e '.', se achar acrescente ao controle e ignora
    // -> busca por \0, se achar indica o fim e causa break
    for(int i = 0; i <= indexCpf; i++)
    {
        // -> abre um for para procurar quanto '-' e '.' existem entre os char
        if(cpf[i + controleFormatacao] == '-' || cpf[i + controleFormatacao] == '.')
        {
            for(int j = i + controleFormatacao; 1; j++)
            {
                if(cpf[j] == '-' || cpf[j] == '.') controleFormatacao++;
                else break;
            }
        }

        // -> busca \0 e encerra a string se achar
        else if(cpf[i + controleFormatacao] == '\0')
        {
            cpf[i] = '\0';
            break;
        }

        // -> atribui valor ao formatado
        cpf[i] = cpf[i + controleFormatacao];
    }

    /*fim*/
    return;
}

int validarCpf(char cpf[])
{
    /*variaveis*/
    char doisDigitosCpf[3] = {};

    /*calcular digitos*/
    gerarDigitosCpf(cpf, doisDigitosCpf);

    /*verificar se são o que deveria*/
    int isValido = ((cpf[9] == doisDigitosCpf[0]) && (cpf[10] == doisDigitosCpf[1])) ? 1 : 0;

    /*fim*/
    return isValido;
}

int main(void)
{
    /*variáveis*/
    int opcaoEscolhida = 0;
    char cpf[16] = {};
    char doisDigitosCpf[3] = {};

    do
    {
        /*inputs*/
        do
        {
            printf("---\nO que deseja fazer?\n1. Validar CPF\n2. Gerar dígitos do CPF\n3. Sair\n\n>> ");
            scanf("%d", &opcaoEscolhida);
        } while(opcaoEscolhida < 1 || opcaoEscolhida > 3);
        
        /*inputs necessários*/
        if(opcaoEscolhida == 1) printf("\nDigite o CPF: \n\n>> ");
        else if(opcaoEscolhida == 2) printf("\nDigite os primeiros 9 digitos do CPF:\n\n>> ");
        scanf("%s", cpf);

        /*verificação opção*/
        switch(opcaoEscolhida)
        {
            case 1:
                limparCpf(cpf);

                if(validarCpf(cpf) == 1) printf("\n>> O CPF e valido\n\n");
                else printf("\n>> O CPF nao e valido\n\n");

                break;
            
            case 2:
                limparCpf(cpf);
                gerarDigitosCpf(cpf, doisDigitosCpf);

                printf("\n>> Digitos gerados: %s\n\n", doisDigitosCpf);

                break;

            case 3:
                return 2;

            default:
                printf("\nError\n\n");

                return 1;
        }

    } while(1);
    
    return 0;
}