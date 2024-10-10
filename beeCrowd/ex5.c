#include <stdio.h>
#include <string.h>
#define TAM 20


int main(){
    int N=1, M=1;
    char str[TAM], strRes[TAM];
    while(N!=0 && M!= 0){
    scanf("%d %d",&N , &M);
    if (M==0 && N==0){
        break;
    }
    int soma = N+M;
    sprintf(str,"%d",soma);
    int j=0, len = strlen(str);
    for (int i=0; i<len; ++i){
        if (str[i]!= '0'){
            strRes[j] = str[i];
            ++j;
        } 
    }strRes[j] = '\0';
    printf("%s\n",strRes);

    }

return 0;
}