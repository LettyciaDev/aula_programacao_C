#include <stdio.h>

// Declarando uma variavel constante
#define QTD_ALUNOS 3

int main() {
    double notas[QTD_ALUNOS]; // pode ser considerado como um ponteiro
    // notas[2] = 10; ou seja, *(notas +2) = 10;

    for (int i = 0; i < QTD_ALUNOS; i++) {
        printf("Digite a %d nota: ", i+1);
        scanf("%lf",&notas[i]);
    }

    for (int i = 0; i < QTD_ALUNOS; i++) {
        printf("%d", notas[i]);
    }

    return 0;
    
}


