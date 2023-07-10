#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define t 100
int main()
{
    char palavra[t] = "xuxatamaluca";
    int len;
    char temp;

    len = strlen(palavra);

    for(int i=0; i < len; i++){
        if(palavra[i] == 'x'){
            for(int j = i; j< len-1; j++){
                temp = palavra[j];
                palavra[j] = palavra[j+1];
                palavra[j+1] = temp;
            }
        }
    }

for(int i = 0; i < len; i++){
    printf("%c", palavra[i]);
   }



   return 0;
}