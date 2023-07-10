#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fib(int n){
        if (n == 1) return 1;
        if (n == 0) return 0;
        return fib(n-1) + fib(n-2);
    }

    long int a = fib(11);
    printf("%d", a);


   return 0;
}



