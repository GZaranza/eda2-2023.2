#include <stdio.h>
#include <stdlib.h>
#include "ordenacoes.h"
#include "ordenacoesMacro.h"


void countingsort(int *v, int n, int c){
    // n é o maior elemento do veotor e c o tamanho do vento
    int *aux = calloc((n+1),sizeof(int));
    for(int i=0; i<c;i++){
        aux[v[i]]++;
    }

    int j=0;

    for(int i=0;i<=n;i++){
        while(aux[i]>0){
            v[j++]=i;
            aux[i]--;
        }
    }
    free(aux);
}

int main(){

    int v[5] = {9,3,1,3,1};

    int *p = v;

    countingsort(p, 9, 5);

    for(int i=0; i<5;i++){
        printf("%d ", v[i]);
    }

    return 0;
}