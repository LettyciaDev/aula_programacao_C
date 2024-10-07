#include <stdio.h>
#include <string.h>
#include <ctype.h>

// String

#define TAM 50

void lerStr(char *str, int tam);
void modificarTexto(char *str, char *mdc);

int main(){
    char texto[TAM];
    char textoMod[TAM];
    printf("Digite o texto: ");
    lerStr(texto, TAM);
    modificarTexto(texto, textoMod);
}

void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
void modificarTexto(char *str, char *mdc) {
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            continue;
        }

        char mod = toupper(str[i]);
        switch (mod) {
            case 'á': case 'à': case 'ã': case 'â': case 'ä':
                mdc[j++] = 'a'; break;
            case 'é': case 'è': case 'ê': case 'ë':
                mdc[j++] = 'e'; break;
            case 'í': case 'ì': case 'î': case 'ï':
                mdc[j++] = 'i'; break;
            case 'ó': case 'ò': case 'õ': case 'ô': case 'ö':
                mdc[j++] = 'o'; break;
            case 'ú': case 'ù': case 'û': case 'ü':
                mdc[j++] = 'u'; break;
             case 'ç':
                mdc[j++] = 'c'; break;
            default:
                mdc[j++] = mod;
        }
    }
    mdc[j] = '\0';

    
}

void ehpalindroma(char *str, char *mdc) {
    int len = strlen(str);
    int j = 0;
    for(int i = str[len - 1]; i > 0; i--){
        mdc[j] = str[i];
        j++;
    }
    mdc[j] = '\0';
}
