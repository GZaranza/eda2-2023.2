#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int n;
    struct no *prox;
}no;

typedef struct grafo{

    no **adj;
    int n;

}grafo;


grafo *criar_grafo(int n){

    grafo *g = malloc(sizeof(grafo));
    g->n=n;
    g->adj=malloc(n*sizeof(no));
    for(int i=0;i<n;i++){
        g->adj[i]=NULL;
    }
    return g;
}

void destroi_grafo(grafo *g){
    for(int i=0;i<g->n;i++){
        free(g->adj[i]);
    }
    free(g->adj);
}

no *insere_na_lista(no *lista, int v){
    no *novo=malloc(sizeof(no));
    novo->n=v;
    novo->prox=lista;
    return novo;

}

void insere_aresta(grafo *g, int u, int v){
    g->adj[u]=insere_na_lista(g->adj[u],v);
    g->adj[v]=insere_na_lista(g->adj[v],u);
}

no *remove_da_lista(no *lista, int v){
    no *proximo;
    if(lista == NULL){
        return NULL;
    }

    else if(lista->n==v){
        proximo = lista->prox;
        free(lista);
        return proximo;
    }

    else{
        lista->prox=remove_da_lista(lista->prox,v);
        return lista;
    }
}

void remove_aresta(grafo *g, int u, int v){
    g->adj[u]=remove_da_lista(g->adj[u],v);
    g->adj[v]=remove_da_lista(g->adj[v],u);
}

void imprime_arestas(grafo *grafo){
    int aux;
    no *t;
    for(int i =0;i<grafo->n;i++){
        for(t=grafo->adj[i];t!=NULL;t=t->prox) printf("{%d,%d}\n",i,t->n);
    }
}

void bp_pai(grafo *g,int *pai, int a, int b){
    pai[b]=a;
    for(no *t=g->adj[b];t!=NULL;t=t->prox){
        if(pai[t->n]==-1) bp_pai(g,pai,b,t->n);
    }
}

int *encontra_caminhos(grafo *g, int v){
    int *pai=malloc(g->n*sizeof(int));
    for(int i=0;i<g->n;i++){
        pai[i]=-1;
    }
    bp_pai(g,pai,v,v);
    return pai;
}

void imprime_caminho(int v, int *pai){
    if(pai[v]!=v) imprime_caminho(pai[v],pai);
    printf("%d\n",v);
}

int main(){
    grafo *grafo = criar_grafo(16);
    insere_aresta(grafo,0,4);
    insere_aresta(grafo,0,1);
    insere_aresta(grafo,1,4);   
    insere_aresta(grafo,1,2); 
    insere_aresta(grafo,2,7);
    insere_aresta(grafo,2,6);
    insere_aresta(grafo,3,7);
    insere_aresta(grafo,5,10);
    insere_aresta(grafo,6,7);
    insere_aresta(grafo,6,11);
    insere_aresta(grafo,7,11);
    insere_aresta(grafo,4,8);
    insere_aresta(grafo,8,9);
    insere_aresta(grafo,8,12);
    insere_aresta(grafo,8,13);
    insere_aresta(grafo,9,5);
    insere_aresta(grafo,9,10);
    insere_aresta(grafo,9,12);
    insere_aresta(grafo,12,13);
    insere_aresta(grafo,10,13);
    insere_aresta(grafo,10,14);
    insere_aresta(grafo,13,14);
    insere_aresta(grafo,14,15);
    //imprime_arestas(grafo);

    int *pai=encontra_caminhos(grafo,0);
    imprime_caminho(15,pai);
}