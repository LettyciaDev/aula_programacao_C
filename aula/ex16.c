#include <stdio.h>

double potencia(int x, int n);
int ponteciaIterativa(int x, int n);

int main(){
    int x, n;

    printf("Digite o numero da base: ");
    scanf("%d", &x);

    do { 
        printf("Digite o numero do expoente: ");
        scanf("%d", &n);
    }while (n < 0);
   
   printf("%f",potencia(x, n));
   printf("%d",ponteciaIterativa(x, n));
}

double potencia(int x, int n){
    if(n == 0){
        return 1;
    }

    return x * potencia(x, n-1);
}

int ponteciaIterativa(int x, int n){
    int pow = 1;

    for(int i = 0; i < n; ++i){
        pow *= x;
    }

    return pow;
}