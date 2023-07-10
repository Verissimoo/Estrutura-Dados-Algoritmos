#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define t 25
int main()
{
   int f91(int n){
    if (n >= 101) return n - 10;
    if (n <= 100) return f91(f91(n+11));
   }

int v[t];
int cont = 0;

for(int i=0; i < t; i++){
   int n;
   scanf("%d", &n);
     if(n != 0){
       v[i] = f91(n);
     } else break;
     cont++;
};

for(int i =0; i < cont; i++){
    printf("%d\n", v[i]);

}

   return 0;
}