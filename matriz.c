#include <stdio.h>

#define QTD_LINHAS 100
#define QTD_COLUNAS 100

void preencherMatriz(int mat[][QTD_COLUNAS], int lin, int col);
int numerosImpares(int mat[][QTD_COLUNAS], int lin, int col);
void buscarElemento(int mat[][QTD_COLUNAS], int lin, int col, int valor);
int somatorio(int mat[][QTD_COLUNAS], int lin, int col);
int mediaMatriz(int mat[][QTD_COLUNAS], int lin, int col);
void mediaLinha(int mat[][QTD_COLUNAS], int lin, int col);
int lerIntervalo(int min, int max);

int main() {
    int qtdLinhas, qtdColunas, qtdImpar, soma, media, elementoBuscado;
    int matriz[QTD_LINHAS][QTD_COLUNAS];

    printf("Digite a quantidade de linhas (1-%d): ", QTD_LINHAS);
    qtdLinhas = lerIntervalo(1,QTD_LINHAS);
    printf("Digite a quantidade de linhas (1-%d): ", QTD_LINHAS);
    qtdColunas = lerIntervalo(1,QTD_COLUNAS);

    preencherMatriz(matriz, qtdLinhas, qtdColunas);

    qtdImpar = numerosImpares(matriz, qtdLinhas, qtdColunas);
    printf("Quantidade de numeros impares: %d\n\n", qtdImpar);

    printf("Digite um elemento para buscar na matriz: ");
    scanf("%d", &elementoBuscado);
    buscarElemento(matriz, qtdLinhas, qtdColunas, elementoBuscado);

    soma = somatorio(matriz, qtdLinhas, qtdColunas);
    printf("Somatorio dos elementos: %d\n\n", soma);

    media = mediaMatriz(matriz, qtdLinhas, qtdColunas);
    printf("Media dos elementos: %d\n\n", media);

    mediaLinha(matriz, qtdLinhas, qtdColunas);

    
    return 0;
}

int lerIntervalo(int min, int max) {
    int valor;
    scanf("%d", &valor);
    while (valor < min || valor > max) { 
        printf("Valor inválido. Digite outro valor entre %d e %d: ", min,max);
        scanf("%d", &valor);
    }

    return valor;
}

void preencherMatriz(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++) {
            printf("Digite o valor para mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);

        }
    }
}

int numerosImpares(int mat[][QTD_COLUNAS], int lin, int col) {
    int c = 0;
    for (int i = 0; i < lin; i++ ) {
        for (int j = 0; j < col; j++){
            if (mat[i][j] % 2 != 0){
                c +=1;
            }
        }
    }

    return c;
}
void buscarElemento(int mat[][QTD_COLUNAS], int lin, int col, int valor) {
    int encontrado = 0;
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            if (mat[i][j] == valor) {
                printf("Elemento %d encontrado na posicao [%d][%d]\n", valor, i, j);
                encontrado = 1;
                break; 
            }
        }
        if (encontrado) break; 
    }
    if (!encontrado) {
        printf("Elemento %d não encontrado na matriz.\n", valor);
    }
}

int somatorio(int mat[][QTD_COLUNAS], int lin, int col) {
    int s = 0;
    for (int i = 0; i < lin; i++ ) {
        for (int j = 0; j < col; j++){
                s += mat[i][j];
            }
        }

    return s;
    }
int mediaMatriz(int mat[][QTD_COLUNAS], int lin, int col) {
    int s = 0;
    int c = 0;
    int media = 0;

    for (int i = 0; i < lin; i++ ) {
        for (int j = 0; j < col; j++){
                c += 1;
                s += mat[i][j];
            
        }
    }
    media = s/c;
    return media;
}
void mediaLinha(int mat[][QTD_COLUNAS], int lin, int col) {
    int mediaLinha = 0;

    for (int i = 0; i < lin; i++) {
        int s = 0;
        for (int j = 0; j < col; j++) {
            s += mat[i][j];
        }
    mediaLinha = s/col;
    printf("Média dos elementos da linha %d: %d\n", i, mediaLinha);
     }
}



