#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main(){
    /*int n,d;
    printf("Digite o numerador e denominador: ");
    scanf("%d / %d", n,d); */

    int v[TAM];
    for (int i = 0; i < TAM; ++i){
        v[i] = rand();
    }
}

/*int divisaoRecursiva(int n, int d){
    if(n < d) {
        return 0;
    }

    return 1 + divisaoRecursiva(n - d, d);
} */

int maiorValor(int v[], int t){
    int i = 0;

    if(v[i] > v[t - 1]){
        return v;
    };

    return v[i] < maiorvalor(v[++i]);
}

int maiorrValor(int v[], int n) {
    if (n == 1) {
        return v[0];
    }

    int resp = maiorrValor(v, n - 1);
    if (v[n-1] > resp) {
        return v[n-1];
    }

    return resp;
}