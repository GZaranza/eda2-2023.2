#include <stdio.h>
#include <stdlib.h>
#include "ordenacoes.h"
#include "ordenacoesMacro.h"

void merge(int *v, int l, int r, int meio){

    int aux[5] ;
    

    int i=l;
    int j = meio+1;
    int k=0;

    while(i<=meio && j<=r){

        if(v[i]<v[j]){
            aux[k++]=v[i++];
        }

        else{
            aux[k++]=v[j++];
        }
    }

    while(i<=meio){
        aux[k++]=v[i++];
    }

    while(j<=r){
        aux[k++]=v[j++];
    }

    k=0;

    for(int i=l;i<=r;i++){
        v[i]=aux[k++];
    }

    

}


void mergesort(int *v, int l, int r){

    if(r<=l) return;

    int meio = (l+r)/2;

    mergesort(v,l,meio);
    mergesort(v,meio+1,r);
    merge(v,l,r,meio);

}

int main(){

    int v[5] = {9,7,8,3,4};

    int *p = v;


    mergesort(v,0,4);
    for(int i =0; i<5;i++){

        printf("%d ", v[i]);
    }

    return 0;
}

