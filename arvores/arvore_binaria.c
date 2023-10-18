#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *esq;
    struct no *dir;
}no;

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;



celula *pilha;

void criar_pilha(){
    pilha =malloc(sizeof(celula));
    pilha->prox=NULL;

}

void empilha(no *no){
    celula *novo=malloc(sizeof(celula));
    novo->dado=no->dado;
    novo->prox=pilha->prox;
    pilha->prox=novo;
}

void desempilha(no *no){
    celula *lixo;
    lixo=pilha->prox;
    pilha->prox=lixo->prox;
    printf(" %d", lixo->dado);
    free(lixo);
}

void liberar_pilha(){
    pilha->prox=NULL;
}

no *busca(no *raiz, int x){

    if(raiz==NULL || raiz->dado==x) return raiz;

    if(raiz->dado > x) return busca(raiz->esq,x);
    else return busca(raiz->dir, x);

}

no *insere(no *raiz, no *novo){
    //arvore vazia, portanto o novo no eh a arvore
    if(raiz==NULL) return novo;
    if(raiz->dado > novo->dado) raiz->esq = insere(raiz->esq,novo);
    else raiz->dir = insere(raiz->dir, novo);
    return raiz;
}

no *criar_no(int dado){
    no *novo = malloc(sizeof(no));

    novo->dado =dado;
    novo->esq=NULL;
    novo->dir=NULL;
    return novo;

}

no *cria_arvore(int dado){
    no *novo = malloc(sizeof(no));
    novo->dado=dado;
    novo->dir=NULL;
    novo->esq=NULL;
    return novo;
}

void pi_preordem(no *raiz){

    criar_pilha();
    empilha(raiz);
    
    while(pilha->prox!=NULL){
        
    }

}

void preordem(no *raiz){

    if(raiz==NULL) return;

    printf("%d ", raiz->dado);
    preordem(raiz->esq);
    preordem(raiz->dir);
}

void em_ordem(no *raiz){
    if(raiz==NULL) return;

    em_ordem(raiz->esq);
    printf(" %d", raiz->dado);
    em_ordem(raiz->dir);   
}

void posordem(no *raiz){

    if(raiz==NULL)return;
    posordem(raiz->esq);
    posordem(raiz->dir);
    printf(" %d", raiz->dado);

}

int main(){

    no *arvore = cria_arvore(21);
    for(int i=0;i<15;i++){
        int x;
        scanf("%d",&x);
        no *novo = criar_no(x);
        insere(arvore, novo);
    }

    preordem(arvore);
    printf("\n");
    em_ordem(arvore);
    printf("\n");
    posordem(arvore);
    printf("\n");
}