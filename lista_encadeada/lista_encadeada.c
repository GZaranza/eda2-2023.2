#include <stdio.h>
#include <stdlib.h>
#include "ordenacoes.h"

typedef struct celula{
    int *prox;
    int chave;
} celula;

celula *new_celula (int chave){
    celula *no = malloc(sizeof(celula));
    no->chave = chave;
    no->prox = NULL;
    return no;
}

