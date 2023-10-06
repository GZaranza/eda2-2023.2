#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
    char cidade[30];
    struct celula *prox;
    int prox_repetiu;
}celula;

typedef struct cabeca{
    int num_itens;
    celula *prox;
    celula *ultimo;
}cabeca;

void inserir(cabeca *le,cabeca *repetidas, char nova_cidade[30]){
    celula *nova = malloc(sizeof(celula));
    strcpy(nova->cidade,nova_cidade);
    nova->prox_repetiu=0;
    nova->prox=NULL;

    if(le->prox==NULL){
        le->prox=nova;
        le->ultimo=nova;
        le->num_itens++;
    }
    else{
        if(le->ultimo->cidade[strlen(le->ultimo->cidade)-1]-32==nova_cidade[0] && le->ultimo->prox_repetiu==0){
            le->ultimo->prox_repetiu=1;
            if(repetidas->prox==NULL){
                repetidas->prox=nova;
                repetidas->ultimo=nova;
                repetidas->num_itens++;
            }
            else{
                repetidas->ultimo->prox=nova;
                repetidas->ultimo=nova;
                repetidas->num_itens++;
            }
            
        }
        else{
            le->ultimo->prox=nova;
            le->ultimo=nova;
            le->num_itens++;
        }
    }

    
}

void inserir_repetida(cabeca *le,cabeca *repetidas, char nova_cidade[30]){
    celula *nova = malloc(sizeof(celula));
    strcpy(nova->cidade,nova_cidade);
    nova->prox_repetiu=0;
    nova->prox=NULL;

    if(le->prox==NULL){
        le->prox=nova;
        le->ultimo=nova;
        le->num_itens++;
    }
    else{
        if(le->ultimo->cidade[strlen(le->ultimo->cidade)-1]-32==nova_cidade[0] && le->ultimo->prox_repetiu==0){
            le->ultimo->prox_repetiu=1;
            if(repetidas->prox==NULL){
                repetidas->prox=nova;
                repetidas->ultimo=nova;
                repetidas->num_itens++;
            }
            else{
                repetidas->ultimo->prox=nova;
                repetidas->ultimo=nova;
                repetidas->num_itens++;
            }
            
        }
        else{
            le->ultimo->prox=nova;
            le->ultimo=nova;
            le->num_itens++;
        }
    }

    
}

void imprimir(cabeca *le){
    
    celula *aux;
    aux=le->prox;
    while(aux!=NULL){
        
        printf("%s\n", aux->cidade);
        aux=aux->prox;
    }
}


int main(){

   cabeca *le = malloc(sizeof(cabeca));
   le->num_itens=0;
   le->prox=NULL;
   le->ultimo=NULL;

   cabeca *repetidas = malloc(sizeof(cabeca));
   le->num_itens=0;
   le->prox=NULL;
   le->ultimo=NULL;

   char nova_cidade[30];

   while (scanf("%s", nova_cidade)==1){
        inserir(le,repetidas,nova_cidade);
   }

   le->ultimo->prox=repetidas->prox;
    printf("\n\n");
    imprimir(le);
    
    
    return 0;
}