#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

   int a, b, c;
   printf("Digite oque foi colocado pelos jogadores:\n");
   scanf("%d %d %d", &a, &b, &c);

   if(a == b && b == c){
    printf("Empate");
   } else if(a == b && b != c){
       printf("Jogador C ganhou");
   } else if(a == c && c != b){
       printf("Jogador B ganhou");
   } else if(b == c && c != a){
       printf("Jogador A ganhou");
   };

   return 0;
}