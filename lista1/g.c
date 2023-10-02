#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula
{
    char str[100];
    struct celula *prox;
} celula;


void inserir(celula *le, char *str){
    celula *nova = malloc(sizeof(celula));

    strcpy(nova->str,str);
    nova->prox= le->prox;
    le->prox = nova;
}

char *desfazer(celula *le){
    celula *lixo;

    if(le->prox==NULL){
        return "NULL";
    }

    lixo = le->prox;
    le->prox=lixo->prox;

    return lixo->str;
}

void imprimir (celula *le){
    celula *aux = le->prox;

    while(aux != NULL){
        printf("%s -> ", aux->str);
        aux=aux->prox;
    }

    printf("NULL\n");

}

int main(){
    
    celula *le = malloc(sizeof(celula));
    
    char str[100];
    char comando[10];

    

    while(scanf("%s",comando)==1){
        
        if(strcmp(comando,"inserir") == 0){
            scanf(" %[^\n]", str);
            inserir(le, str);
        }

        else if (strcmp(comando,"desfazer") == 0) {
            printf("%s\n", desfazer(le));
        }

    }
    /*char teste[]= "gabriel";
    inserir(le, teste);
    inserir(le, "aqui");

    imprimir(le);

    desfazer(le);
    imprimir(le);*/

    return 0;
}