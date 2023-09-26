#include <stdio.h>

typedef struct celula{
    struct celula *prox;
    int dado;
} celula;

celula *busca(celula *le, int x){
    celula *aux;

    aux = le;

    while(aux->dado!=x){
        aux = aux->prox;
    }

    return aux;

}

celula *busca_rec(celula *le, int x){

    if(le==NULL) return NULL;
    if(le->dado ==x) return le;
    return busca_rec(le->prox, x);
}