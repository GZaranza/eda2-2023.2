#include <stdio.h>
#include <stdlib.h>
#include "ordenacoes.h"

typedef struct celula{
    struct celula *prox;
    int dado;
} celula;

celula *criar_celula (int dado){
    celula *no = malloc(sizeof(celula));
    no->dado = dado;
    no->prox = NULL;
    return no;
}

celula *criar_lista (){
    celula *head = malloc(sizeof(celula));
    head->dado=0;
    head->prox=NULL;
    return head;
}

int vazia(celula*le){
    return (le->prox == NULL);
}

void insere_inicio(celula *le, int x){

    celula *nova = criar_celula(x);

    nova->prox=le->prox;
    le->prox=nova;
}

void insere_antes(celula *le, int x, int y){
    
    celula *novo = malloc(sizeof(celula));
    novo->dado=x;

    celula *aux = le;
    celula *aux_prox=le->prox;

    while (aux_prox!=NULL && aux_prox->dado!=y ){
        aux=aux_prox;
        aux_prox=aux_prox->prox;
    }

    novo->prox=aux_prox;
    aux->prox=novo;

}

int remove_depois(celula *p){
    celula *aux;
    aux = p->prox;

    if(aux->prox==NULL){
        p->prox=NULL;
    }

    else p->prox = aux->prox;

    return aux->dado;
}

void remove_elemento(celula *le, int x){
    
    celula *aux, *aux_prox;
    aux = le;
    aux_prox = le->prox;

    while(aux_prox!=NULL && aux_prox->dado!=x){
        aux=aux_prox;
        aux_prox = aux_prox->prox;
    }
    
    if(aux_prox != NULL){
        aux->prox = aux_prox->prox;
        free(aux_prox);
    }
}

void remove_todos_elementos(celula *le, int x){
    celula *aux, *aux_prox;
    aux = le;
    aux_prox = le->prox;

    int count=0;

    while(aux_prox!=NULL){
        if(aux_prox->dado==x) count++;
        aux=aux_prox;
        aux_prox = aux_prox->prox;
    }
    

    for(int i=0;i<=count;i++){
        while(aux_prox!=NULL && aux_prox->dado!=x){
        aux=aux_prox;
        aux_prox = aux_prox->prox;
        }
    
        if(aux_prox != NULL){
            aux->prox = aux_prox->prox;
            free(aux_prox);
        }

        aux = le;
        aux_prox = le->prox;
    }
}

celula *busca(celula *le, int x){
    celula *aux;

    aux = le;

    while(aux!=NULL && aux->dado!=x){
        aux = aux->prox;
    }

    return aux;

}

celula *busca_rec(celula *le, int x){

    if(le==NULL) return NULL;
    if(le->dado ==x) return le;
    return busca_rec(le->prox, x);
}

void imprime (celula *le){
    celula *aux = le->prox;

    while(aux != NULL){
        printf("%d -> ", aux->dado);
        aux=aux->prox;
    }

    printf("NULL\n");

}

void imprime_rec(celula *le){

    if(le==NULL || le->prox==NULL){

        printf("NULL\n");

        return;
    }

    printf("%d -> ", le->prox->dado);

    imprime_rec(le->prox);
}

int main(){

    celula *le = criar_celula(0);

    insere_inicio(le,3);
    insere_inicio(le,2);
    insere_inicio(le,4);
    insere_inicio(le,2);
    insere_inicio(le,5);
    insere_inicio(le,2);

    imprime(le);
    printf("\n");


    celula *b = busca_rec(le, 2);

    printf("%d\n", b->dado);


    /*remove_depois(le);
    imprime(le);
    printf("\n");*/

    //insere_antes(le, 4, 1);


   /*remove_depois(le);
    imprime(le);
    printf("\n");

    remove_todos_elementos(le, 2);
    
    imprime(le);
    printf("\n");

    remove_depois(le);
    imprime(le);
    printf("\n");

    remove_elemento(le, 1);

    imprime(le);
    printf("\n");
    */

}