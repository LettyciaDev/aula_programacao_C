#include <stdio.h>

int menu(int QTD[], int *tam);
int buscaBinaria(int QTD[], int tam);
int removerElemento(int QTD[], int *tam, int valor);
int inserirElemento(int QTD[], int *tam, int valor);

int main() {
    int QTD[50];
    int tam, opcao;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);


    if (tam < 3 &&  tam > 50) {
        return -1;
    }

    for (int c = 0; c < tam; c++) {
        printf("Digite o %d° valor: ", c +1);
        scanf("%d", &QTD[c]);
    }

    for (int i = 0; i < tam; i++) {
        int atual = QTD[i];
        int j = i - 1;

        while (j >= 0 && QTD[j] > atual) {
            QTD[j + 1] = QTD[j];
            --j;
        }

        QTD[j + 1] = atual;
    }

     menu(QTD, &tam);
}
int menu(int QTD[], int *tam) {
        int opcao;

        printf("Imprimir todo o vetor - Digite 1\n");
        printf("Consultar posição do elemento no vetor - Digite 2\n");
        printf("Remover um elemento - Digite 3\n");
        printf("Inserir elemento no vetor - Digite 4\n");

        printf("Digite um numero: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("\nVetor:\n");

            for(int i = 0; i < *tam; ++i) {  
                printf("%d ", QTD[i]);
            }
        printf("\n\n");
        }
        else if(opcao == 2) {
            int pos = buscaBinaria(QTD, *tam);
            if(pos != -1) {
                printf("Valor encontrado na posição: %d\n", pos);
            } else {
                printf("Valor não encontrado no vetor.\n");
            }
        } else if(opcao == 3) {
            int valor;
            printf("Digite o valor que deseja remover: ");
            scanf("%d", &valor);
            int remover = removerElemento(QTD, tam, valor);
            if (remover != -1) {
                printf("\nValor removido. Vetor atualizado:\n");
                for (int i = 0; i < *tam; ++i) {  
                    printf("%d ", QTD[i]);
                }
                printf("\n");
            } else {
                printf("Valor não encontrado no vetor.\n");
            } 
        } else if(opcao == 4) {
            if(*tam < 50) {  
                int valor;
                printf("Qual valor que você deseja inserir? ");
                scanf("%d", &valor);
                inserirElemento(QTD, tam, valor);
                printf("Vetor atualizado:\n");
                for (int i = 0; i < *tam; ++i) {  
                    printf("%d ", QTD[i]);
                }
                    printf("\n");
            } else {
                printf("Capacidade máxima do vetor atingida.\n");
            }
        }
}

int buscaBinaria(int QTD[], int tam) {
    int esq = 0, dir = tam - 1, meio, valor;
    printf('Digite o valor: ');
    scanf('%lf', &valor);

    while (esq <= dir) {
        int meio = (esq + dir) / 2;
        if (QTD[meio] == valor) {
            return meio;
        } else if (QTD[meio] < valor) {
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
    }
    return -1;
}

int removerElemento(int QTD[], int *tam, int valor) {
    int pos = buscaBinaria(QTD, *tam);
    if (pos == -1) {
        return -1;
    }
    for (int i = pos; i < *tam - 1; ++i) {
        QTD[i] = QTD[i + 1];
    }
    (*tam)--;
    return pos;
}

int inserirElemento(int QTD[], int *tam, int valor) {
    int i, m = 0;
    while (m < *tam && QTD[m] < valor) {
        m++;
    }
    for (i = *tam; i > m; i--) {
        QTD[i] = QTD[i - 1];
    }
    QTD[m] = valor;
    (*tam)++;
    return m;
}