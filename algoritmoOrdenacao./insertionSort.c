#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void preencherVetor(int *v, int tam);
void preencherVetorOC(int *v, int tam);
void preencherVetorOD(int *v, int tam);
void insertionSort(int *v, int tam);
double tempoExecucao(clock_t inicio, clock_t fim);


int main() {
    int size[] = {10, 100, 1000, 10000, 100000};
    int max_time = 300000;

    for (int s = 0; s < sizeof(size) / sizeof(size[0]); s++) {
        int tam = size[s];
        int *v = (int *)malloc(tam * sizeof(int));
        if (v == NULL) {
            printf("Falha na alocação de memória!\n");
            return 1;
        }

        double temp_desord, temp_cres, temp_desc;
        clock_t inicio, fim;

           
        preencherVetor(v, tam);
        inicio = clock();
        insertionSort(v,tam);
        fim = clock();
        temp_desord = tempoExecucao(inicio, fim);
        if (temp_desord > max_time) {
            free(v);
            break;
        }

        preencherVetorOC(v,tam);
        inicio = clock();
        insertionSort(v,tam);
        fim = clock();
        temp_cres = tempoExecucao(inicio, fim);

        
        preencherVetorOD(v,tam);
        inicio = clock();
        insertionSort(v,tam);
        fim = clock();
        temp_desc = tempoExecucao(inicio, fim);

        printf("TAM do Vetor: %7d |tempo(vetor desordenado): %23.2f |tempo(vetor Ordenado Cres): %29.2f |tempo(vetor Ordenado decres): %30.2f\n",tam, temp_desord, temp_cres, temp_desc);
        free(v);
        
        
    
    }
   
    return 0;
}


void preencherVetor(int *v, int tam){
    for(int i = 0; i < tam; ++i){
        v[i] = rand();
    }
}

void preencherVetorOC(int *v, int tam){
    for(int i = 0; i < tam; ++i){
        v[i] = i;
    }
}

void preencherVetorOD(int *v, int tam){
    for(int i = 0; i < tam; ++i){
        v[i] = tam - i;
    }
}


void insertionSort(int *v, int tam) {
    for (int i = 1; i < tam; i++) {
        int tmp = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > tmp) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = tmp;
    }
}

double tempoExecucao(clock_t inicio, clock_t fim) {
    return ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
}