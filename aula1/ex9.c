#include <stdio.h>

#define TAM 20

int main() {
    int vetor[TAM];
    int tam;

    printf("Digite o valor: ");
    scanf("&d ", &tam);
    
    int i;

    while (i = tam - 1 && i > 0) {
        printf("Digite o valor do elemento %d°: ");
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < tam; i++) {
        printf("Digite o valor do elemento %d°: ");
        scanf("%d", &vetor[i]);
    }


}