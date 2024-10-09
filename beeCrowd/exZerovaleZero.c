#include <stdio.h>
#include <string.h>

#define TAM 100

int main() {
    int M, N;
    int soma;
    char resultado[TAM]; 
    int i = 0;

    scanf("%d", &M);
    scanf("%d", &N);

    soma = M + N;

    // Armazena a soma como uma string
    sprintf(resultado, "%d", soma);


    char resultadoSemZeros[TAM];
    int j = 0;

   
    for (int k = 0; resultado[k] != '\0'; k++) {
        if (resultado[k] != '0') {
            resultadoSemZeros[j++] = resultado[k];
        }
    }

    resultadoSemZeros[j] = '\0'; 

    if (j > 0) {
        printf("%s\n", resultadoSemZeros);
    } else {
        printf(" "); // Se não houver dígitos, exibe 0
    }

    return 0;
}
