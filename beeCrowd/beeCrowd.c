#include <stdio.h>
#include <string.h>

#define TAM 48

void lerStr(char *str, int tam);

int main(){
    int qtd, c = 0;
    char nome[TAM];

    scanf("%d", &qtd);
    getchar();

    for(int i = 0; i < qtd; i++) {
        lerStr(nome, TAM);

         c = 0;
         for(int j = 0; j < strlen(nome); i++) {
        
            if (nome[j] != 'a' || nome[j] != 'e' || nome[j] != 'i' || 
                nome[j] != 'o' ||nome[j] != 'u') {

                    c +=1;
            }
        }
    }

   

    if (c == 3) {
        printf("%s nao eh facil\n", nome);        
    } else {
        printf("%s eh facil\n", nome);
    }
    
}

void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}