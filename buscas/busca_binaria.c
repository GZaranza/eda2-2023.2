#include <stdio.h>
#include "ordenacoes.h"

int busca_binaria(int *v,int l,int r, int chave){

    if(l>=r) return 0;

    int meio = (l+r)/2;

    if (v[meio]==chave) return 1;
    else if (v[meio]<chave) busca_binaria(v,l,meio-1,chave);
    else if (v[meio]>chave) busca_binaria(v,meio+1,r,chave);

}

int main(){

    int v[5]= {4,9,7,6,8};

    int *p=v;

    selectionsort(p,0,4);

    for(int i=0;i<5;i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    int aux = busca_binaria(v,0,4,4);

    printf("%d\n\n", aux);
    return 0;
}