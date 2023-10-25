#include <stdio.h>
#include <stdlib.h>

enum cor {VERMELHO, PRETO};

typedef struct no{
    int chave;
    enum cor cor;
    struct no *esq, *dir;
}no;


int ehVermelho(no  *x){
    if(x==NULL) return 0;
    return x->cor == VERMELHO;

}

int ehPreto(no *x){
    if(x==NULL) return 0;
    return x->cor==VERMELHO;
}

no *rotaciona_esq(no *raiz){
    no *aux = raiz->dir;
    raiz->dir=aux->esq;
    aux->esq=raiz;
    aux->cor=raiz->cor;
    raiz->cor=VERMELHO;
    return aux;
}

no *rotaciona_dir(no *raiz){
    no *aux=raiz->esq;
    raiz->esq= aux->dir;
    aux->dir=raiz;
    aux->cor=raiz->cor;
    raiz->cor=VERMELHO;
    return aux;


    return aux;
}


int main(){
}