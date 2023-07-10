#include <stdio.h>
#include <stdlib.h>

#define max 100


int main()
{
    int n;
    int menor;

    scanf("%d", &n);

     int v[n];

    for(int i=0;i <n; i++){
        scanf("%d", &v[i]);
    }

    menor = v[0];
    for(int i=0; i<n;i++){
        if(v[i] < menor){
            menor = v[i];
        }
    }

    printf("O menor valor do vetor e: %d", menor);

 return 0;
}