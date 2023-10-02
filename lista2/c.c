#include <stdio.h>
#include <stdlib.h>




int main(){

    int n;
    scanf("%d", &n);
    while (n!=0){
        int *v = calloc(1000001, sizeof(int));
        
        int cor;
        int maior_count=0;
        int maior_cor=0;

        for(int i=0;i<n;i++){
            scanf("%d",&cor);
            v[cor]++;
            if(v[cor]>maior_count){
                maior_cor=cor;
                maior_count=v[cor];
            }
        }
        printf("%d\n", maior_cor);
        free(v);
        scanf("%d", &n);
    }
    

    return 0;
}