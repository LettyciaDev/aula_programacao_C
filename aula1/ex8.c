#include <stdio.h>

#define QTD_LINHAS 10
#define QTD_COLUNAS 10

int main() {
    int mat[QTD_LINHAS][QTD_COLUNAS];
    int lin, col;

    printf("Digite a quantidade de linhas: ");
    scanf("&d", lin);

    printf("Digite a quantidade de colunas: ");
    scanf("&d", col);

    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++) {
            printf("Digite o valor para mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);

        }
    }
    int resultado = ehDiagonal(int mat, int lin, int col);
}

int ehDiagonal(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++) {
            if (mat[i][j] != 0) {
                if (i != j) {
                    return 0;
                }
            }
        }
    }
}