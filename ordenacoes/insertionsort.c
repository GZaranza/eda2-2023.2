#include <stdio.h>
#define troca(A,B) {int t; t=A;A=B;B=t;}
#define menor(A,B) ((A)<(B))
#define menor_igual(A,B) ((A)<=(B))
#define menor_troca(A,B) {if (menor(B, A)) troca(A,B)}

int vetor[100]= {2, 86, 42, 14, 69, 49, 67, 3, 23, 10, 18, 80, 51, 61, 31, 93, 45, 73, 96, 74, 12, 65, 71, 97, 30, 29, 62, 99, 16, 64, 5, 58, 91, 56, 76, 37, 7, 66, 85, 21, 38, 60, 47, 46, 24, 95, 54, 50, 53, 19, 89, 27, 25, 68, 26, 81, 70, 79, 59, 17, 75, 36, 15, 48, 11, 8, 83, 22, 35, 78, 94, 4, 98, 55, 90, 77, 84, 20, 92, 9, 87, 34, 32, 28, 63, 88, 72, 6, 57, 33, 1, 40, 82, 41, 43, 44, 52}
;
void insertionsort(int *v, int l, int r){

    for(int i=l+1;i<r;i++){
        int j = i;
        for(int )
    }


}





int main(){
    int *v= vetor;
    insertionsort(v,0,99);

    int a=0;

    for(int i=0;i<100;i++){
        printf("%d ", v[i]);
        a++;
    }

    printf("\n%d ", a);
    return 0;
}