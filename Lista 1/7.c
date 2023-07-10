#include <stdio.h>
#include <stdlib.h>

int main()
{
   float g, a, rG, rA;
   printf("Digite os valores:\n");
   scanf("%f %f %f %f", &g, &a, &rG, &rA);
   int r1, r2;

   // A e G sao preços
   //rG e rA sao quantos km faz com o litro com base no preço
   //multiplicar valor pelo rendimento
   //0.01 <= A <= 10.00
   //0.01 <= G <= 10.00
   //0.01 <= Ra <= 20.00
   //0.01 <= Rg <= 20.00

   if(a > 0.01 && a < 10 && g > 0.01 && g < 10 && rG > 0.01 && rG < 20 && rA > 0.01 && rA < 20 ){
    r1 = g * rG;
    r2 = a * rA;

    if(r1 > r2){
        printf("G");
    } else if (r1 == r2){
        printf("G");
    } else printf("A");
   };

   return 0;
}