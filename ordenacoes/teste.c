#include <stdio.h>
#include <stdlib.h>
#include "ordenacoesMacro.h"


int separa(int *v, int l, int r){

    int pivo = v[r];
    //k anda por todo o vetor 
    int j = l;//posicao atual onde entrara um num menor que o pivo

    for(int k=l;k<r;k++){
        if(less(v[k],pivo)){
            exch(v[j],v[k]);
            j++;
        }
    }

    exch(v[j],v[r]);
    return j;
}

void quicksort(int *v, int l, int r){

    if(l>=r) return;

    /*cmpexch(v[r],v[(l+r)/2]);
    cmpexch(v[(l+r)/2], v[l]);
    cmpexch(v[(l+r)/2], v[r]);*/

    int j = separa(v,l,r);
    quicksort(v,l,j-1);
    quicksort(v,j+1,r);
}

void quickselect(int *v, int l, int r, int k){
    if(l>=r) return;

    int j = separa(v,l,r);
    if(j<k) quickselect(v,j+1,r,k);
    if(j>k) quickselect(v,l,j-1,k);
}

void insertionsort(int *v, int l, int r){

    for(int i = l+1; i<=r; i++){
        for(int j=i; j>l;j--){
            cmpexch(v[j],v[j-1]);
        }
    }

}

void selectionsort(int *v, int l, int r){

    for(int i=l;i<=r;i++){

        int menor = i;
        for(int j = i; j<=r;j++){
            if(v[j]< v[menor]){
                menor=j;
            }
        }
        exch(v[i],v[menor]);
    }

}

void confere_ordenacao(int *v, int l, int r){

    for(int i=l+1;i<=r;i++){
        if(v[i]<v[i-1]){
            printf("\nNao esta ordenado\n");
            return;
        }
    }
    printf("\nEsta ordenado\n");
            return;
}

void merge(int *v, int l, int r, int m){

    int i=l;
    int j=m+1;
    int k =0;

    int *aux=malloc(sizeof(int)*(r-l+1));

    while(i<=m && j<=r){
        if(v[i]<=v[j]){
            aux[k++]=v[i++];
        }
        else{
            aux[k++]= v[j++];
        }
    }

    while(i<=m) aux[k++]=v[i++];

    while(j<=r) aux[k++]=v[j++];

    k=0;

    for(int i =l; i<=r;i++){
        v[i]=aux[k++];
    }

}

void mergesort(int *v, int l, int r){
    if(l>=r) return;

    int meio = (l+r)/2;

    mergesort(v,l,meio);
    mergesort(v,meio+1,r);
    merge(v,l,r,meio);
}

void coutingsort(int *v, int n, int c){
    //n = maior numero do conjunto; c = tamanho do vetor
    int *aux = calloc(n+1,sizeof(int));

    for(int i =0; i < c;i++){
        aux[v[i]]++;
    }

    int j = 0;

    for(int i=0; i<=n;i++){
        while(aux[i]>0){
            v[j++]=i;
            aux[i]--;
        }
    }
    free(aux);
}

int busca_binaria(int *v, int l, int r, int valor){

    if(l>=r) return;

    int meio = (l+r)/2;

    if(valor==v[meio]){
        printf("\nValor encontrado\n");
        return 1;
    }
    else if(valor<v[meio]) busca_binaria(v,l,meio-1,valor);
    else if(valor>v[meio]) busca_binaria(v,meio+1,r,valor);
    else printf("\nValor NAO encontrado\n");
    return 0;



}

int main(){

    int vetor[50] = {57, 12, 86, 33, 41, 95, 70, 64, 25, 78, 5, 50, 91, 18, 74, 63, 28, 99, 37, 7, 88, 55, 46, 22, 6, 68, 31, 76, 59, 92, 9, 85, 20, 72, 54, 14, 60, 96, 44, 67, 23, 49, 83, 2, 39, 89, 17, 45, 73, 35};
    int l=0;
    int r=49;
    int *p = vetor;

    //quickselect(vetor,0,49, 10);
    coutingsort(vetor,99,50);
    for(int i =l;i<=r;i++){
        printf("%d ", vetor[i]);
    }

    printf("\n");
    confere_ordenacao(vetor,l,r);

    busca_binaria(vetor,l,r,64);
    return 0;
}

//2 5 6 7 9 12 14 17 18 20 22 23 25 28 31 33 35 37 39 41 44 45 46 49 50 54 55 57 59 60 63 64 67 68 70 72 73 74 76 78 83 85 86 88 89 91 92 95 96 99 