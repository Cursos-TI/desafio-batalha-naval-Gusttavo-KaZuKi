#include <stdio.h>

#define TAM 10

int main() {
    int tab[TAM][TAM] = {0};

    // Matrizes de habilidades EXATAMENTE como você enviou
    // 3 linhas × 5 colunas

    // CONE = número 1 no tabuleiro
    int cone[3][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1}
    };

    // CRUZ = número 3 no tabuleiro
    int cruz[3][5] = {
        {0,0,3,0,0},
        {3,3,3,3,3},
        {0,0,3,0,0}
    };

    // OCTAEDRO = número 5 no tabuleiro
    int octaedro[3][5] = {
        {0,0,5,0,0},
        {0,5,5,5,0},
        {0,0,5,0,0}
    };

    // Mesmas posições anteriores
    int origem_cone_l = 0, origem_cone_c = 2;   // CONE
    int origem_cruz_l = 2, origem_cruz_c = 6;   // CRUZ
    int origem_octa_l = 5, origem_octa_c = 2;   // OCTAEDRO

    int r, c;

    // --- Aplicar CONE ---
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 5; c++) {
            if (cone[r][c] != 0) {
                int dl = origem_cone_l + r;
                int dc = origem_cone_c + c - 2; // centralizar (coluna do meio = origem)
                if (dl >= 0 && dl < TAM && dc >= 0 && dc < TAM)
                    tab[dl][dc] = 1;
            }
        }
    }

    // --- Aplicar CRUZ ---
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 5; c++) {
            if (cruz[r][c] != 0) {
                int dl = origem_cruz_l + r;
                int dc = origem_cruz_c + c - 2;
                if (dl >= 0 && dl < TAM && dc >= 0 && dc < TAM)
                    tab[dl][dc] = 3;
            }
        }
    }

    // --- Aplicar OCTAEDRO ---
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 5; c++) {
            if (octaedro[r][c] != 0) {
                int dl = origem_octa_l + r;
                int dc = origem_octa_c + c - 2;
                if (dl >= 0 && dl < TAM && dc >= 0 && dc < TAM)
                    tab[dl][dc] = 5;
            }
        }
    }

    // --- Imprimir TABULEIRO ---
    printf("     ");
    for (int i = 1; i <= 10; i++)
        printf("%2d ", i);
    printf("\n");

    char letras[] = "ABCDEFGHIJ";

    for (int i = 0; i < TAM; i++) {
        printf("%c   ", letras[i]);
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tab[i][j]);
        }
        printf("\n");
    }

    return 0;
}
