#include <stdio.h>
#include <string.h>

#define QTD 26
#define TAM_NOME 50
#define TEMP_CHAR 256

struct Estado{
    char nome[TAM_NOME];
    int num_veiculo;
    int acidente;
};

void lerEstados(struct Estado estados[], int qtd);
void lerStr(char *str, int tam);
void lerEstado(struct Estado *estado);
void maiorMenorAcidente(struct Estado a[], int qtd, int *maior, int *menor);
float percentVeiculo(struct Estado estado);
float mediaAcidentes(struct Estado estado[], int qtd);
void estadosAcimaMedia(struct Estado estado[], int qtd, float media);

int main(){
    int maior, menor;
    struct Estado estados[QTD];

    lerEstados(estados, QTD);

    maiorMenorAcidente(estados, QTD, &maior, &menor);
    printf("Estado com maior numero de acidente: %s (%d ° posicao)", estados[maior].nome, maior);
    printf("Estado com menor numero de acidente: %s (%d ° posicao)", estados[menor].nome, menor);

    printf("\nPercentual de veiculos envolvidos em acidentes: \n");
    for (int i = 0; i < QTD; ++i){
        float percentual = percentVeiculo(estados[i]);
        printf("Estado: %s percentual: %.2f%%\n", estados[i].nome, percentual);
    }

    float media = mediaAcidentes(estados, QTD);
    printf("\nMedia de acidentes no pais: %.2f\n", media);

    printf("\nEstados acima da média: \n");
    estadosAcimaMedia(estados, QTD, media);

    return 0;
}

void lerEstados(struct Estado estados[], int qtd) {
    struct Estado estado;

    for (int i = 0; i < QTD; ++i){
        printf("Dados do %d° estado: ", i+1);
        lerEstado(&estado);
    }
}

void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void lerEstado(struct Estado *estado){
    char temp[TEMP_CHAR];
    printf("Digite o nome do Estado: ");
    lerStr(estado->nome, TAM_NOME);
    printf("Digite o numero de veiculo: ");
    scanf("%d", estado->num_veiculo);
    printf("Digite o numero de acidentes: ");
    scanf("%d", estado->acidente);
    lerStr(temp, TEMP_CHAR);
}

void maiorMenorAcidente(struct Estado a[], int qtd, int *maior, int *menor){
    *maior = 0;
    *menor = 0;

    for (int i = 0; i < qtd; ++i){
       if(a[i].acidente > a[*maior].acidente){
            *maior = i;
       }

       if(a[i].acidente < a[*menor].acidente){
            *menor = i;
       }
    }
   
}

float percentVeiculo(struct Estado estado){
    float percentual;
   
    percentual = (estado.acidente / estado.num_veiculo) * 100;
    return percentual;
}


float mediaAcidentes(struct Estado estado[], int qtd) {
    float somaAcidentes = 0.0;
    for (int i = 0; i < qtd; i++) {
        somaAcidentes += estado[i].acidente;
    }
    return  somaAcidentes / qtd;
}


void estadosAcimaMedia(struct Estado estado[], int qtd, float media) {
    for (int i = 0; i < qtd; i++) {
        if (estado[i].acidente > media) {
            printf("%s (%d acidentes)\n", estado[i].nome, estado[i].acidente);
        }
    }
}