#include <stdio.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

void imprime (celula *le){
    celula *aux = le->prox;
    while(aux != NULL){
        printf("%d -> ", aux->dado);
        aux=aux->prox;
    }
    printf("NULL\n");
}

void imprime_rec (celula *le){
    

   if(le==NULL || le->prox==NULL){

        printf("NULL\n");

        return;
    }

    printf("%d -> ", le->prox->dado);
    
    imprime_rec(le->prox);
}
