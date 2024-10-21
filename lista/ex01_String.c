#include <stdio.h>
#include <string.h>

#define TAM 50

void lerStr(char *nome, int tam);
int main(){
    char nome[2][TAM];
    for (int i = 0; i < 2; ++i) {
        lerStr(nome[i], TAM);
    }

    
    if (strcmp(nome[0], nome[1]) < 0){
        char temp[TAM];
        strcpy(temp, nome[0]);
        strcpy(nome[0], nome[1]);
        strcpy(nome[1], temp);
    }
    
    for (int j = 0; j < 2; ++j) {
        printf("%s", nome[j]);
    }

    return 0;

}

void lerStr(char *nome, int tam) {
    fgets(nome, tam, stdin);
    int len = strlen(nome);

    if (nome[len - 1] == '\n') {
        nome[len - 1] = '\0';
    }
}