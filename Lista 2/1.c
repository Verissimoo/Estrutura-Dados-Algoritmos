#include <stdlib.h>
#include <string.h>


int main()
{

   int swap(int *i, int *p) {
       int t;
        t = *i;
       *i = *p;
       *p = t;
   };

   int a, b;
   scanf("%d%d", &a, &b);
   printf("%d, %d\n", a, b);
   swap(&a, &b);
   printf("%d, %d", a, b);


   return 0;
}