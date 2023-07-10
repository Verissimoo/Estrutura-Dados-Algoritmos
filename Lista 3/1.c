#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula
   {
    int dado;
    struct celula *prox;
   } celula;
   
   
   
   celula *busca(celula *le, int x){
        celula *p;
         for(p = le; p != NULL; p->prox ){
            if(p->dado == x) return p;
         } 
       
   }

   celula *buscarec(celula *le, int x){
       celula *p;
       p = le;
       if (p->dado == x) return p;
       return buscarec(le->prox, x);
   }

int main(){
    
}