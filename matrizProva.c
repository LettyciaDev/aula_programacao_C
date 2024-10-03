//Alunos: Lucas Mendes Nóbrega e Lettycia Vitória.

#include <stdio.h>
#include <stdlib.h>

#define M 30
#define N 20


void preencherMatriz(int m[][N], int lin, int col);
void imprimirMatriz(int m[][N], int lin, int col);
void maiorCadaColuna(int m[][N], int lin, int col, int v[]);
void imprimirVetor(int v[], int tam);
void MaisRepetidos(int Coluna, int mat[][Coluna],int Linha, int vetOrdLinha[], int vetOrdColuna[]);

int main() {
    int matriz[M][N];
    int vetor[N], vetOrdLinha[N], vetOrdColuna[M];
    int opcao;
    do {
        printf("\nMENU\n\n");
        printf("1 - preencher matriz com aleatorios\n");
        printf("2 - Maior cada coluna\n");
        printf("3 - Linha ou Coluna com mais repetidos\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            preencherMatriz(matriz, M, N);
            imprimirMatriz(matriz, M, N);
            break;
        case 2:
            maiorCadaColuna(matriz, M, N, vetor);
            imprimirVetor(vetor, N);
            break;
        case 3:
            MaisRepetidos(N,matriz,M,vetOrdLinha,vetOrdColuna);
        default:
            break;
        }
    } while (opcao != 0);
    return 0;
}

void preencherMatriz(int m[][N], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            m[i][j] = rand() % 100 + 1;
        }
    }
}

void imprimirMatriz(int m[][N], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
}

void maiorCadaColuna(int m[][N], int lin, int col, int v[]) {
    for (int j = 0; j < col; ++j) {
        int maior = m[0][j];
        for (int i = 1; i < lin; ++i) {
            if (m[i][j] > maior) {
                maior = m[i][j];
            }
        }
        v[j] = maior;
    }
}
void imprimirVetor(int v[], int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
void MaisRepetidos(int Coluna, int mat[][Coluna], int Linha, int vetOrdLinha[], int vetOrdColuna[]) {
    int IndLin, MaiorRepLin=0;
    int IndCol, MaiorRepCol=0;
    
    for (int a = 0; a < Linha; ++a) {
        for (int b = 0; b < Coluna; ++b) {
            vetOrdLinha[b] = mat[a][b];
        }
        for (int i = 1; i < Coluna; ++i) {
            int x = vetOrdLinha[i];
            int j = i - 1;
            while (j >= 0 && vetOrdLinha[j] > x) {
                vetOrdLinha[j + 1] = vetOrdLinha[j];
                --j;
            }
            vetOrdLinha[j + 1] = x;
        }
        int qtdRepetidos = 0, qtdTotal = 0;
        for (int i = 0; i < Coluna - 1; ++i) {
            if (vetOrdLinha[i] == vetOrdLinha[i + 1]) {
                int x = vetOrdLinha[i];
                qtdRepetidos = 1;
                while (i < Coluna - 1 && x == vetOrdLinha[i + 1]) {
                    ++qtdRepetidos;
                    ++i;
                }
                qtdTotal += qtdRepetidos;
            }
        }
        if (qtdTotal > MaiorRepLin) {
            MaiorRepLin = qtdTotal;
            IndLin = a;
        }
    }

    for (int a = 0; a < Coluna; ++a) {
        for (int b = 0; b < Linha; ++b) {
            vetOrdColuna[b] = mat[b][a];
        }
        for (int i = 1; i < Linha; ++i) {
            int x = vetOrdColuna[i];
            int j = i - 1;
            while (j >= 0 && vetOrdColuna[j] > x) {
                vetOrdColuna[j + 1] = vetOrdColuna[j];
                --j;
            }
            vetOrdColuna[j + 1] = x;
        }
        
        int qtdRepetidos = 0, qtdTotal = 0;
        for (int i = 0; i < Linha - 1; ++i) {
            if (vetOrdColuna[i] == vetOrdColuna[i + 1]) {
                int x = vetOrdColuna[i];
                qtdRepetidos = 1;
                while (i < Linha - 1 && x == vetOrdColuna[i + 1]) {
                    ++qtdRepetidos;
                    ++i;
                }
                qtdTotal += qtdRepetidos;
            }
        }
        if (qtdTotal > MaiorRepCol) {
            MaiorRepCol = qtdTotal;
            IndCol = a;
        }
    }
    if (MaiorRepLin>MaiorRepCol){
        printf("A linha %d possui o maior número de elementos repetidos: %d",IndLin,MaiorRepLin);
    } else if (MaiorRepLin<MaiorRepCol){ 
        printf("A coluna %d possui o maior número de elementos repetidos: %d",IndCol,MaiorRepCol);
    } else {
        printf("A linha %d e a coluna %d possuem o maior número de elementos repetidos: %d ",IndLin,IndCol,MaiorRepLin);
    }
}