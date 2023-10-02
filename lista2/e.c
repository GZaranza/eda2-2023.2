#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    int id;
    char letra;
    struct celula *prox;
} celula;

typedef struct {
    celula *tb; // tabela hash
    int M; // tamanho da tabela hash
    int N; // total de chaves presentes na tabela
} TH;

void LEinicia(celula *le){
    le->prox=NULL;
    le->id=0;
    le->letra=' ';
}

int LEremove(celula *le, int ch){
    celula *anterior=le;
    celula *proximo= le->prox;

    while(proximo!=NULL && proximo->id!=ch ){
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
        if(aux->id==ch){
            return 1;
        }
        aux=aux->prox;
    }
    return 0;
}
void LEinsere (celula *le, int ch, char letra){
    celula *novo = malloc(sizeof(celula));
    novo->id=ch;
    novo->letra = letra;
    novo->prox=le->prox;
    le->prox=novo;
}

void LEimprime(celula *le){
    celula *aux=le->prox;
    while(aux!=NULL){
        printf("%c", aux->letra);
        aux = aux->prox;
    }
    printf("\n");
}

int hash(TH *h, int ch){
    return ch%h->M;
}

int THremove (TH *h, int ch){
    int hashing = hash(h,ch);
    int resultado = LEremove(&h->tb[hashing], ch);

    if(resultado==0) printf("\nA chava %d foi removida\n", ch);
    else printf("\nA chava %d nao foi removida, pois nao foi encontrada na tabela\n", ch);
    return resultado;
    
}

int THbusca (TH *h, int id){
    int hashing = hash(h,id);
    int busca = LEbusca(&h->tb[hashing], id);
    return busca;
}

void THinsere (TH *h, int id, char letra){
    int hashing = hash(h, id);
    int busca;
    busca = THbusca(h, id);
    if(busca==0){
        LEinsere(&h->tb[hashing], id, letra);
    }
    else return;
}

void THimprime(TH *h){
    for(int i = 0; i < h->M; i++){
        //printf("M = %d : ", i);
        LEimprime(&h->tb[i]);
    }
}

TH *THinicia(TH *h, int m){
    h->tb=malloc(sizeof(celula)*m);
    h->M=m;
    h->N=0;
    for(int i=0; i<m;i++){
        
        LEinicia(&h->tb[i]);
    }
    return h;
}

int main(){

    int tam_TH = 104677;
    TH *tabela=malloc(sizeof(TH));
    tabela=THinicia(tabela, tam_TH);

    int id;
    char letra;

    while(scanf("%d %c",&id, &letra)== 2){
    }

    return 0;
}


