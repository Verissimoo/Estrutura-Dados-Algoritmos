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
    int pares[n];
    int impares[n];
    int np = 0;
    int ni = 0;

    for(int i=0;i < n; i++){
        scanf("%d", &v[i]);

        if(v[i] % 2 == 0){
            pares[np] = i;
            np++;
        } else{
            impares[ni] = i;
            ni++;
        }
    }

// O(n)

for(int i=0; i < np; i++){
    printf("%d, ", pares[i]);
}

printf("\n");

for(int i=0; i < ni; i++){
    printf("%d, ", impares[i]);
}

 return 0;
}