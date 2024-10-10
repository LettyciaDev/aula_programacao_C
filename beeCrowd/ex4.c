#include <stdio.h>
#include <string.h>
#define TAM 45

void LerString(char *str,int tam);

int main(){
    int N,j=0;
    scanf("%d",&N);
    getchar();
    while(j<N){    
        char str[TAM];
        LerString(str,TAM);
        int len = strlen(str);
        int x=1,a=0,R=1;
        while(len-x>=0){
            if (!(str[len-x]=='A' || str[len-x]=='E' || str[len-x]=='I' || str[len-x]=='O' || str[len-x]=='U' 
            || str[len-x]=='a' || str[len-x]=='e' || str[len-x]=='i' || str[len-x]=='o' || str[len-x]=='u' )){
                ++a;
                if (a==3){
                    R=0;
                    break;
                }
            }   else{
                a=0;
            }
            ++x;
        }  
        if (R){
            printf("%s eh facil\n",str);
        } else {
            printf("%s nao eh facil\n",str);
        }
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