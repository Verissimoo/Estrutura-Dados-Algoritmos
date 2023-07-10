#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define t 100
int main()
{
    char pares(char s[], int i){
        if (s[i] == '\0') return 0;
        if (s[i] == s[i+2]) return 1 + pares(s, i+1);
        return pares(s, i+1);

    }
    char s[201];
    scanf("%s", s);
    int npares = pares(s, 0);
    printf("%d", npares);




   return 0;
}