#include <stdio.h>

typedef struct celula{
    struct celula *prox;
    int dado;
} celula;


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
    