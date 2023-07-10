#include <stdio.h>
#include <stdlib.h>

#define t 100

int main()
{
   char x[t] = "Veri";
   int cont = 0;

   for(int i =0; i < t; i++){
        if(x[i] != '\0'){
            cont++;
        } else break;
   }
   
 printf("%d", cont);

   return 0;
}