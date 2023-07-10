#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define t 100

int main()
{
   char x[t] = "Veri";
   int len;

   len = strlen(x);

   for(int i = len; i >=0; i--){
    printf("%c", x[i]);
   }



   return 0;
}

