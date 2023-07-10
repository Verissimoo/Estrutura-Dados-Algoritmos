#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
 char inverte(char s[], int len){
    if (len == 0)return;
    printf("%c", s[len-1]);
    return inverte(s, len-1);

}

    char p[201];
    scanf("%s", p);
    int len = strlen(p);
    inverte(p, len);

   return 0;
}