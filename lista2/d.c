#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa{
    int id;
    char primeiro_nome[30];
    char ultimo_nome[30];
    char telefone[30];
    char dt_nascimento[30];
    struct pessoa *prox;
}pessoa;

typedef struct {
    pessoa *tb; // tabela hash
    int M; // tamanho da tabela hash
    int N; // total de chaves presentes na tabela
} TH;

pessoa *cria_pessoa(int id, char primeiro_nome[], char ultimo_nome[], char dt_nasc[], char telefone[]){
    pessoa *nova=malloc(sizeof(pessoa));
    nova->prox=NULL;
    nova->id=id;
    
    strcpy(nova->primeiro_nome, primeiro_nome);
    strcpy(nova->ultimo_nome, ultimo_nome);
    strcpy(nova->dt_nascimento, dt_nasc);
    strcpy(nova->telefone, telefone);

    return nova;
}

void LEinicia(pessoa *le){
    le->prox=NULL;
    le->id=-1;
    strcpy(le->primeiro_nome, " ");
    strcpy(le->ultimo_nome, " ");
    strcpy(le->dt_nascimento, " ");
    strcpy(le->telefone, " ");

    /*le->primeiro_nome=' ';
    le->ultimo_nome=' ';
    le->telefone=' ';
    le->dt_nascimento=' ';*/
}

void LEinsere(pessoa *le, int id, char primeiro_nome[], char ultimo_nome[], char dt_nasc[], char telefone[]){
    
    pessoa *nova = cria_pessoa(id,primeiro_nome,ultimo_nome,dt_nasc,telefone);

    nova->prox=le->prox;
    le->prox=nova;

}

void LEimprime(pessoa *le){
    
    pessoa *aux=le->prox;

    while(aux!=NULL){
        printf("\n%s %s %s %s", aux->primeiro_nome,aux->ultimo_nome,aux->dt_nascimento,aux->telefone);
        aux=aux->prox;
    }

}



int hash(TH *h, int ch){
    return ch%h->M;
}


void THinsere(TH *h, int id, char primeiro_nome[], char ultimo_nome[], char dt_nasc[], char telefone[]){

    int hashing = hash(h, id);

    LEinsere(&h->tb[hashing], id, primeiro_nome, ultimo_nome, dt_nasc, telefone);

}

TH *THinicia(TH *h,int  m){

    h->tb=malloc(sizeof(pessoa)*m);
    h->M=m;
    h->N=0;

    for(int i = 0; i<m; i++){
        LEinicia(&h->tb[i]);
    }
    return h;

}

void THimprime(TH *h){

    for(int i=0; i<h->M;i++){
        LEimprime(&h->tb[i]);
    }

}

int main(){
    
    int tam_TH = 13;
    TH *tabela=malloc(sizeof(TH));
    tabela=THinicia(tabela, tam_TH);;

    char comando[6];

    while(scanf("%s",comando)==1){

        //adicionando uma pessoa    
        if(strcmp(comando,"add")==0){
            int id;
            char first_name[20];
            char last_name[20];
            char birthday[15];
            char phone_number[20];
            scanf(" %d %s %s %s %s", &id, first_name,last_name,birthday,phone_number);
            THinsere(tabela,id, first_name,last_name,birthday,phone_number);
        }
        //THimprime(tabela);
    }

    
    return 0;
}