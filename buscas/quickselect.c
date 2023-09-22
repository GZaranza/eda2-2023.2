#include <stdio.h>
#include "ordenacoesMacro.h"

int separa(int *v, int l, int r){

    int pivo =v[r];

    int j =l;

    for(int k=l;k<r;k++){
        if(v[k]<=pivo){
            exch(v[k],v[j]);
            j++;
        }
    }
    exch(v[r],v[j]);

    return j;

}

void quickselect(int *v, int l, int r, int chave){

    if(l>=r) return;

    int i;
    i= separa(v,l,r);
    printf("%d\n",v[i]);
    if(chave<i) quickselect(v,l,i-1,chave);
    if(chave>i) quickselect(v,i+1,r,chave);

    
}


int main (){

    int v[10]={2,10,6,14,8,20,12,16,18,4};

    int *p=v;

    int indice_buscado=1;

    quickselect(p,0,9,indice_buscado);

    printf("%d\n",v[indice_buscado]);




    return 0;
}