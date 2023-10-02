#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3){

    celula *anterior = l3;
    l1 = l1->prox;
    l2 = l2->prox;

    if(l1==NULL) anterior->prox=l2;
    if(l2==NULL) anterior->prox=l1;

    while(l1!=NULL && l2!=NULL){

        if(l1->dado < l2->dado){
            anterior->prox = l1;
            l1 = l1->prox;
        }
        else{
            anterior->prox =l2;
            l2 =l2->prox;
        }
        anterior=anterior->prox;
    }

    while(l1!=NULL){
        anterior->prox = l1;
        l1 = l1->prox;
        anterior=anterior->prox;
    }

    while(l2!=NULL){
        anterior->prox = l2;
        l2 = l2->prox;
        anterior=anterior->prox;
    }
    
}