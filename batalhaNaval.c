#include <stdio.h>

// Definições de constantes
#define TAMANHO 10
#define NAVIO 3
#define AGUA 0

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int i, j;

    // Inicializa todas as posições com 0 (representando água)
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posiciona navio 1 - horizontal (linha 1, colunas 2 a 4)
    tabuleiro[0][1] = NAVIO;
    tabuleiro[0][2] = NAVIO;
    tabuleiro[0][3] = NAVIO;

    // Posiciona navio 2 - vertical (coluna 6, linhas 5 a 7)
    tabuleiro[4][5] = NAVIO;
    tabuleiro[5][5] = NAVIO;
    tabuleiro[6][5] = NAVIO;

    // Posiciona navio 3 - diagonal principal (de [2][2] até [4][4])
    tabuleiro[2][2] = NAVIO;
    tabuleiro[3][3] = NAVIO;
    tabuleiro[4][4] = NAVIO;

    // Posiciona navio 4 - diagonal secundária (de [1][7] até [3][5])
    tabuleiro[1][7] = NAVIO;
    tabuleiro[2][6] = NAVIO;
    tabuleiro[3][5] = NAVIO;

    // Imprime identificação das colunas (A a J)
    printf("   ");
    for (i = 0; i < TAMANHO; i++) {
        printf(" %c", 'A' + i);
    }
    printf("\n");

    // Imprime o tabuleiro com identificação das linhas (1 a 10)
    for (i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1);  // Número da linha
        for (j = 0; j < TAMANHO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
