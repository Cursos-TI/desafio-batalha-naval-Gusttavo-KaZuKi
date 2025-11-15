#include <stdio.h>

int main() {
    // Representar tabuleiro usando matriz 10x10, considerando 0 como água
    int tabuleiro[10][10] = {0};

    // Tamanho fixo do navio
    int tamanho_navio = 3;

    // Identificação das linhas e colunas do tabuleiro
    char linhas[10]  = {'A','B','C','D','E','F','G','H','I','J'};
    int colunas[10]  = {1,2,3,4,5,6,7,8,9,10};

    // Vetores representando navios horizontal e vertical
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // Escolha das coordenadas iniciais
    int linha_h = 2, coluna_h = 4; // navio horizontal
    int linha_v = 5, coluna_v = 7; // navio vertical

    // Posicionar navio horizontal (para a direita)
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
    }

    // Posicionar navio vertical (para baixo)
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
    }

    // Navio diagonal 1
    int linha_d1 = 0, coluna_d1 = 0;
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_d1 + i][coluna_d1 + i] = 3;
    }

    // Navio diagonal 2
    int linha_d2 = 0, coluna_d2 = 9;
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_d2 + i][coluna_d2 - i] = 3;
    }

    // Exibir tabuleiro na tela
    printf("\n===== BATALHA NAVAL — TABULEIRO 10x10 =====\n\n");

    // Mostrar numeração das colunas (1 a 10)
    printf("   ");
    for (int c = 0; c < 10; c++) {
        printf("%2d ", colunas[c]);
    }
    printf("\n");

    // Mostrar linhas e conteúdo do tabuleiro
    for (int l = 0; l < 10; l++) {
        printf("%c  ", linhas[l]); // letra A–J
        for (int c = 0; c < 10; c++) {
            printf("%2d ", tabuleiro[l][c]); // alinhado
        }
        printf("\n");
    }

    printf("\nNavios posicionados com sucesso!\n");

    return 0;
}
