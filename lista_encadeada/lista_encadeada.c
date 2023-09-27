#include <stdio.h>
#include <stdlib.h>
#include "ordenacoes.h"

typedef struct celula{
    struct celula *prox;
    int dado;
} celula;

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

int remove_depois (celula *p){

    if(p == NULL || p->prox==NULL){
       return 0;
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

celula *busca(celula *le, int x){

    celula *aux= le;

    while(aux!=NULL && aux->dado!=x){
        aux = aux->prox;
    }

    return aux;

}

celula *busca_rec(celula *le, int x){

    if(le==NULL) return NULL;
    if(le->dado ==x) return le;
    return busca_rec(le->prox, x);
}

void imprime (celula *le){
    celula *aux = le->prox;

    while(aux != NULL){
        printf("%d -> ", aux->dado);
        aux=aux->prox;
    }

    printf("NULL\n");

}

void mescla_listas (celula *l1, celula *l2, celula *l3){

    celula *anterior = l3;
    celula *proximo = l3->prox;

    while(l1!=NULL && l2!=NULL){
        if(l1->dado < l2->dado){
            anterior->prox=l1->prox;
            l1=l1->prox;
        }
        else{
            anterior->prox=l2;
            l2=l2->prox;
        }
        anterior=anterior->prox;
        proximo=proximo->prox;
    }
}

void imprime_rec(celula *le){

    if(le==NULL || le->prox==NULL){

        printf("NULL\n");

        return;
    }

    printf("%d -> ", le->prox->dado);

    imprime_rec(le->prox);
}

int main(){

    celula *l1 = criar_celula(0);
    celula *l2 = criar_celula(0);
    celula *l3 = criar_celula(0);

    insere_inicio(l1,5);
    insere_inicio(l1,3);
    insere_inicio(l1,1);

    insere_inicio(l2,6);
    insere_inicio(l2,4);
    insere_inicio(l2,2);

    imprime(l1);
    printf("\n");
    imprime(l2);
    printf("\n");
    
    mescla_listas(l1,l2,l3);

    imprime(l3);
    printf("\n");



    /*remove_depois(le);
    imprime(le);
    printf("\n");*/

    //insere_antes(le, 4, 1);


   /*remove_depois(le);
    imprime(le);
    printf("\n");

    remove_todos_elementos(le, 2);
    
    imprime(le);
    printf("\n");

    remove_depois(le);
    imprime(le);
    printf("\n");

    remove_elemento(le, 1);

    imprime(le);
    printf("\n");
    */

}