#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
    char cidade[30];
    struct celula *prox;
}celula;

typedef struct cabeca{
    int num_itens;
    celula *prox;
    celula *ultimo;
}cabeca;

void inserir(cabeca *le, char nova_cidade[30]){
    celula *nova = malloc(sizeof(celula));
    strcpy(nova->cidade,nova_cidade);
    nova->prox=NULL;

    if(le->prox==NULL){
        le->prox=nova;
    }
    else{
        le->ultimo->prox=nova;
    }

    le->ultimo=nova;
    le->num_itens++;
}

void mover_pro_final(cabeca *le, celula *x){
    celula *atual;
    
    atual = le->prox;

    while(atual->prox != x){
        atual = atual->prox;
    }

    atual->prox = x->prox;
    
    le->ultimo->prox=x;
    le->ultimo=x;
    x->prox=NULL;
    
}

void organizar_lista(cabeca *le){
    celula *aux;
   
    aux = le->prox;
    
    while(aux!=NULL){
        
        if(aux->cidade[strlen(aux->cidade)-1]-32 == aux->prox->cidade[0]){
            //mover_pro_final(le,aux->prox);
            printf("entrou\n");
        }

        aux=aux->prox;
    }
}

void imprimir(cabeca *le){
    
    celula *aux;
    aux=le->prox;
    while(aux!=NULL){
        
        printf("%s->", aux->cidade);
        aux=aux->prox;
    }
}


int main(){

   cabeca *le = malloc(sizeof(cabeca));
   le->num_itens=0;
   le->prox=NULL;
   le->ultimo=NULL;

   char nova_cidade[30];

   while (scanf("%s", nova_cidade)==1){

        inserir(le,nova_cidade);
   }
    printf("IMPRIMINDO AS ENTRADAS:\n");
    imprimir(le);
    //mover_pro_final(le,le->prox->prox);
    printf("\nIMPRMINDO A LISTA FINAL:\n");
    organizar_lista(le);
    imprimir(le);
    //printf("%d", strlen(le->prox->cidade));

    return 0;
}