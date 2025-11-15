#include <stdio.h>

int main() {
    // Representar tabuleiro usando matriz 10x10, considerando 0 como água
    int tabuleiro[10][10] = {0};
    int tamanho_navio = 3;

    // Identificação das linhas e colunas do tabuleiro
    char linhas[10]  = {'A','B','C','D','E','F','G','H','I','J'};
    int colunas[10]  = {1,2,3,4,5,6,7,8,9,10};

    // Vetores representando navios horizontal e vertical
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3]   = {3, 3, 3};

    // Posições iniciais dos navios horizontal e vertical
    int linha_h = 2, coluna_h = 4;
    int linha_v = 5, coluna_v = 7;

    // Coloca navio horizontal
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
    }

    // Coloca navio vertical
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
    }

    // Coloca navio diagonal 1
    int linha_d1 = 0, coluna_d1 = 0;
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_d1 + i][coluna_d1 + i] = 3;
    }

    // Coloca navio diagonal 2
    int linha_d2 = 0, coluna_d2 = 9;
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_d2 + i][coluna_d2 - i] = 3;
    }

    // Habilidades
    int cone[5][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    int cruz[5][5] = {
        {0,0,7,0,0},
        {7,7,7,7,7},
        {0,0,7,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    int octaedro[5][5] = {
        {0,0,5,0,0},
        {0,5,5,5,0},
        {0,0,5,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    // ORIGEM DAS HABILIDADES (CENTRO)
    int ox_cone = 2, oy_cone = 2;
    int ox_cruz = 3, oy_cruz = 5;
    int ox_octa = 7, oy_octa = 2;

    // Coloca CONE
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] != 0) {
                int lx = ox_cone + i - 2;
                int cy = oy_cone + j - 2;
                if (lx >= 0 && lx < 10 && cy >= 0 && cy < 10)
                    tabuleiro[lx][cy] = cone[i][j];
            }
        }
    }

    // Coloca CRUZ
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] != 0) {
                int lx = ox_cruz + i - 2;
                int cy = oy_cruz + j - 2;
                if (lx >= 0 && lx < 10 && cy >= 0 && cy < 10)
                    tabuleiro[lx][cy] = cruz[i][j];
            }
        }
    }

    // Coloca OCTAEDRO
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] != 0) {
                int lx = ox_octa + i - 2;
                int cy = oy_octa + j - 2;
                if (lx >= 0 && lx < 10 && cy >= 0 && cy < 10)
                    tabuleiro[lx][cy] = octaedro[i][j];
            }
        }
    }

    // EXIBIÇÃO
    printf("\n===== BATALHA NAVAL — TABULEIRO 10x10 =====\n\n");

    printf("   ");
    for (int c = 0; c < 10; c++) printf("%2d ", colunas[c]);
    printf("\n");

    for (int l = 0; l < 10; l++) {
        printf("%c  ", linhas[l]);
        for (int c = 0; c < 10; c++) {
            printf("%2d ", tabuleiro[l][c]);
        }
        printf("\n");
    }

    printf("\nLegenda:\n");
    printf("0 = água\n");
    printf("3 = navio\n");
    printf("1 = cone\n");
    printf("7 = cruz\n");
    printf("5 = octaedro\n\n");

    return 0;
}
