#include <stdio.h>


int main() {
    int vetor[10];
    int qtd;
    double valor;

    vetorOrdenado(valor);

    int tam = 0;

    int vetorOrdenado(valor) {
        int i = tam - 1;
        
        while (i >= 0 && vetor[i] > valor) {
            vetor[i + 1] = vetor[i];
            i--;
        }
        
        vetor[i + 1] = valor;
        tam++;
    }

    printf("Digite a quantidade de valores que serão inseridos: \n");
    scanf("%d", &qtd);

    if (qtd > 10) {
        printf("A quantidade excede o valor permitido");
        return 1;
    }
    
    for (int i= 0; i < qtd; i++) {
        printf("Digite o valor do %d° elemento: ", i+1);
        scanf("%f",&valor);
    }
    
    printf("Valores ordenados");
    for (int i= 0; i < tam; i++) {
        scanf("%f", vetor[i]);
    }
}