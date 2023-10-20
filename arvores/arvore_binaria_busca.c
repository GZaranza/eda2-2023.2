#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *esq;
    struct no *dir;
}no;

no *busca(no *raiz, int ch){

    while(raiz!=NULL && raiz->dado!=ch){
        if(ch < raiz->dado){
            raiz = raiz->esq;
        }
        else raiz = raiz->dir;
    }
    return raiz;
}

no *insere(no *raiz, int ch){
    if(raiz==NULL){
        no *novo=malloc(sizeof(no));
        novo->dado=ch;
        novo->esq=NULL;
        novo->dir=NULL;
        return novo;
    }
    if(ch < raiz->dado){
        raiz->esq = insere(raiz->esq,ch);
    }
    else raiz->dir = insere(raiz->dir, ch);
    return raiz;
}

no *min(no *raiz){
    if(raiz->esq==NULL){
        return raiz;
    }

    return min(raiz->esq);

}

no *delmin(no *raiz){
    if(raiz->esq==NULL) return raiz->dir;

    raiz->esq = delmin(raiz->esq);
    return raiz;
}

no *remover(no *raiz, int ch){
    if(raiz==NULL) return NULL;
    if(ch < raiz->dado) raiz->esq = remover(raiz->esq,ch);
    else if (ch > raiz->dado) raiz->dir = remover(raiz->dir,ch);
    else{
        if(raiz->esq==NULL) return raiz->dir;
        else if(raiz->dir==NULL) return raiz->esq;
        
        no *aux=raiz;
        raiz=min(aux->dir);
        raiz->dir=delmin(aux->dir);
        raiz->esq=aux->esq;
        
        
    }
    return raiz;
}

void imprimir(no *raiz){
    if(raiz == NULL)return;
    printf("%d ", raiz->dado);
    imprimir(raiz->esq);
    imprimir(raiz->dir);
}

int main(){

no *arvore = malloc(sizeof(no));

insere(arvore,1);
insere(arvore, 4);
insere(arvore, 5);
insere(arvore, 3);

imprimir(arvore);
printf("\n");
remover(arvore, 1);
imprimir(arvore);

}