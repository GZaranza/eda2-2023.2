#include <stdio.h>
#include <stdlib.h>

int c;
int t;
long long int circulos[100010];

int distancia(int x, int y){
    
    int dist = (x*x) + (y*y);
    return dist;

}

int busca(long long int x){
    int i=1;
    int j=c;

    if(x>circulos[c]) return 0;

    while (i<j){
        int meio = (i+j)/2;

        if(circulos[meio]>=x){
            j=meio;
        }
        else{
            i=meio+1;
        }

    }
    return c+1-j;

}


int main(){

    long long int pontuacao=0;

    scanf("%d %d", &c, &t);

    

    for(int i=1; i<=c;i++){
        scanf("%lld", &circulos[i]);
        circulos[i]=circulos[i]*circulos[i];
    }
    
    long long int x=0,y=0;

    for(int i=1; i<=t;i++){
        scanf("%lld %lld", &x,&y);
        pontuacao += busca(x*x+y*y);
    }
    printf("%lld\n", pontuacao);
    return 0;
}