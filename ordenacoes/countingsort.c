#include <stdio.h>
#include <stdlib.h>


void countingsort(int *v, int n, int r){

    int *aux = calloc(r, sizeof(int));

    for(int i =0;i<n;i++){
        aux[v[i]]++;
    }
    int j=0;
    for(int i = 0; i<r;i++){
        v[j++]=v
        
    }

}

int main(){

    int v[5] = {9,3,1,3,1};

    int *p = v;

    countingsort(v, 5, 10);

    for(int i=0; i<5;i++){
        printf("%d ", v[i]);
    }

    return 0;
}