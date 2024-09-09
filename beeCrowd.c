#include <stdio.h>

int main() {
    int N[6];
    int tam = 6;
    for (int a = 0; a <= tam; a++) {
        printf("Digite o %d valor: ", a + 1);
        scanf("%d", &N[a]);

    }
    
    int inicio = 0;
    int fim = tam - 1;

    while (inicio < fim) {
        
    }
    


    for (int i = 0; i < tam; i++){
        printf("N[%d] = %d", i, N[i]);
    }

    

}