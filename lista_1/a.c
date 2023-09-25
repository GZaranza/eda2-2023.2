#include <stdio.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void imprime (celula *le){
   celula *aux;

   for(aux = le ;aux!=NULL;aux=aux->prox){
        printf("%d -> ", aux->dado);
   }
    printf("NULL\n");
   
}

void imprime_rec (celula *le){
    if(le == NULL){
        printf("NULL");
    }
    else{
        printf("%d ->", le->dado);
        imprime_rec(le->prox);
    }
}
