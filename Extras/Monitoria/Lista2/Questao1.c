#include <stdio.h>

int main(void)
{
    /*variaveis*/
    int opcaoEscolhidaLanche = 0;
    int opcaoEscolhidaAcompanhamento = 0;
    int opcaoEscolhidaBebida = 0;
    float total = 0;

    /*inputs*/
    printf("Escolha seu lanche:\n1. Hambúrguer simples - R$10,00\n2. Cheeseburguer - R$12,00\n3. X-Bacon - R$14,00\n4. X-Tudo - R$16,00\n5. Veggie Burger - R$13,00\n");
    printf(">> Digite o número do lanche: ");
    do{
        scanf("%d", &opcaoEscolhidaLanche);
    } while(opcaoEscolhidaLanche < 1 || opcaoEscolhidaLanche > 5);
    printf("\n");

    printf("Escolha o acompanhamento:\n1. Batata frita - R$6,00\n2. Onion rings - R$7,00\n3. Nuggets - R$8,00\n");
    printf(">> Digite o número do acompanhamento: ");
    do{
        scanf("%d", &opcaoEscolhidaAcompanhamento);
    } while(opcaoEscolhidaAcompanhamento < 1 || opcaoEscolhidaAcompanhamento > 3);
    printf("\n");

    printf("Escolha a bebida:\n1. Refrigerante lata - R$5,00\n2. Suco natural - R$6,00\n3. Água mineral - R$3,00\n4. Milkshake - R$8,00\n");
    printf(">> Digite o número da bebida: ");
    do{
        scanf("%d", &opcaoEscolhidaBebida);
    } while(opcaoEscolhidaBebida < 1 || opcaoEscolhidaBebida > 4);
    printf("\n");

    /*verificações*/
    printf("Comanda:\n- Lanche escolhido: ");
    
    if(opcaoEscolhidaLanche == 1)
    {
        printf("Hambúrguer simples (R$10,00)\n");
        total += 10;
    }
    else if(opcaoEscolhidaLanche == 2)
    {
        printf("Cheeseburguer (R$12,00)\n");
       total += 12; 
    }
    else if(opcaoEscolhidaLanche == 3)
    {
        printf("X-Bacon (R$14,00)\n");
        total += 14;
    }
    else if(opcaoEscolhidaLanche == 4)
    {
        printf("X-Tudo (R$16,00)\n");
        total += 16;
    }
    else
    {
        printf("Veggie Burger (R$13,00)\n");
        total += 13;
    }

    printf("- Acompanhamento escolhido: ");
    if(opcaoEscolhidaAcompanhamento == 1)
    {
        printf("Batata frita (R$6,00)\n");
        total += 6;
    }
    else if(opcaoEscolhidaAcompanhamento == 2)
    {
        printf("Onion rings (R$7,00)\n");
        total += 7;
    }
    else
    {
        printf("Nuggets (R$8,00)\n");
        total += 8;
    }

    printf("- Bebida escolhida: ");
    if(opcaoEscolhidaBebida == 1)
    {
        printf("Refrigerante lata (R$5,00)\n");
        total += 5;
    }
    else if(opcaoEscolhidaBebida == 2)
    {
        printf("Suco natural (R$6,00)\n");
        total += 6;
    }
    else if(opcaoEscolhidaBebida == 3)
    {
        printf("Água mineral (R$3,00)\n");
        total += 3;
    }
    else
    {
        printf("Milkshake (R$8,00)\n");
        total += 8;
    }

    /*total*/
    printf("\nTotal a pagar: R$%0.2f", total);

    return 0;
}