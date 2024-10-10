#include <stdio.h>
#include <string.h>
#define TAM 102

int main(){
    int N,j=0;
    scanf("%d",&N);
    getchar();
    while(j<N){    
        char str[TAM];
        scanf("%s",str);
        int len = strlen(str);
        char strRes[len];
        int a=0;
        for (int b=len-1;b>=0;--b){
            if (!(str[b]>='A' && str[b]<='Z')){
                strRes[a]=str[b];
                ++a;
            }
        }  
        strRes[a]='\0';
        printf("%s\n",strRes);
        ++j;
    }
    return 0;
}