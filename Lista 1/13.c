#include <stdio.h>
#include <stdlib.h>

#define max 100


int main()
{
    int n;
    int x;
    int resultado = 0;

    scanf("%d", &n);

    int v[n];

    for(int i=0;i <n; i++){
        scanf("%d", &v[i]);
    }
    printf("Digite o X\n");
    scanf("%d", &x);

    for(int i=0; i < n; i++){
            if(x == v[i]){
                resultado = 1;
                break;
            }
    }
    if(resultado == 1){
        printf("Pertence");
    } else {
        printf("Nao pertence");
    }





 return 0;
}