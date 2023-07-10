#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula
   {
    int dado;
    struct celula *prox;
   } celula;
   
typedef int Item;
typedef struct registro node;
struct registro {
    Item info;
    celula *prox; 
};
   
   
   celula *divide(celula *l, celula *l1, celula *l2){
        celula *p;
         for(p = l; p != NULL; p->prox ){
            if(l->dado % 2 !=0){
                l1->dado = l->dado;
            } else
             l2->dado = l->dado;
         } 
   }

celula *criar_lista()
{
    celula *le = malloc(sizeof(celula));  
    le->num_itens = 0;  
    le->prox = NULL;    
    le->ultimo = NULL;  
    return le;          
}

node *criar_no(Item x)
{
    node *no = malloc(sizeof(node));  //cria o espaço na memoria e o no
    no->prox = NULL;  
    no->info = x;  //insere ao conteudo o nó o item declarado como x
    return no;
}

void insere_inicio(celula *lista, node *novo)
{  
    //cabeca != node
    if(vazia(lista)) lista->ultimo = novo; //se a lista estiver vazia o ultimo item dela se torna o novo
      //sempre que adicionar um item na lista tem que incrementar o n de itens
    
    novo->prox = lista->prox;   // o novo nó sera o proximo após a cabeça 
    lista->prox = novo;         //apos a cabeça esta o novo item
}

void imprime(celula *lista)
{
    
    node *a = lista->prox;
    while(a!=NULL) {
        printf("%3d", a->info);
        a = a->prox;
    }
    printf("\n\n");
}

int main(){

    celula *l = criar_lista();
    celula *l1 = criar_lista();
    celula *l2 = criar_lista();
    
    
    for(int i=0; i<10; i++){
        node *novo = criar_no(i);
        insere_inicio(l, novo);
    };

    divide(l, l1, l2);
    imprime(l1);
    imprime(l2);

    return 0;
}