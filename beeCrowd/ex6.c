#include <stdio.h>
#include <string.h>
#define TAM 52

int main() {
    int N, T = 0;
    scanf("%d", &N);
    getchar();
    
    while (T < N) {
        char strOri[TAM];
        fgets(strOri, TAM, stdin);
        int len = strlen(strOri);

        if (strOri[len - 1] == '\n') {
            strOri[len - 1] = '\0';
            len--;  
        }

        char strRes[TAM];
        int j = 0;

        
        int novaPalavra = 1;

        for (int i = 0; i < len; i++) {
            if (strOri[i] != ' ') {  
                if (novaPalavra) {
                    strRes[j++] = strOri[i];  
                    novaPalavra = 0; 
                }
            } else {
                novaPalavra = 1;
            }
        }
        strRes[j] = '\0';

        int temLetra = 0;
        for (int i = 0; i < len; i++) {
            if (strOri[i] != ' ') {
                temLetra = 1;
                break;
            }
        }

        if (temLetra) {
            printf("%s\n", strRes);
        } else {
            printf("\n");
        }

        T += 1;
    }
    return 0;
}