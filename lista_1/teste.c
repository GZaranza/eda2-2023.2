#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    struct celula *prox;
    int dado;
} celula;


int remove_depois (celula *p){

    if(p == NULL || p->prox==NULL){
       return;
    }
    celula *aux=p->prox;
    p->prox = aux->prox;
    free(aux);
}

void remove_elemento (celula *le, int x){
    
    celula *ant=le;
    celula *pro=le->prox;

    while(pro->dado!=x && pro!=NULL){
        ant=pro;
        pro = pro->prox;
    }
    
   if(pro->dado == x){
        ant->prox=pro->prox;
        free(pro);
   }
    
}

void remove_todos_elementos (celula *le, int x){
    
    celula *ant=le;
    celula *pro=le->prox;
    
   while( pro !=NULL){
        if(pro->dado ==x){
            ant->prox=pro->prox;
            celula *aux = pro;
            pro=pro->prox;
            free(aux);
        }
        else{
            ant=pro;
            pro=pro->prox;
        }
   }
}