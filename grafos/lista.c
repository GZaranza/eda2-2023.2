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

//PILHA

no *criar_pilha(){
    no *pilha = malloc(sizeof(no));
    pilha->prox=NULL;
    pilha->n=-1;
    return pilha;
}

void empilhar(no *pilha, int s){
    no *novo = malloc(sizeof(no));
    novo->n=s;
    novo->prox=pilha->prox;
    pilha->prox=novo;
}

int desempilhar(no *pilha){
    no *lixo=pilha->prox;
    pilha->prox=lixo->prox;
    int s = lixo->n;
    free(lixo);
    return s;
}

int pilha_vazia(no *pilha){
    return (pilha->prox==NULL);
}

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
    no *aux;
    novo->n=v;
    if(lista==NULL){
        novo->prox=NULL;
        return novo;
    }

    else if(novo->n < lista->n){
        novo->prox=lista;
        return novo;
    }
    else{
        aux = lista;
        while(aux->prox && novo->n > aux->prox->n){
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox=novo;
        return lista;
    }


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

void imprime_arestas(grafo *g){
    no *t;
    for(int u=0;u<g->n;u++){
        for(t=g->adj[u];t!=NULL;t=t->prox){
            printf("{%d,%d}\n",u,t->n);
        }
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

void grau(grafo *g, int v){

    int grau=0;
    no *t;
    for(t=g->adj[v]; t!=NULL;t=t->prox){
        grau++;
    }
    printf("\nGrau de %d = %d\n",v,grau);

}

void imprime_caminho(int v, int *pai){
    if(pai[v]!=v) imprime_caminho(pai[v],pai);
    printf("%d\n",v);
}

int busca_rec_existe_caminho(grafo *g, int *visitado, int a, int b){
    if(a!=b){
        visitado[a]=1;
        no *t;
        for(t=g->adj[a];t!=NULL;t=t->prox){
            if(!visitado[t->n]){
                if(busca_rec_existe_caminho(g,visitado,t->n,b)){
                    return 1;
                }
            }
        }
        return 0;
    }
    return 1;
}

void existe_caminho(grafo *g, int u, int v){
    int *visitado = calloc(g->n,sizeof(int));
    int encontrou = busca_rec_existe_caminho(g,visitado,u,v);
    free(visitado);
    if(encontrou==1) printf("\nExiste caminho entre %d e %d\n", u,v);
    else printf("\nNao existe caminho entre %d e %d\n",u,v);
}  
//retorna o vetor pai a partir de um vertice
int *busca_prof_pilha(grafo *g, int s){

    int *pai=malloc(g->n*sizeof(int));
    int *visitado=malloc(g->n*sizeof(int));

    for(int i =0;i<g->n;i++){
        pai[i]=-1;
        visitado[i]=0;
    }

    no *pilha = criar_pilha();
    empilhar(pilha,s);
    pai[s]=s;
    while(!pilha_vazia(pilha)){
        int v = desempilhar(pilha);
        if(visitado[v]) continue;
        visitado[v]=1;
        for(no *t=g->adj[v];t!=NULL;t=t->prox){
            if(!visitado[t->n]){
                pai[t->n]=v;
                empilhar(pilha,t->n);
            }
        }
    }
    return pai;
}
int main(){
    grafo *grafo = criar_grafo(16);
    insere_aresta(grafo,0,4);
    insere_aresta(grafo,0,1);
    insere_aresta(grafo,1,4);   
    insere_aresta(grafo,1,2); 
    insere_aresta(grafo,2,6);
    insere_aresta(grafo,2,3);
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

    //int *pai=busca_prof_pilha(grafo,0);for(int i=0;i<16;i++){printf("%d: %d\n", i,pai[i]);}
    
    int *pai = encontra_caminhos(grafo,0);  imprime_caminho(15,pai);

    //existe_caminho(grafo,11,15);




    //for(no *t=grafo->adj[0];t!=NULL;t=t->prox){printf("%d ",t->n);}printf("\n");
}