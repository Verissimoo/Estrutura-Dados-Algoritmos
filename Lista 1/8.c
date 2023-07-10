#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
   int a, b;
   int n, t;
   int contA = 0;
   int contB = 0;

   printf("Quantas testes teve?:\n");
   scanf("%d", &t); // 5

   for(int j=0; j<t;j++){
     printf("Quantas rodadas teve no teste %d:\n", j+1);
     scanf("%d", &n);

         for(int i=0;i<n;i++){
           printf("Resultado da rodada %d:\n", i+1);
           scanf("%d %d", &a, &b);
           contA += a;
           contB += b;
           }
         if(a > b){
            printf("Teste %d\n Aldo wins\n",j+1);
         } else printf("Teste %d\n Beto wins\n", j+1);
   }

   return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
   int a, b;
   int n, t;
   int contA = 0;
   int contB = 0;



   printf("Quantas testes teve?:\n");
   scanf("%d", &t); // 5

   int somaA[t];
   int somaB[t];


   for(int j =0; j<t; j++){
     printf("Quantas rodadas teve no teste %d:\n", j+1);
     scanf("%d", &n);

     contA = 0;
     contB = 0;

         for(int i=0;i<n;i++){
           printf("Resultado da rodada %d:\n", i+1);
           scanf("%d %d", &a, &b);
           contA += a;
           contB += b;
           }
        somaA[j] = contA;
        somaB[j] = contB;
   }

   for(int j=0; j<t; j++){
    if(somaA[j] > somaB[j]){
            printf("Teste %d\n Aldo wins\n",j+1);
         } else{
             printf("Teste %d\n Beto wins\n", j+1);
         }
   }

   return 0;
}
