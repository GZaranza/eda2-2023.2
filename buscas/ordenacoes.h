#ifndef ORDENACOES_H
#define ORDENACOES_H


#include <stdio.h>
#define less(a,b) (a<b)
#define lesseq(a,b) (a<=b)
#define exch(a,b) {int t; t=a;a=b;b=t;}
#define cmpexch(a,b) {if(less(a,b)) exch(a,b)}
#define cmpeqexch(a,b) {if(lesseq(a,b)) exch(a,b)}

void insertionsort(int *v, int l, int r){

    for(int i =l+1; i<=r;i++){
        for(int j=i;j>l;j--){
            cmpexch(v[j],v[j-1]);
        }
    }

}

void selectionsort(int *v, int l, int r){

    for(int i =0; i<=r;i++){
        int min = i;
        for(int j=i;j<=r;j++){
            if(v[j]<v[min]){
                min=j;
            }
        }
        exch(v[i],v[min])
    }
}

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

int separa(int *v,int l,int r){

    int pivo = v[r];

    int j =l;

    for(int k=0;k<r;k++){
        if(lesseq(v[k],pivo)){
            exch(v[j],v[k]);
            j++;
        }
    }

    exch(v[j],v[r]);

    return j;
    

}

void quicksort(int *v, int l, int r){

    if(l>=r) return;

    //cmpexch(v[r],v[(l+2)/2]);
    //cmpexch(v[(l+r)/2],v[l]);
    //cmpexch(v[(l+r)/2],v[r]);


    int p = separa(v,l,r);

    quicksort(v,l,p-1);
    quicksort(v,p+1,r);

}

#endif
