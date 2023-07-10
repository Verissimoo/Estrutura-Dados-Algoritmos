#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n, c;    // n = numero de leiruas; c = capacidade maxima
   int s, e;    // s = saiu; e = entrou
   int cont = 0;
   int infos[n];

   printf("Digite o numero de leituras e a capacidade maxima:\n");
   scanf("%d %d", &n, &c);

   for(int j=0; j<n;j++){
        printf("info: %d\n", j+1);
        scanf("%d %d",&s ,&e);

        cont -= s;
        cont += e;

        infos[j] = cont;
   };

for(int i=0; i<n; i++){

        if(infos[i] > c){
            printf("S");
        }else {
            printf("N");

              }
}

 return 0;
}