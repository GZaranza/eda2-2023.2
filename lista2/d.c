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
    pessoa *anterior=le;
    pessoa *proximo= le->prox;

    while(proximo!=NULL && proximo->id < id ){
        anterior=proximo;
        proximo=proximo->prox;
    }

    if(proximo!=NULL){
        nova->prox = proximo;
        anterior->prox=nova;
        free(proximo);
    }
    else{
        le->prox=nova;
        nova->prox=NULL;
    }

}

void LEimprime_toda(pessoa *le){
    
    pessoa *aux=le->prox;

    while(aux!=NULL){
        printf("\n%s %s %s %s", aux->primeiro_nome,aux->ultimo_nome,aux->dt_nascimento,aux->telefone);
        aux=aux->prox;
    }

}

void LEimprime_pessoa(TH *h, char bd[],char fn[], char ln[], char pn[]){
    
    for(int i=0; i<h->M;i++){
        pessoa *cabeca;
        cabeca=&h->tb[i];

        pessoa *aux = cabeca->prox;

        while(aux!=NULL){
            if(strcmp(aux->dt_nascimento,bd)==0 || strlen(bd)==0){

                if(strcmp(aux->primeiro_nome,fn)==0 || strlen(fn)==0){
                
                    if(strcmp(aux->primeiro_nome,ln)==0 || strlen(ln)==0){
                    
                        if(strcmp(aux->primeiro_nome,pn)==0 || strlen(pn)==0){
                            printf("oii %s %s %s %s", aux->primeiro_nome,aux->ultimo_nome,aux->dt_nascimento,aux->telefone);
                            return;
                        }
                    }
                }

            }


            aux=aux->prox;
        }
    }

    printf("oi\n");
    return;

}

int LEbusca(pessoa *le, int id){
    pessoa *aux=le->prox;

    while(aux!=NULL){
        if(aux->id==id){
            return 1;
        }
        aux=aux->prox;
    }

    return 0;

}

int LEremove(pessoa *le, int id){
    pessoa *aux=le;
    pessoa *proximo=le->prox;

    while(proximo!=NULL && proximo->id!=id  ){
        aux=aux->prox;
        proximo=proximo->prox;
    }

    if(proximo!=NULL){//achou o elemento a ser removido
        aux->prox=proximo->prox;
        free(proximo);
        return 1;
    }
    return 0;//n achou o elemento

}

int hash(TH *h, int ch){
    return ch%h->M;
}


void THinsere(TH *h, int id, char primeiro_nome[], char ultimo_nome[], char dt_nasc[], char telefone[]){

    int hashing = hash(h, id);
    int busca = LEbusca(&h->tb[hashing],id);

    if(busca==0){//n achou o id, ou sej, n foi cadastrado
        LEinsere(&h->tb[hashing], id, primeiro_nome, ultimo_nome, dt_nasc, telefone);
    }
    else printf("ID %d ja cadastrado.\n", id);

    
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

void THremove(TH *h, int id){
    int hashing = hash(h, id);
    int remove = LEremove(&h->tb[hashing], id);
    if(remove==0){
        printf("ID %d nao existente\n", id);
    }

}


void THbusca(TH *h, int id){
    int hashing = hash(h, id);
    int busca = LEbusca(&h->tb[hashing], id);
    if(busca==1){
        printf("%d\n", id);
    }
    else printf("ID %d nao existente\n", id);
}

void THimprime_pessoa(TH *h, char bd[],char fn[], char ln[], char pn[]){

    LEimprime_pessoa(h, bd,fn,ln,pn);
    
}

void THimprime_toda(TH *h){

    for(int i=0; i<h->M;i++){
        LEimprime_toda(&h->tb[i]);
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
        
        else if (strcmp(comando,"del")== 0){
            int id;
            scanf(" %d", &id);
            THremove(tabela, id); 
        }

        else if (strcmp(comando,"info")== 0){
            int id;
            scanf(" %d", &id);
            THbusca(tabela, id);
        }

        else if (strcmp(comando,"query")== 0){
            char bd[15];
            char fn[20];
            char ln[20];
            char pn[20];
            scanf(" %s %s %s %s", bd,fn,ln,pn);
            THimprime_pessoa(tabela, bd,fn,ln,pn);
        }
        
    }

    
    return 0;
}