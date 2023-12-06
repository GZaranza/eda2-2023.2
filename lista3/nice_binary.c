#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int main (){
   
    int t;
    scanf("%d", &t);
    char *vetor = malloc(sizeof(char)*10000);
    for(int i = 0;i<t;i++){
        scanf("%s", vetor);
        
        int tam = strlen(vetor);
        
        int l=0,n=0,dir=0,esq=0;

        if(vetor[0]=='l'){
            printf("0\n");
            continue;
        }

        for(i=1;i<tam;i++){
            if(vetor[i]=='n') n++;
            else l++;

            if(n+1==l) break;
        }

        

        printf("%d\n", cont);
    }

}