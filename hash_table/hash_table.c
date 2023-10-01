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

    while(proximo!=NULL && proximo->dado!=ch ){
        anterior=proximo;
        proximo=proximo->prox;
    }

    if(proximo!=NULL){
        anterior->prox=proximo->prox;
        free(proximo);
        return 0;
    }

    else return -1;
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


int THremove (TH *h, int ch){
    int hashing = hash(h,ch);
    return LEremove(&h->tb[hashing], ch);
    
}

int THbusca (TH *h, int ch){
    int hashing = hash(h,ch);
    int busca = LEbusca(&h->tb[hashing], ch);
    return busca;
}

void THinsere (TH *h, int ch){
    int hashing = hash(h, ch);
    
    /*int busca;
    busca = THbusca(h, ch);*/

    LEinsere(&h->tb[hashing], ch);
}


int main(){

   TH *tabela = malloc(sizeof(TH));
   celula vetor[13];
   tabela->M = 13;
   tabela->N = 1000;
   tabela->tb = vetor; 

    for(int i =0;i<1000;i++){
        THinsere(tabela, i);
    }

    printf("%d\n", THbusca(tabela, 950));
    //printf("%d\n", THremove(tabela, 0));
}