#include <stdio.h>
/*formas de imprimir:
    %d (inteiro na base 10);
    %i (inteiro); 
    %f (double);
    %c (char);
    %s (string)*/

/*Operadores Lógicos:
    AND -> &&
    OR -> ||
    NOT -> !*/
    
/*Estrutura de repetição:
    while(condição) {} -> testa e executa (0 ou + vezes)
    do {} while (condição); -> apenas executa (1 ou + vezes); 
    */
/*Ponteiro: acessa diretamente a memória do computador, 
  guardando o endereço de memoria da variavel,
  possibilitando a alteração do valor da variável
  
  Ex:
    int main() {
        int min = 10, max = 20;
        int *ptr;
        printf("min = %d - max = %d - ptr = %p\n", min,max,ptr);

        ptr = &min;
        *ptr = 15;
        printf("min = %d - max = %d - ptr = %p\n", min,max,ptr);

        ptr = &max;
        *ptr = 25;
        printf("min = %d - max = %d - ptr = %p\n", min,max,ptr);


    }

  */
int imprimirNumeros1a100();

int main() {
    int min, max;
    printf("\nDigite o menor valor do intervalo: ");
    scanf("%d, &min"); // comando de entrada
    do {
        printf("\nDigite o maior valor do intervalo: ");
        scanf("%d, &max");
    } while (max < min);
    
    imprimirNumeros1a100();
    return(0);
}

int imprimirNumeros1a100() {
    for (int num = 1; num <= 100; num += 1) {
        printf("%d, ", num); 
    }
}

int calcularSomatorioImpares10e100() {
    int soma = 0;
    for (int num = 11; num <= 100; num += 3) {
        soma += num;
    }
    return soma;
}
