#include <stdio.h>

#define TAM 48
int main(){
    int qtd;
    char nome[TAM];

    scanf("%d", &qtd);

    for(int i = 0; i < qtd; i++) {
        lerStr(nome, TAM);
    }
    for(int i = 0; i < qtd; i++) {
        pri
    }
}

void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}