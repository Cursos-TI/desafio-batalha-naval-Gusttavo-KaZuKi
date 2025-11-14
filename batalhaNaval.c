#include <stdio.h>

int main() {
    // Representar tabuleiro usando matriz 10x10, considerando 0 como a água
    int tabuleiro[10][10] = {0};

    // Definir tamanho dos navios
    int tamanho_navio = 3;

    // Identificação das linhas e colunas do tabuleiro
    char linhas[10]  = {'A','B','C','D','E','F','G','H','I','J'};
    int colunas[10]  = {1,2,3,4,5,6,7,8,9,10};

    // Vetores representando navios horizontal e vertical
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // Coordenadas iniciais dos navios
    int linha_h = 2, coluna_h = 4; // navio horizontal iniciando em (C,5)
    int linha_v = 5, coluna_v = 7; // navio vertical iniciando em (F,8)

    // Posicionar navio horizontal (3 para direita)
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_h][coluna_h + i] = 3;
    }

    // Posicionar navio vertical (3 para baixo)
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_v + i][coluna_v] = 3;
    }

    // Exibir tabuleiro na tela com linhas (A-J) e colunas (1-10)
    printf("\n===== BATALHA NAVAL — TABULEIRO 10x10 =====\n\n");

    // Imprime cabeçalho das colunas
    printf("   "); // espaçamento inicial antes dos números das colunas
    for (int c = 0; c < 10; c++) {
        // imprime colunas alinhadas com 3 espaços por célula
        printf(" %2d", colunas[c]);
    }
    printf("\n");

    // Imprime cada linha com sua letra e os valores do tabuleiro
    for (int linha = 0; linha < 10; linha++) {
        // imprime a letra da linha seguida de um separador
        printf(" %c ", linhas[linha]);
        for (int coluna = 0; coluna < 10; coluna++) {
            printf(" %d ", tabuleiro[linha][coluna]);  // 0 = água, 3 = parte do navio
        }
        printf("\n");
    }

    printf("\nSeus navios foram posicionados!\n");

    return 0;
}
