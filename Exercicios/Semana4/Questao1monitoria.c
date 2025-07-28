#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUANT 30

int main() {
    int vetor[QUANT][2] = {};
    int quantDistinto = QUANT;
    int contarMaisRepetido = 0;
    int contarMenosRepetido = 0;

    srand(time(NULL)); // <<<--- Usando a Lib de randomizar para não ter que colocar cada número de forma manual

    for (int i = 0; i < QUANT; i++) {

        // printf("[%d] Digite o valor: ", i + 1);  // <| Original para pegar os Números do usuário
        // scanf("%d", &vetor[i][0]);               // <|

        vetor[i][0] = rand() % 30 + 1; //<--- Randomizando para não ter que colocar cada número de forma manual
        vetor[i][1] = 1;
    }

    for (int i = 0; i < QUANT; i++) {
        int aux[2] = {};
        for (int j = i + 1; j < QUANT; j++) {
            if ((vetor[j][1] != 0 && vetor[i][0] > vetor[j][0]) || vetor[i][1] == 0) {
                aux[0] = vetor[i][0];
                aux[1] = vetor[i][1];

                vetor[i][0] = vetor[j][0];
                vetor[i][1] = vetor[j][1];

                vetor[j][0] = aux[0];
                vetor[j][1] = aux[1];

            } else if ((vetor[i][1] != 0 && vetor[j][1] != 0) && vetor[i][0] == vetor[j][0]) {
                vetor[i][1] += vetor[j][1];
                vetor[j][1] = 0;
                quantDistinto--;
            }
        }

        // Atualiza o maisRepetido e menosRepetido usando vetor[i][1]
        if (vetor[i][1] != 0) {
            if (vetor[i][1] > contarMaisRepetido) {
                contarMaisRepetido = vetor[i][1];
            }
            if (contarMenosRepetido == 0 || vetor[i][1] < contarMenosRepetido) {
                contarMenosRepetido = vetor[i][1];
            }
        }
    }

    printf("\n\n\nLista de numeros distintos digitados (ORDENADO):\n");
    for (int i = 0; i < quantDistinto; i++) {
        if (vetor[i][1] == contarMaisRepetido) {
            printf("\n<+> ");
        } else if (vetor[i][1] == contarMenosRepetido) {
            printf("\n>-< ");
        } else {
            printf("\n    ");
        }
        printf("[%03d]: %d", vetor[i][0], vetor[i][1]);
        if (vetor[i][1] == 2)
            printf(" <-------- [=2]");
        else if (vetor[i][1] > 2)
            printf(" <<[+2]");
    }

    printf("\n\nNúmeros com MAIOR frequência (%d ocorrência%s):\n|", contarMaisRepetido, contarMaisRepetido == 1 ? "" : "s");
    for (int i = 0; i < quantDistinto; i++) {
        if (vetor[i][1] == contarMaisRepetido) printf(" %03d |", vetor[i][0]);
    }

    printf("\nNúmeros com MENOR frequência (%d ocorrência%s):\n|", contarMenosRepetido, contarMenosRepetido == 1 ? "" : "s");
    for (int i = 0; i < quantDistinto; i++) {
        if (vetor[i][1] == contarMenosRepetido) printf(" %03d |", vetor[i][0]);
    }
    printf("\n");

    return 0;
}