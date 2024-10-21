#include <stdio.h>

int main() {
    double QTD[10];
    
    for (int c = 0; c < 10; ++c) {
        printf("Digite o %d° valor: ", c + 1);
        scanf("%lf", &QTD[c]);
    }
    
    for (int i = 1; i < 10; ++i) {
        double atual = QTD[i];
        int j = i - 1;
        
        while (j >= 0 && QTD[j] > atual) {
            QTD[j + 1] = QTD[j];
            --j;
        }
        QTD[j + 1] = atual;  
    }
    
    for (int v = 0; v < 10; ++v) {
        printf("%f\n", QTD[v]);
    }
    
    return 0;
}
