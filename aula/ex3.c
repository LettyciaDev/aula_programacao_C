#include <stdio.h>

// Passagem por referencia

int main() {
    int num1 = 10, num2 = 20;
    printf("num1 = %d - num2 = %d\n", num1, num2);
    troca(&num1, &num2); // Guardando o endereço de memória
    printf("num1 = %d - num2 = %d\n", num1, num2);
    return 0;
}

void troca(int *a, int *b) { // 'a' e 'b' são ponteiros
    printf("a = %d - b = %d\n", *a,*b);
    int aux = *a;
    *a = *b;
    *b = aux;
    printf("a = %d - b = %d\n", *a,*b);

}
/*Solicitar ao sistema operacional um espaço na memória:
    função da biblioteca stdlib.h: void *malloc

    int main() {
     int *ptr = (int *) malloc(sizeof(int));
     if (!ptr) {
        printf("Memória não alocada!")
        return 1;
     }
     *ptr = 20
     printf("ptr = %p - *ptr = %d\n", ptr, *ptr)

     free(ptr)
     }
*/