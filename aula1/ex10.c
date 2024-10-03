// BeeCrowd voleibol

#include <stdio.h>

int main() {
    int v[10];
    for (int i = 0; i < 10; i++) {
        printf("Digite o valor na posicao %d: ", i);
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < 10; i++) {
        printf("%d", v[i]);
    }

    printf("Digite o valor que deseja buscar: ");
    buscaBinaria(v, 10);

}

int buscaBinaria(int v[10], int tam) {
    int esq = 0, dir = tam - 1, meio, valor;
    scanf("%d", &valor);

    while (esq <= dir) {
        meio = (esq+dir)/2;
        if (v[meio] == valor) {
            return meio;
        } else if ( v[meio] < valor){
            esq = meio 
        }
    }
}