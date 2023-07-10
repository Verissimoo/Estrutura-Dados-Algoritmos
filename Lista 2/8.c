#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define t 100
int main()
{

 char muda(char s[], int i){
    if (s[i] == '\0')return;
    if (s[i] != 'x') return muda(s, i+1);
    if (s[i] == 'x'){
        s[i] = 'y';
    }
}

    char p[201];
    scanf("%s", p);
    muda(p, 0);
    printf("%s", p);



   return 0;
}
