#include <stdio.h>
#include <stdlib.h>


typedef struct grafo{

    int **adj;
    int n;

}grafo;

grafo *cria_grafo(int n){

    grafo *g=malloc(sizeof(grafo));
    g->n=n;
    g->adj=malloc(n*sizeof(int *));
    for(int i=0; i<n;i++){
        g->adj[i]=malloc(n*sizeof(int));
    }
    return g;
}

void insere_aresta(grafo *g, int u,int v){ //retorna o grau (num de vizinhos) de um vertice v
    g->adj[u][v]=g->adj[v][u]=1;
}

void remove_aresta(grafo *g, int u, int v){
    g->adj[u][v]=g->adj[v][u]=0;
}

int grau(grafo *g, int v){
    int grau=0;
    for(int i=0;i<g->n;i++){
        if(g->adj[v][i]==1) grau++;
    }
    return grau;
}


int busca_recursiva(grafo *g, int *visitado,int u, int v){
    if(u!=v){
        visitado[u]=1;
        for(int w=0;w<g->n;w++){
            if(g->adj[u][w] && !visitado[w]){
                if(busca_recursiva(g,visitado,w,v)){
                    return 1;
                }
            }
        }
        return 0;
    }
    return 1;
}

int existe_caminho(grafo *g, int u, int v){
    int *visitado = calloc(g->n,sizeof(int));
    int encontrou = busca_recursiva(g,visitado,u,v);
    free(visitado);
    return encontrou;

}

int main(){

    grafo *grafo = cria_grafo(8);
    insere_aresta(grafo,0,2);
    insere_aresta(grafo,0,5);
    insere_aresta(grafo,2,6);
    insere_aresta(grafo,6,4);
    insere_aresta(grafo,4,7);
    insere_aresta(grafo,4,3);
    insere_aresta(grafo,7,1);
    insere_aresta(grafo,3,5);
    
    //MOSTRANDO O GRAU DE TODOS OS ELEMENTOS
    for(int i=0;i<8;i++){
       // printf("\ngrau do %d é: %d\n", i, grau(grafo,i));
    }

    printf("\nencontrou = %d\n", existe_caminho(grafo,0,1));



}