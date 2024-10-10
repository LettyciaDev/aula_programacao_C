#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 15

void LerString(char *str,int tam);
void SomaString(char *str, int *soma);

int main(){
    int N,j=0;
    scanf("%d",&N);
    getchar();
    while(j<N){
        char str[TAM];
        int soma = 0;
        LerString(str,TAM);
        int num =0,total=0;
        for (int i=0;i<TAM;++i){
            if (isdigit(str[i])){
                num = num*10 + (str[i] - '0');
                ++total;
            }else if (total>0){
                soma += num;
                num =0;
                total = 0;
            }


            }
        
        printf("%d\n",soma);
        ++j;
}
    return 0;
}



void LerString(char *str,int tam){
    fgets(str,tam,stdin);
    int len=strlen(str);
    if (str[len-1]=='\n'){
        str[len-1]='\0';
    }
}

void SomaString(char *str, int *soma){
    int num;
    sscanf(str,"%d",&num);
    *soma +=num;
}