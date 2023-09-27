#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} tiro;

int distancia_ponto(int x, int y){
    int soma = (x*x)+(y*y);
    return soma;
}

int main(){

    int c,t;
    int pontuacao =0;


    scanf("%d %d", &c,&t);

    int raios[c];
    int aux;
    

    for(int i=0;i<c;i++){
        scanf("%d", &aux);
        raios[i]=aux*aux;
        //printf("%d\n", raios[i]);
    }

    //tiro tentativas[t] ;
    int x,y;
    int dist[t];

    for(int i=0;i<t;i++){
        scanf("%d %d", &x, &y);
        dist[i]=distancia_ponto(x,y);
        //printf("%d\n", dist[i]);
    }
   

    for(int i=0;i<t;i++){
        for(int i=0;i<t;i++){
            
        }
    }

    printf("%d\n", pontuacao);
}