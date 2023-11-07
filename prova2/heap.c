#include <stdlib.h>
#include <stdio.h>

typedef struct FP{
    int *v;
    int n, tam;
}FP;

FP *cria_heap(int tam){
    FP *heap = malloc(sizeof(FP));
    heap->v=malloc(tam*sizeof(int));
    heap->tam=tam;
    heap->n=0;
    return heap;
}

int pai(int n){
    return (n-1)/2;
}

int esq_filho(int n){
    return (n*2)+1;
}

int dir_filho(int n){
    return (n*2)+2;
}

void troca(FP *fp, int pai, int filho){
    int aux = fp->v[filho];
    fp->v[filho] = fp->v[pai];
    fp->v[pai] = aux;
}

void sobe_heap(FP *fp, int i){
    
    //se i nao eh 0 e se o pai eh menor que o filho
    if(i > 0 && fp->v[pai(i)] < fp->v[i]){
        troca(fp,pai(i),i);
        sobe_heap(fp, pai(i));
    }
}

void desce_heap(FP *fp, int i){
    int maior_filho;
    int esq = 2*i+1;
    int dir =2*i+2;

    if(esq < fp->n){
        maior_filho = esq;
        if(dir < fp->n && fp->v[dir] > fp->v[esq]){
            maior_filho=dir;
        }
        if(fp->v[i] < fp->v[maior_filho]){
            troca(fp,i,maior_filho);
            desce_heap(fp,maior_filho);
        }
    }
}

void insere(FP *fp, int x){
    fp->v[fp->n]=x;
    fp->n++;
    sobe_heap(fp,fp->n-1);
}


int remover(FP *fp){
    troca(fp,0,fp->n-1);
    fp->n--;
    desce_heap(fp,0);
    return fp->v[fp->n];
}



int main(){

    FP *heap=cria_heap(15);
    int v[12] = {6,1,5,4,3,7,8,12,2,9,10,11};
    for(int i=0;i<12;i++){
        insere(heap,v[i]);
    }

    for(int i =0;i<12;i++){
        printf("%d ",remover(heap));
    }
    printf("\n");
}