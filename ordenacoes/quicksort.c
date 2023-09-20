#include <stdio.h>
#include <stdlib.h>

#define less(a,b) (a<b)
#define lesseq(a,b) (a<=b)
#define exch(a,b) {int t; t=a;a=b;b=t;}
#define cmpexch(a,b) {if(less(a,b)) exch(a,b)}
#define cmpeqexch(a,b) {if(lesseq(a,b)) exch(a,b)}

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

    cmpexch(v[r],v[(l+2)/2]);
    cmpexch(v[(l+r)/2],v[l]);
    cmpexch(v[(l+r)/2],v[r]);


    int p = separa(v,l,r);

    quicksort(v,l,p-1);
    quicksort(v,p+1,r);

}



int main(){

    int v[5] = {1,5,3,7,6};

    int *p=v;

    quicksort(v, 0,4);

    for(int i =0;i<5;i++){
        printf("%d ", v[i]);
    }



    return 0;
}