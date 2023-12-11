#include <stdio.h>
#include <stdlib.h>

enum cor  {VERMELHO,PRETO};

typedef struct no{
    int dado;
    struct no *esq, *dir;
    enum cor cor;
}no;

no *rot_dir(no *raiz){
    no *a = raiz->esq;
    raiz->esq=a->dir;
    a->dir=raiz;
    a->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return a;
}

no *rot_esq(no *raiz){
    no *x = raiz->dir;
    raiz->dir = x->esq;
    x->esq = raiz;
    x->cor=raiz->cor;
    raiz->cor=VERMELHO;
    return x;
}

void sobe_cor(no *raiz){
    raiz->cor=VERMELHO;
    raiz->esq->cor=PRETO;
    raiz->dir->cor=PRETO;
}

no *corrige(no *raiz){
    if(raiz->esq->cor==PRETO && raiz->dir->cor==VERMELHO){
        return rot_esq(raiz);
    }
    if(raiz->esq->cor==VERMELHO && raiz->dir->cor==VERMELHO){
        sobe_cor(raiz);
        return raiz;
    }
    if(raiz->esq->cor==VERMELHO && raiz->esq->esq->cor==VERMELHO){
        raiz = rot_dir(raiz);
        sobe_cor(raiz);
        return raiz;
    }
    return raiz;
}

no *insere_rec(no *raiz, int dado){
    if(raiz==NULL){
        no *novo = malloc(sizeof(no));
        novo->cor=VERMELHO;
        novo->dado=dado;
        novo->dir=NULL;
        novo->esq=NULL;
        return novo;
    }

    if(dado < raiz->dado) raiz->esq= insere_rec(raiz->esq,dado);
    else raiz->dir = insere_rec(raiz->dir, dado);
    return corrige(raiz);
}

no *insere(no *raiz, int dado){
    raiz=insere_rec(raiz, dado);
    raiz->cor=PRETO;
    return raiz;
}

void pre_ordem(no *raiz){
    if(raiz==NULL) return;
    printf("%d ", raiz->dado);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
}

void em_ordem(no *raiz){
    if(raiz==NULL) return;
    em_ordem(raiz->esq);
    printf("%d ", raiz->dado);
    em_ordem(raiz->dir);
}

void pos_ordem(no *raiz){
    if(raiz==NULL) return;
    pos_ordem(raiz->esq);
    pos_ordem(raiz->dir);
    printf("%d ",raiz->dado);
}

int main(){
    
    no *arvore = malloc(sizeof(no));
    insere(arvore,12);
    /*int v[6]= {12,4,16,2,8,6};

    for(int i =0; i<6;i++){
        insere(arvore,v[i]);
    }
   em_ordem(arvore);
    printf("\n");
    pre_ordem(arvore);
    printf("\n");
    pos_ordem(arvore);
    printf("\n");*/
}