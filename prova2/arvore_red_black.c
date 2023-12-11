#include <stdio.h>
#include <stdlib.h>

enum cor {VERMELHO, PRETO};

typedef struct no{
    int dado;
    struct no *esq, *dir;
    enum cor cor;
}no;

no *rotacao_esquerda(no *raiz){
    no *x= raiz->dir;
    raiz->dir=x->esq;
    x->esq=raiz;
    x->cor=raiz->cor;
    raiz->cor=VERMELHO;
    return x;
}

no *rotacao_direita(no *raiz){
    no *a=raiz->esq;
    raiz->esq=a->dir;
    a->dir=raiz;
    a->cor=raiz->cor;
    raiz->cor=VERMELHO;
    return a;
}

void *sobe_cor(no *raiz){
    raiz->cor=VERMELHO;
    raiz->esq->cor=PRETO;
    raiz->dir->cor=PRETO;
}

no *corrige(no * raiz){
    if(raiz->esq->cor==PRETO && raiz->dir->cor==VERMELHO){
        return rotacao_esquerda(raiz);
    }
    if(raiz->esq->cor==VERMELHO && raiz->dir->cor==VERMELHO){
        sobe_cor(raiz);
        return raiz;
    }
    if(raiz->esq->cor=VERMELHO && raiz->esq->esq->cor==VERMELHO){
        raiz=rotacao_direita(raiz);
        sobe_cor(raiz);
        return raiz;
    }
    return raiz;
}

no *insere(no *raiz, int dado){
    raiz=insere_rec(raiz,dado);
    raiz->cor=PRETO;
    return raiz;
}

no *insere_rec(no *raiz,int dado){
    if(raiz==NULL){
        no *novo=malloc(sizeof(no));
        novo->esq=NULL;
        novo->dir=NULL;
        novo->cor=VERMELHO;
        novo->dado=dado;
        return novo;
    }

    if(dado < raiz->dado) raiz->esq=insere_rec(raiz->esq,dado);
    else raiz->dir=insere_rec(raiz->dir,dado);
    return corrige(raiz);
}





int main(){

}