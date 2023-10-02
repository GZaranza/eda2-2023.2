#include <stdio.h>
#include <string.h>

int main(){

    char min[10];

    char max[10];

    scanf("%s", min);
    scanf("%s",max);

    printf("\n%d\n", min[strlen(min)-1]-32);
    printf("\n%d\n", max[0]);
    /*if(b[0]+32 == a[strlen(a)-1]){
        printf("igual\n");
    }*/
    return 0;
}