#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *tb; // tabela hash
    int M; // tamanho da tabela hash
    int N; // total de chaves presentes na tabela
} TH;

int aumentaTamanho (int M);

int hash(TH *h, int ch){
    return ch%h.m;
}

void THinsere (TH *h, int ch){

    int hashing = hash(h, ch);

    if(h->N > (h->M/2)){
        int novo_tam = aumentaTamanho(h->M);
        h->M=novo_tam;
        h->tb=realloc(h->tb,novo_tam*sizeof(int));
        

    }

    while(h->tb[hashing]!=-1 && h->tb[hashing]!=ch){
        hashing = hash(h, hashing+1);
    }

    if(h->tb[hashing] = ch) return;

    h->tb[hashing] = chave;
    h->N++;
}

int THremove (TH *h, int ch){
    int hashing = hash(h, ch);

    while(h->tb[hashing]!=-1){
        if(h->tb[hashing]==ch){
            h->tb[hashing]=-2;
            h->N--;
            return 0;
        }
        hashing = hash(h, hashing+1);
    }
    return -1;
}

int THbusca (TH *h, int ch){
    int hashing = hash(h, ch);
    
    while(h->tb[hashing]!=-1){
        if(h->tb[hashing]==ch){
            return 1;
        }
        hashing = hash(h, hashing+1);
    }
    return 0;
}

