#include <stdio.h>

// Matrizes

/* int v[12];
    int mat[4][3];
    mat[2][1] = 7;

    
    &v[0] -> v
    v[8] -> *(v+8 -> 8*4(sizeofint))

    Em matrizes, sempre devemos declarar o valor da coluna,
    assim podemos consultar a posição do elemento em uma matriz. Ex:

    mat[2][1]
    mat + (2(linha)*3(qtd_coluna)+1)
*/

#define QTD_LINHAS 4
#define QTD_COLUNAS 3

void lerMatriz(int mat[][QTD_COLUNAS], int lin, int col);

int main() {
    int qtdLinhas, qtdColunas;
    int matriz[QTD_LINHAS][QTD_COLUNAS];
    printf("Digite a quantidade de Linhas no intervalo (1-%d)", QTD_LINHAS);
    qtdLinhas = lerDentroIntervalo(1, QTD_LINHAS);



    return 0;
}

void lerMatriz(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < QTD_LINHAS; i++){
        for (int j = 0; j < QTD_COLUNAS; j++){
            printf("(%d,%d )", i,j);
        }
        printf("\n");
    }
}
void imprimirMatriz();

int lerDentroIntervalo(int min, int max) {
    int valor;
    scanf("%d", &valor);
    while (valor < min || valor > max){
        printf("Valor invalido! Digite o valor correto");
        scanf("%d", &valor);
    }
}