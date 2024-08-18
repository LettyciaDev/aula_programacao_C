#include <stdio.h>

void num_1_a_100() {

    printf("Numeros de 1 a 100: \n");
    for (int i = 1; i <= 100; i++) {
        if (i < 100) {
            printf("%d, ", i);
        } else {
            printf("%d\n", i);
        }
    }
}

void soma_impar_entre_10_e_1000() {

    printf("Somatorio de todos os numeros impares entre 10 e 1000: \n");
    int soma = 0;
    for (int i = 10; i <= 1000; i++) {
        if (i % 2 != 0) {
            soma += i;
        }
    }
    printf("%d\n", soma);
}

void multi_de_3_sem_3_entre_1_e_200() {

    printf("Todos os numeros multiplos de 3 que nao terminam em 3 (entre 1 e 200): \n");
    for (int i = 1; i <= 200; i++) {
        if (i % 3 == 0 && i % 10 != 3) {
            if (i < 200 && i != 3) {
                printf("%d, ", i);
            } else {
                printf("%d\n", i);
            }
        }
    }
}

int main() {
    num_1_a_100();
    soma_impar_entre_10_e_1000();
    multi_de_3_sem_3_entre_1_e_200();
    return 0;
}
