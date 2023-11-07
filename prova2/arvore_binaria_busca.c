#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *esq;
    struct no *dir;
}no;

no *cria_no(int dado){
    no *arvore = malloc(sizeof(no));
    arvore->dado = dado;
    arvore->esq = NULL;
    arvore->dir = NULL;
    return arvore;
}

no *busca(no *raiz, int dado){

    while(raiz != NULL && raiz->dado != dado){
        if(dado < raiz->dado){
            raiz = raiz->esq;
        }
        else raiz =  raiz->dir;
    }
    //se raiz = null, o dado n existe na arvore, então retorna 0
    if(raiz==NULL){
        return cria_no(0);
    }
    else return raiz;

}

no *insere(no *raiz, int dado){
    if(raiz == NULL){
        return cria_no(dado);
    }

    if(dado < raiz->dado){
        raiz->esq = insere(raiz->esq,dado);
    }
    else{
        raiz->dir = insere(raiz->dir,dado);
    }

    return raiz;

}

no *removesucessor(no *raiz, int *dado){
    if(raiz->esq==NULL){
        *dado = raiz->dado;
        return raiz->dir;
    }
    raiz->esq=removesucessor(raiz->esq,dado);
    return raiz;
}

no *remover(no *raiz, int dado){
    
    if(raiz == NULL) return NULL;

    if(dado < raiz->dado) raiz->esq = remover(raiz->esq,dado);
    else if (dado > raiz->dado) raiz->dir = remover(raiz->dir,dado);
    else{
        if(raiz->esq==NULL) return raiz->dir;
        else if(raiz->dir==NULL) return raiz->esq;
        else{
            int novoDado;
            raiz->dir=removesucessor(raiz->dir,&novoDado);
            raiz->dado=novoDado;
        }
        
    }
    return raiz;
}

void em_ordem(no *raiz){
    if(raiz==NULL) return;
    em_ordem(raiz->esq);
    printf("%d ", raiz->dado);
    em_ordem(raiz->dir);
}

void preorderm(no *raiz){
    if(raiz==NULL) return;
    printf("%d ", raiz->dado);
    preorderm(raiz->esq);
    preorderm(raiz->dir);
}

void posorderm(no *raiz){
    if (raiz==NULL) return;
    posorderm(raiz->esq);
    posorderm(raiz->dir);
    printf("%d ", raiz->dado);
}

int main(){

    int v[15]= {21,14,28,11,18,25,32,5,12,15,19,23,27,30,37};

    no *arvore = malloc(sizeof(no));
    
    for(int i =0; i<15;i++){
        insere(arvore, v[i]);
    }

    posorderm(arvore);

    remover(arvore,11);
    printf("\n");
    posorderm(arvore);
    printf("\n");

}