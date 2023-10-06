#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
    struct celula *ant;
} celula;

typedef struct {
    celula *tb; // tabela hash
    int M; // tamanho da tabela hash
    int N; // total de chaves presentes na tabela
} TH;

void LEinicia(celula *le){
    le->prox=NULL;
    le->dado=0;
    le->ant=NULL;
}

int LEremove(celula *le, int ch){
    
    celula *anterior=le;
    celula *proximo= le->prox;

    while(proximo!=NULL && proximo->dado!=ch ){
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
        if(aux->dado==ch){
            return 1;
        }
        aux=aux->prox;
    }
    return 0;
}
void LEinsere (celula *le, int ch){

    celula *novo = malloc(sizeof(celula));
    novo->dado=ch;

    celula *aux =
}

void LEimprime(celula *le){
    celula *aux=le->prox;
    while(aux!=NULL){
        printf("%d ", aux->dado);
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

int THbusca (TH *h, int ch){
    int hashing = hash(h,ch);
    int busca = LEbusca(&h->tb[hashing], ch);

    /*if(busca==1){
        printf("\nA chave %d foi encontrada\n", ch);
    }
    else printf("\nA chave %d nao foi encontrada\n", ch);*/
    return busca;
}

void THinsere (TH *h, int ch){
    int hashing = hash(h, ch);
    
    int busca;
    busca = THbusca(h, ch);

    if(busca==0){
        LEinsere(&h->tb[hashing], ch);
    }
    else return;

    
}

void THimprime(TH *h){
    for(int i = 0; i < h->M; i++){
        printf("M = %d : ", i);
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
    int tam_TH = scanf("%d", &tam_TH);

    TH *tabela=malloc(sizeof(TH));

    tabela=THinicia(tabela, tam_TH);
    
    for(int i =0;i<14;i++){
        THinsere(tabela, i);
        tabela->N++;
    }

    
    /*THbusca(tabela, 9);
    THremove(tabela, 9);
    THbusca(tabela, 9);
    THremove(tabela, 9);*/
}