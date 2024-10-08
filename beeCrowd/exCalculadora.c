#include <stdio.h>

#define TAM 14
int main(){
    int tam;
    char lin[14];

    while (tam < 0 || tam > 1000){
        scanf("%d", &tam);
    }
    
    for(int i = 0; i < tam; i++) {
        lerStr(lin, TAM);
    }
}

void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void somar(char *str, int tam) {
    int len = strlen(str);
}