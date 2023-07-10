#include <stdio.h>
#include <stdlib.h>

int main()
{

   int nb;
   int batida;

   printf("Qual o numero de batidas ?: \n");
   scanf("%d", &nb);

   for(int i =0; i< 5; i++){
        if(i%2==0){
    printf("THUMS THUMS THUMS\n");
        } else {
            printf("THUMS THUMS THUMS THUMS THUMS THUMS\n");
        }
   };
 return 0;
}