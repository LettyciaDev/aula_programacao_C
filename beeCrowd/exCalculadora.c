#include <stdio.h>
#include <ctype.h>

int main() {
    int N;
    scanf("%d", &N); // Lê o número de linhas
    getchar(); // Limpa o caractere de nova linha após a leitura do inteiro

    for (int i = 0; i < N; i++) {
        char linha[15]; // Array para armazenar a linha (14 caracteres + 1 para o terminador)
        fgets(linha, sizeof(linha), stdin); // Lê a linha

        int soma = 0; // Variável para armazenar a soma dos dígitos
        for (int j = 0; j < 14; j++) {
            if (isdigit(linha[j])) { // Verifica se o caractere é um dígito
                soma += linha[j] - '0'; // Converte o caractere para inteiro e soma
            }
        }
        printf("%d\n", soma); // Exibe o resultado da soma
    }

    return 0;
}
