#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

typedef struct {
    celula *tb; // tabela hash
    int M; // tamanho da tabela hash
    int N; // total de chaves presentes na tabela
} TH;

int LEremove(celula *le, int ch){
    
    celula *anterior=le;
    celula *proximo= le->prox;

    while(proximo->dado!=ch && proximo!=NULL){
        anterior=proximo;
        proximo=proximo->prox;
    }

    if(proximo==NULL){
        return -1;
    }

    if(proximo->dado==ch){
        anterior->prox=proximo->prox;
        return 0;
    }

}

int LEbusca(celula *le, int ch){
    celula *aux= le->prox;

    while(aux!=NULL ){
        if(aux->dado==ch){
            return 1;
        }
        aux=aux->prox;
    }
    return 0;
}

void LEinsere (celula *le, int ch){

    celula *novo = malloc(sizeof(celula));
    novo->dado=ch;
    novo->prox=le->prox;
    le->prox=novo;
}

int hash(TH *h, int ch){
    return ch%h->M;
}

void THinsere (TH *h, int ch){
    int hashing = hash(h, ch);
    LEinsere(&h->tb[hashing], ch);
}

int THremove (TH *h, int ch){
    int hashing = hash(h,ch);
    return LEremove(&h->tb[hashing], ch);
    
}

int THbusca (TH *h, int ch){
    int hashing = hash(h,ch);
    return LEbusca(&h->tb[hashing], ch);
}