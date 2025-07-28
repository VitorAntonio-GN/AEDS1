#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void exibirAssentos(int matriz[16][6])
{
    /*imprime os assentos*/
    printf("____________________________________.    .\n");
    for(int i = 0; i < 16; i++)
    {
        printf("|=|");

        for(int j = 0; j < 6; j++)
        {
            if(matriz[i][j] == '\0') printf(" [%02d]", (90 - (i * 6) + (j + 1)));
            else printf(" [--]");
        }
        
        if(i == 0) printf(" |=|\\  /|\n");
        else printf(" |=|    |\n");
    }

    /*fim*/
    return;
}

void reservarAssento(int RA, int assentosReservadosRA[96][2], int* indexControle, int matriz[16][6])
{
    /*variaveis*/
    int isReservado = 0;
    int assentoDesejado = 0;
    int i = 0;
    int j = 0;

    /*busca se já reservou*/
    for(int i = 0; i < 96; i++)
    {
        if(RA == assentosReservadosRA[i][0])
        {
            isReservado = 1;
            break;
        }
    }

    /*verifica se o RA já reservou*/
    if(isReservado == 1)
    {
        printf("\nVoce ja reservou um assento\n");
        return;
    }

    /*loop para assentos*/
    do
    {
        /*input*/
        printf("Digite o número do assento (1-96):\n>> ");
        scanf("%d", &assentoDesejado);

        /*pega linha e coluna para verificação*/
        i = (((assentoDesejado / 6) - 15) * (-1));
        j = (assentoDesejado % 6) - 1;

        /*verifica se o assento já está reservado*/
        if(matriz[i][j] != '\0')
        {
            printf("\nAssento ja reservado\n");
            continue;
        }

        /*reserva o assento*/
        matriz[i][j] = RA;
        assentosReservadosRA[*indexControle][0] = RA;
        assentosReservadosRA[*indexControle][1] = assentoDesejado;

        /*fim*/
        return;        
    } while(1);
}

void editarAssento(int RA, int assentosReservadosRA[96][2], int matriz[16][6])
{
    /*variaveis*/
    int isReservado = 0;
    int indexReservado = 0;
    int assentoDesejado = 0;
    int i = 0;
    int j = 0;
    int iAntigo = 0;
    int jAntigo = 0;

    /*busca se já reservou*/
    for(int i = 0; i < 96; i++)
    {
        if(RA == assentosReservadosRA[i][0])
        {
            isReservado = 1;
            indexReservado = i;
            break;
        }
    }

    /*verifica se o RA não reservou*/
    if(isReservado == 0)
    {
        printf("\nVoce nao reservou um assento\n");
        return;
    }

    /*loop do assento*/
    do
    {
        /*input*/
        printf("\nSeu assento reservado: [%02d]\n\nDigite o novo numero do assento (1-96):\n>> ", assentosReservadosRA[indexReservado][1]);
        scanf("%d", &assentoDesejado);

        /*pega linha e coluna para verificação*/
        i = (((assentoDesejado / 6) - 15) * (-1));
        j = (assentoDesejado % 6) - 1;

        /*verifica se o assento já está reservado*/
        if(matriz[i][j] != '\0')
        {
            printf("\nAssento ja reservado\n");
            continue;
        }

        /*pega a linha e coluna já reservada*/
        iAntigo = (((assentosReservadosRA[indexReservado][1] / 6) - 15) * (-1));
        jAntigo = (assentosReservadosRA[indexReservado][1] % 6) - 1;

        /*limpa a reserva atual*/
        matriz[iAntigo][jAntigo] = '\0';

        /*reserva o assento*/
        matriz[i][j] = RA;
        assentosReservadosRA[indexReservado][1] = assentoDesejado;

        /*fim*/
        return;  

    } while(1);  
}

int main(void)
{
    /*variaveis*/
    int opcaoEscolhida = 0;
    int matrizAssentos[16][6] = {};
    int assentosReservadosRA[96][2] = {};
    int indexControleAssentosReservadosRA = 0;
    int RA = 0;
    int isSair = 0;

    /*loop da interface*/
    do
    {
        /*input RA*/
        printf("Bem-vindo ao Sistema de Reservas do Cinema!\nDigite seu RA: ");
        scanf("%d", &RA);

        if(RA == 0)
        {
            printf("\nVoce saiu do sistema\n");
            break;
        }

        /*loop interface*/
        do
        {
            /*verifica se é para sair*/
            if(isSair == 1)
            {
                isSair = 0;
                break;
            }

            /*input interface*/
            do
            {
                printf("\n------------------------------------------\nMenu:\n1. Ver mapa de assentos\n2. Reservar assento\n3. Editar/Cancelar reserva\n4. Sair\n\n>> ");
                scanf("%d", &opcaoEscolhida);
            } while(opcaoEscolhida < 1 || opcaoEscolhida > 4);

            /*vericações*/
            switch(opcaoEscolhida)
            {
                case 1: exibirAssentos(matrizAssentos);
                        break;

                case 2: reservarAssento(RA, assentosReservadosRA, &indexControleAssentosReservadosRA, matrizAssentos);
                        break;

                case 3: editarAssento(RA, assentosReservadosRA, matrizAssentos);
                        break;
                
                case 4: isSair = 1;
                        break;

                default:printf("\nError\n");
                        return 1;
            }
        } while(1);
    } while(1);

    /*fim*/
    return 0;
}