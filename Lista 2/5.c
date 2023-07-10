#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int soma(int n){
        if (n < 10) return n;
        return (n % 10) + soma(n/10);
    }

    int a = soma(123);
    printf("%d", a);


   return 0;
}