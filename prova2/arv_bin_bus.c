#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int dado;
    struct no *esq;
    struct no *dir;
}no;

no *cria_no(int dado){
    no *novo = malloc(sizeof(no));
    novo->dado=dado;
    novo->dir=NULL;
    novo->esq=NULL;
    return novo;
}

no *busca(no *raiz, int dado){

    if(raiz == NULL || raiz->dado == dado) return raiz;

    if(dado < raiz->dado) return busca(raiz->esq,dado);

    else return busca(raiz->dir,dado);
    

}

no *insere(no *raiz, int dado){

    if (raiz==NULL) return cria_no(dado);

    if(dado < raiz->dado) raiz->esq = insere(raiz->esq,dado);
    else raiz->dir = insere(raiz->dir,dado);
    return raiz;
}

no *removersucessor(no *raiz, int *dado){
    if(raiz->esq==NULL){
        *dado=raiz->dado;
        return raiz->dir;
    }
    raiz->esq=removersucessor(raiz->esq,dado);
    return raiz;
}  

no *remover(no *raiz, int dado){
   if(raiz==NULL) return NULL;

   if(dado < raiz->dado) raiz->esq=remover(raiz->esq,dado);
   else if(dado > raiz->dado) raiz->dir=remover(raiz->dir,dado);
   else{
        int novoDado;
        raiz->dir=removersucessor(raiz->dir,&novoDado);
        raiz->dado=novoDado;
   }
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

    no *arvore = cria_no(12);
    
    int v[6]= {12,4,16,2,8,6};

    for(int i =1; i<6;i++){
        insere(arvore,v[i]);
    }

    no *aux = busca(arvore,10);
    //printf("%d\n", aux->dado);
    //remover(arvore,5);
    aux = busca(arvore,6);
    //printf("%d\n", aux->dado);
    em_ordem(arvore);
    printf("\n");
    pre_ordem(arvore);
    printf("\n");
    pos_ordem(arvore);
    printf("\n");



}