#include <stdio.h>
#include "selectionsort.h"


int main(){

    int v[5]= {4,9,7,6,8};

    int *p=v;

    selectionsort(p,0,4);
    
    for(int i=0;i<5;i++){
        printf("%d ", v[i]);
    }
    
    return 0;
}