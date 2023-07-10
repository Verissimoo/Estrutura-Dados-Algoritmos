#include <stdio.h>
#include <stdlib.h>

int main()
{
   //1 entrada: comprimento e distancia entre pedagios
   //2 entrada: custo por km e valor do pedagio

   int estrada;  //km
   int dist;
   int custoK;
   int custoP;

   printf("Digite o comprimento da estrada e a distancia entre pedagios:\n");
   scanf("%d %d", &estrada, &dist);

   printf("Digite o custo por km e o valor do pedagio:\n");
   scanf("%d %d", &custoK, &custoP);

   int totalK, distP, totalP, total;

   distP = estrada / dist;
   totalP = distP * custoP;

   totalK = custoK * estrada;

   total = totalP + totalK;

   printf("%d\n", total);

   return 0;
}

