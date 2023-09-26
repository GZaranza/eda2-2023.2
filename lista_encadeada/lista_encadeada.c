#include <stdio.h>
#include <stdlib.h>
#include "ordenacoes.h"

typedef struct celula{
    struct celula *prox;
    int dado;
} celula;

typedef struct cabeca{
    int num_itens;
    celula *prox;
} cabeca;

celula *criar_celula (int dado){
    celula *no = malloc(sizeof(celula));
    no->dado = dado;
    no->prox = NULL;
    return no;
}

celula *criar_lista (){
    celula *head = malloc(sizeof(celula));
    head->dado=0;
    head->prox=NULL;
    return head;
}

int vazia(celula*le){
    return (le->prox == NULL);
}

void insere_inicio(celula *le, int x){

    celula *nova = criar_celula(x);

    nova->prox=le->prox;
    le->prox=nova;
}

void insere_antes(celula *le, int x, int y){
    celula *aux = le->prox;

    if(aux->prox->dado != y){
        insere_antes(aux->prox,x,y);
    }

    celula *nova = criar_celula(x);

    nova->prox=le->prox;
    le->prox=nova;
    return;

}

void imprime (celula *le){
    celula *aux = le->prox;
    while(aux != NULL){
        printf("%d -> ", aux->dado);
        aux=aux->prox;
    }
    printf("NULL\n");

}

void imprime_rec(celula *le){
    if(le!=NULL){
        printf("%d -> ", le->dado);
        imprime_rec(le->prox);
    }
    else{
        printf("NULL\n");
    }
}

int main(){

    celula *le = criar_celula(0);

    insere_inicio(le,1);
    insere_inicio(le,2);
    insere_inicio(le,3);
    
    imprime(le);
    printf("\n\n");
    imprime_rec(le);

}