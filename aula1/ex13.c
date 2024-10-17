#include <stdio.h>

#define TAM_NOME 50
// Variaveis compostas heterogeneas (Struct/Registros)
struct Pessoa{
    char nome[TAM_NOME];
    int idade;
    float peso;
};

int main(){
    struct Pessoa pessoa;

    return 0;
   
}