#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5
#define TAM_HABILIDADE 5

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para posicionar navios em posições fixas
void posicionarNavios(int tabuleiro[TAM][TAM]) {
    // Navio horizontal
    tabuleiro[1][1] = NAVIO;
    tabuleiro[1][2] = NAVIO;
    tabuleiro[1][3] = NAVIO;

    // Navio vertical
    tabuleiro[3][5] = NAVIO;
    tabuleiro[4][5] = NAVIO;
    tabuleiro[5][5] = NAVIO;

    // Diagonal descendente
    tabuleiro[6][6] = NAVIO;
    tabuleiro[7][7] = NAVIO;
    tabuleiro[8][8] = NAVIO;

    // Diagonal ascendente
    tabuleiro[6][2] = NAVIO;
    tabuleiro[7][1] = NAVIO;
    tabuleiro[8][0] = NAVIO;
}

// Função para gerar matriz com forma de cone (aponta para baixo)
void gerarCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Código que forma o cone expandindo-se verticalmente para baixo
            if (j >= (2 - i) && j <= (2 + i)) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para gerar matriz em formato de cruz
void gerarCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Marca a linha central e a coluna central
            if (i == 2 || j == 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para gerar matriz com forma de octaedro (losango)
void gerarOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Soma das distâncias de linha e coluna em relação ao centro deve ser <= 2
            if (abs(i - 2) + abs(j - 2) <= 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para aplicar matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origemLinha - 2 + i;
                int coluna = origemColuna - 2 + j;

                // Aplica apenas se estiver dentro dos limites e não sobrepor navio
                if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM && tabuleiro[linha][coluna] == AGUA) {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }
}

// Função para exibir o tabuleiro com cabeçalhos
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    // Cabeçalho das colunas
    printf("   ");
    for (int i = 0; i < TAM; i++) {
        printf(" %c", 'A' + i);
    }
    printf("\n");

    // Linhas numeradas + conteúdo do tabuleiro
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == AGUA) printf(" ~");
            else if (tabuleiro[i][j] == NAVIO) printf(" N");
            else if (tabuleiro[i][j] == HABILIDADE) printf(" *");
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    // Inicializa tabuleiro e posiciona navios
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    // Gera matrizes de habilidade
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplica habilidades no tabuleiro com ponto de origem
    aplicarHabilidade(tabuleiro, cone, 2, 2);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
