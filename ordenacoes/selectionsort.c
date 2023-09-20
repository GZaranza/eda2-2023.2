#include <stdio.h>

#define less(a,b) ((a)<(b))
#define exch(a,b) {int t;t=a;a=b;b=t;}
#define cpmexch(a,b) {if(less(a,b)) exch(a,b)}


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


int main(){

    int v[5] = {9,5,7,3,4};

    int *p=v;

    selectionsort(p,0,4);

    for(int i =0;i<5;i++){
        printf("%d ", v[i]);
    }

    return 0;
}