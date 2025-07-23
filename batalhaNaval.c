#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0}; // Tabuleiro 10x10 inicializado com 0 (água)

    // Coordenadas iniciais dos navios
    int linha_horizontal = 2, coluna_horizontal = 4; // Navio horizontal em (2,4)
    int linha_vertical = 5, coluna_vertical = 1;     // Navio vertical em (5,1)

    int i;

    // Posiciona navio horizontal (tamanho 3)
    for (i = 0; i < 3; i++) {
        if (coluna_horizontal + i < 10 &&
            tabuleiro[linha_horizontal][coluna_horizontal + i] == 0) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
        }
    }

    // Posiciona navio vertical (tamanho 3)
    for (i = 0; i < 3; i++) {
        if (linha_vertical + i < 10 &&
            tabuleiro[linha_vertical + i][coluna_vertical] == 0) {
            tabuleiro[linha_vertical + i][coluna_vertical] = 3;
        }
    }

    // Exibe cabeçalho com letras das colunas (A até J)
    printf("   "); // Espaço inicial para alinhar com números das linhas
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    // Exibe o tabuleiro com numeração das linhas (1 até 10)
    for (int linha = 0; linha < 10; linha++) {
        printf("%2d ", linha + 1); // Mostra o número da linha
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
