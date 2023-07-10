#include <stdio.h>
#include <stdlib.h>

int main()
{
   int c1, c2, c3, c4, c5;
   printf("Digite o valor das cartas:\n");
   scanf("%d %d %d %d %d", &c1, &c2, &c3, &c4, &c5);

   if(c1<=13 && c2<=13 && c3<=13 && c4<=13 && c5<=13){
        if(c1>c2 && c2>c3 && c3>c4 && c4>c5){
            printf("D");
        } else if(c5>c4 && c4>c3 && c3>c2 && c2>c1){
            printf("C");
        } else printf("N");

   };
   
   return 0;
}