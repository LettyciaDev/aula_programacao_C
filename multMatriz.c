#include <stdio.h>

#define QTD_LINHAS 10
#define QTD_COLUNAS 10

void multiplicarMatrizes(int matrizA[QTD_LINHAS][QTD_COLUNAS], int linA, int colA, 
                         int matrizB[QTD_LINHAS][QTD_COLUNAS], int linB, int colB, 
                         int matrizMult[QTD_LINHAS][QTD_COLUNAS]) {
    // Verifica se a multiplicação é possível
    if (colA != linB) {
        printf("Multiplicação não é possível. O número de colunas de matrizA deve ser igual ao número de linhas de matrizB.\n");
        return;
    }

    // Inicializa a matriz resultado com zeros
    for (int i = 0; i < linA; i++) {
        for (int j = 0; j < colB; j++) {
            matrizMult[i][j] = 0;
        }
    }

    // Calcula o produto das matrizes
    for (int i = 0; i < linA; i++) {
        for (int j = 0; j < colB; j++) {
            for (int k = 0; k < colA; k++) {
                matrizMult[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

void imprimirMatriz(int matriz[QTD_LINHAS][QTD_COLUNAS], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrizA[QTD_LINHAS][QTD_COLUNAS], matrizB[QTD_LINHAS][QTD_COLUNAS], matrizMult[QTD_LINHAS][QTD_COLUNAS];
    int linA, colA, linB, colB;

    // Entrada da primeira matriz
    printf("Digite o número de linhas e colunas da matriz A: ");
    scanf("%d %d", &linA, &colA);

    printf("Digite os elementos da matriz A:\n");
    for (int i = 0; i < linA; i++) {
        for (int j = 0; j < colA; j++) {
            scanf("%d", &matrizA[i][j]);
        }
    }

    // Entrada da segunda matriz
    printf("Digite o número de linhas e colunas da matriz B: ");
    scanf("%d %d", &linB, &colB);

    printf("Digite os elementos da matriz B:\n");
    for (int i = 0; i < linB; i++) {
        for (int j = 0; j < colB; j++) {
            scanf("%d", &matrizB[i][j]);
        }
    }

    // Multiplica as matrizes
    multiplicarMatrizes(matrizA, linA, colA, matrizB, linB, colB, matrizMult);

    // Exibe o resultado
    printf("Matriz resultado:\n");
    imprimirMatriz(matrizMult, linA, colB);

    return 0;
}
