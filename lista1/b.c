#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio (celula *le, int x){
    celula *novo = malloc(sizeof(celula));
    novo->dado=x;

    novo->prox=le->prox;
    le->prox=novo;

}

void insere_antes (celula *le, int x, int y){
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
   