#include <stdio.h>

#define tam 5

int main () {
    int vetor[tam];
    int i, v, valor;

    // buscaMelhoradaSeitinela( v,  tam, valor);

    for (int i =0; i < tam; ++i) {
        printf("Digite o %d valor", i);
        scanf("%d", &vetor[i]);
    }

    printf("Qual valor deseja procurar?");
    scanf("%d", &valor);

    for (int i =0; i < tam; i++) {
        if (vetor[i] == valor) {

            return i;
        }
    }

    return -1;

    /*int buscaMelhoradaSeitinela(int v, int tam, int valor) {
        int i = 0;
        v[tam] = valor;

        while (v[i] < valor) {
            ++i;
        }
        if (i < tam && v[i] == valor) {
            return i;
        }
        return -1;
    } */

    /*int vetoresOrdenados(int v[], int tam) {
        for (int i = 1; i < tam; i++) {
            if (v[i] < v[i-1]) {
                return 0;
            }
        }
        return 1;
    } */
}