#include <stdio.h>

#define less(A,B) ((A)<(B))
#define exch(A,B) {int t; t=A;A=B;B=t;}
#define cmpexch(A,B){if(less(A,B)) exch(A,B)}

void insertionsort(int *v, int l, int r){

    for(int i =l+1; i<=r;i++){
        for(int j=i;j>l;j--){
            cmpexch(v[j],v[j-1]);
        }
    }

}



int main(){

    int v[5] = {9,5,6,3,2};

    int *p=v;

    insertionsort(p, 0,4);

    for(int i=0; i<5;i++){
        printf("%d ", v[i]);
    }

    
    
    return 0;

}