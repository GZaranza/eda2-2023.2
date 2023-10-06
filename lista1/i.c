#include <stdio.h>
#include <stdlib.h>




int main(void){

    int n;
    scanf("%d", &n);

    int menor_trilha=0;
    int menor_dist=1000000000;

    for(int i=0;i<n;i++){

        int m;
        int ida=0;
        int volta=0;
        int resultado=0;

        scanf("%d", &m);
        int v[m];

        for(int j =0; j< m; j++){
            scanf(" %d", &v[j]);
        }

        for(int j=1;j<m;j++){
            if(v[j]>v[j-1]){
                ida+=(v[j]-v[j-1]);
            }
        }

        for(int j=m-1;j!=0;j--){
            if(v[j-1]>v[j]){
                volta+=(v[j-1]-v[j]);
            }
        }
        if(ida<=volta) resultado=ida;
        else resultado=volta;
        printf("\nresultado da trilha %d: %d\n", i+1, resultado);

        if(resultado<menor_dist){
            menor_trilha=i+1;
            menor_dist=resultado;
        }
    }
    printf("%d\n", menor_trilha);
    return 0;
}