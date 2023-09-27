#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3){

    celula *anterior = l3;
    celula *proximo = l3->prox;

    while(l1!=NULL && l2!=NULL){
        if(l1->dado <= l2->dado){
            anterior->prox = l1;
            proximo = l1->prox;
        }
        else{
            anterior->prox =l2;
            proximo =l2->prox;
        }
        anterior=proximo;
        proximo=proximo->prox;
    }
}