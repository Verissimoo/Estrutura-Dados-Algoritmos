#include <stdio.h>
#include <stdlib.h>

/*
SequÃªncia de conteiners
        InserÃ§Ã£o tempo constante
        Ideal para aplicaÃ§Ãµes com grandes conjuntos de dados e, poucas ou sem remoÃ§Ãµes, ou implementaÃ§Ãµes de FIFO (filas)
        Custo de remoÃ§Ã£o: O(n)
        Formas de implementaÃ§Ã£o
            Aponta para o prÃ³ximo elemento
            InserÃ§Ã£o/RemoÃ§Ã£o apÃ³s um elemento em tempo constante
            Sem cabeÃ§a, com cabeÃ§a, com cauda, com cabeÃ§a e cauda
            CabeÃ§a do mesmo tipo dos elementos do corpo
            CabeÃ§a com elementos diferentes do corpo
            
        CaracterÃ­sticas
            melhor performance na inserÃ§Ã£o, remoÃ§Ã£o/extraÃ§Ã£o e movimentaÃ§Ã£o dos elementos
            requer menos espaÃ§o e manipulaÃ§Ã£o de ponteiro do que a duplamente
            algoritmos com vÃ¡rias movimentaÃ§Ãµes como algoritmos de ordenaÃ§Ã£o
            desvantagem: 
                sem acesso direto a uma posiÃ§Ã£o
                aumento da carga nas remoÃ§Ãµes de elementos arbitrÃ¡rios
            uso de campos adicionais: 
                    aumenta o uso da memÃ³ria e um pouco da carga de inserÃ§Ãµes e remoÃ§Ãµes
                    porÃ©m aumenta a eficiÃªncia das operaÃ§Ãµes em fim de lista
                        diminui o custo da funÃ§Ã£o busca_fim

*/
/*
 * Tipos de dados dos elementos da lista
 *  Item: tipo do conteÃºdo dos nÃ³s
 *  node: tipo de cada nÃ³
 *  head: tipo da cabeÃ§a da lista
 */
typedef int Item;


//tipo node
typedef struct registro node;
struct registro {
    Item info;
    node *prox; 
};

//tipo head
typedef struct cabeca head;
struct cabeca {
    int num_itens;
    node *prox;
    node *ultimo;
};


//PROTÃ“TIPO DAS OPERAÃ‡Ã•ES BÃSICAS
head * criar_lista();
node *criar_no(Item);
int vazia(head *);
int tamanho_lista(head *);

void insere_inicio(head *, node *);
void insere_depois(head *, node *, node *);
void insere_fim(head *, node *); //com cabeÃ§a e apontador para o Ãºltimo

node *busca_inicio(head *);
node *busca_proximo(node *);
node *busca_fim(head *);//com cabeÃ§a e apontador para o Ãºltimo

void remove_no(head *, node *);
void remove_inicio(head *);

//OPERAÃ‡Ã•ES ADICIONAIS
//buscar nÃ³ antes de outro nÃ³
//buscar nÃ³ antes de um dado/item
//inserir um nÃ³ ou um item antes de um nÃ³
//inserir um nÃ³ ou um item antes ou depois de uma posiÃ§Ã£o
//remover um item ou nÃ³ depois de um nÃ³ ou de uma posiÃ§Ã£o


head * criar_lista()
{
    head *le = malloc(sizeof(head));
    le->num_itens = 0;
    le->prox = NULL;
    le->ultimo = NULL;
    return le;
}

node *criar_no(Item x)
{
    node *no = malloc(sizeof(node));
    no->prox = NULL;
    no->info = x;
    return no;
}

int vazia(head *p)
{
    return (p->prox==NULL); 
}

int tamanho_lista(head *lista)
{
    //cabeca != node
    return lista->num_itens;
    
}

void insere_inicio(head *lista, node *novo)
{  
    //cabeca != node
    if(vazia(lista)) lista->ultimo = novo;
    lista->num_itens++;  
    
    novo->prox = lista->prox;    
    lista->prox = novo;
}

void insere_fim(head *lista, node *novo)
{
    if(vazia(lista)) return insere_inicio(lista, novo);
        
    novo->prox = NULL;
        
    //cabeca != node
    lista->ultimo->prox = novo;
    lista->ultimo = novo;
    lista->num_itens++;
    
    //cabeca == node
    //node *aux = busca_fim(lista);
    //insere_depois(lista, aux, novo);
}

void insere_depois(head *lista, node *ref, node *novo)
{
    if(lista->ultimo == ref) return insere_fim(lista, novo);
      
    novo->prox = ref->prox;
    ref->prox = novo;
      
    //cabeca != node
    lista->num_itens++;
}

node *busca_inicio(head *lista)
{
  return lista->prox;
}

node *busca_proximo(node *no)
{
  return no->prox;
}

node *busca_fim(head *lista)
{

    //cabeca != node
    return lista->ultimo;
    
    //cabeca == node
    //cauda apontando para o Ãºltimo elemento
    
}

void remove_no(head *lista, node *lixo)
{
    node *aux = busca_inicio(lista);
    while(aux!=NULL && aux->prox!=lixo) 
        aux = busca_proximo(aux);

    if(aux){
        aux->prox = lixo->prox;
        if(lixo == lista->ultimo) lista->ultimo = aux->prox;
        lista->num_itens--;
    }
    
}

void remove_inicio(head *lista)
{
    if(!vazia(lista)){
        node *lixo = lista->prox;
        lista->prox = lista->prox->prox;

        if(lixo == lista->ultimo) lista->ultimo = NULL;
        lista->num_itens--;
    }
}

///////////////////////////////////////////////////
///////////////////////////////////////////////////




///////////////////////////////////////////////////
///////////////////////////////////////////////////
void imprime(head *lista){
    printf("%d itens\n", lista->num_itens);
    
    node *a = lista->prox;
    while(a!=NULL) {
        printf("%3d", a->info);
        a = a->prox;
    }
    
    if(lista->ultimo) printf("\nÃºltimo item: %d", lista->ultimo->info);
    printf("\n\n");
}

/*void criar_lista(head **le)
{
    *le = malloc(sizeof(head));
    (*le)->num_itens = 0;
    (*le)->prox = NULL;
    (*le)->ultimo = NULL;
}*/


///////////////////////////////////////////////////
///////////////////////////////////////////////////
int main(){
  head *le = criar_lista();
  //head *le;
  //criar_lista(&le);
  
  return 0;
}







#include <stdio.h>
#include <stdlib.h>

/*
Listas Duplamente Encadeadas

        Formas de implementaÃ§Ã£o
            Aponta para o elemento anterior e prÃ³ximo
            Consome espaÃ§o adicional e manutenÃ§Ã£o dos apontadores
            PorÃ©m facilita operaÃ§Ãµes inserÃ§Ãµes/remoÃ§Ãµes anteriores
            InserÃ§Ã£o/RemoÃ§Ã£o antes e apÃ³s um elemento em tempo constante
            Sem cabeÃ§a, com cabeÃ§a, com cauda, com cabeÃ§a e cauda
            CabeÃ§a do mesmo tipo dos elementos do corpo
            CabeÃ§a com elementos diferentes do corpo
        
        Utilizado em algoritmos com manipulaÃ§Ãµes frequentes, como os algoritmos de ordenaÃ§Ã£o
    
*/

/*
 * Tipos de dados dos elementos da lista
 *  Item: tipo do conteÃºdo dos nÃ³s
 *  node: tipo de cada nÃ³
 *  head: tipo da cabeÃ§a da lista
 */
typedef int Item;

typedef struct registro node;
struct registro {
    Item info;
    node *ant; //<<<<<<<<<<<<<<<<<<<<<<<<<<<
    node *prox;
};

//tipo head
typedef struct cabeca head;
struct cabeca {
    int num_itens;
    node *prox;
    node *ultimo;
};


//PROTÃ“TIPO DAS OPERAÃ‡Ã•ES BÃSICAS
head *criar_lista();
node *criar_no(Item);

int vazia(head*);
int tamanho_lista(head *);

node *busca_inicio(head *);
node *busca_anterior(node *);
node *busca_proximo(node *);
node *busca_fim(head *);

void insere_inicio(head *, node *);
void insere_fim(head *, node *);
void insere_depois(head *, node *, node *);
void insere_antes(head *, node *, node *);

void remove_no(head *, node *);

//OPERAÃ‡Ã•ES ADICIONAIS
//UTILIZAR FUNÃ‡Ã•ES BASES

head * criar_lista()
{
    head *le = malloc(sizeof(head));
    le->num_itens = 0;
    le->prox = NULL;
    le->ultimo = NULL;
    return le;
}

node *criar_no(Item x)
{
    node *no = malloc(sizeof(node));
    no->ant = NULL;            //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    no->prox = NULL;
    no->info = x;
    return no;
}

int vazia(head *p)
{
  return (p->prox==NULL); 
}

int tamanho_lista(head *lista)
{
    //cabeca != node
    return lista->num_itens;
    
    //cabeca == node
    //int tam = 0;
    //node *aux = busca_inicio(lista);
    //while(aux != NULL && aux->prox != NULL){
      //  aux= aux->prox;
      // tam++;
    //}
    //return tam;
    
}

node *busca_inicio(head *lista)
{
  return lista->prox;
}

node *busca_anterior(node *no)   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
{
  return no->ant;
}

node *busca_proximo(node *no)
{
  return no->prox;
}

node *busca_fim(head *lista)
{

    //cabeca != node
    return lista->ultimo;
    
    //cabeca == node
    //cauda == node
    
}

void insere_inicio(head *lista, node *novo)
{  
    if(vazia(lista)) lista->ultimo = novo;
    else lista->prox->ant = novo; //<<<<<<<<<<<<<<<<<<<<<<<<
    lista->num_itens++; 

    novo->ant = NULL;         //<<<<<<<<<<<<<<<<<<<<<<<<
    novo->prox = lista->prox;    
    lista->prox = novo;
}

void insere_fim(head *lista, node *novo)
{
    if(vazia(lista)) return insere_inicio(lista, novo);
    
    novo->ant = lista->ultimo; //<<<<<<<<<<<<<<<<<
    novo->prox = NULL;
    
    //cabeca != node
    lista->ultimo->prox = novo;
    lista->ultimo = novo;
    lista->num_itens++;
}

void insere_depois(head *lista, node *ref, node *novo)
{
    if(lista->ultimo == ref) return insere_fim(lista, novo);
    
    novo->ant = ref;        //<<<<<<<<<<<<<<<<<<<<<<<<<<
    novo->prox = ref->prox;
    ref->prox->ant = novo;  //<<<<<<<<<<<<<<<<<<<<<<<<<<
    ref->prox = novo;
    
    lista->num_itens++;
}

void insere_antes(head *lista, node *ref, node *novo)
{
    if(lista->prox == ref) return insere_inicio(lista, novo);
     
    return insere_depois(lista, ref->ant, novo);
}

void remove_no(head *lista, node *lixo)
{
    
    if(lixo->ant) lixo->ant->prox = lixo->prox; //se nao for o primeiro elemento
    else lista->prox = lixo->prox;
    
    if(lixo->prox) lixo->prox->ant = lixo->ant; //se nao for o ultimo elemento
    else lista->ultimo = lixo->ant; //cabeca != node
    
    //cabeca != node
    lista->num_itens--;
    
}



///////////////////////////////////////////////////
///////////////////////////////////////////////////

void imprime(head *lista)
{
    printf("%d itens\n", lista->num_itens);
    
    node *a = lista->prox;
    while(a!=NULL) {
        printf("%3d", a->info);
        a = a->prox;
    }
    
    if(lista->ultimo) printf("\nÃºltimo item: %d", lista->ultimo->info);
    printf("\n\n");
}

void imprime_reverso(head *lista)
{
    printf("Imprime reverso\n");
    printf("%d itens\n", lista->num_itens);
    
    node *a = busca_fim(lista);
    while(a!=NULL) {
        printf("%3d", a->info);
        a = a->ant;
    }
    
    if(lista->ultimo) printf("\nÃºltimo item: %d", lista->ultimo->info);
    printf("\n\n");
}


void troca_nos(head *lista, node *no1, node *no2)
{
    //printf("troca: %d %d\n", no1->info, no2->info);
    node *no2_prox = busca_proximo(no2);
  
    remove_no(lista, no2);  
    insere_antes(lista, no1, no2);
    remove_no(lista, no1);  

    if(no2_prox) insere_antes(lista, no2_prox, no1);
    else insere_fim(lista, no1);
    
}

void inverte_lista_v1(head *lista){
    //insere depois do primeiro ultimo 
    node *p = busca_inicio(lista);
    node *q = busca_fim(lista);
    int tam = tamanho_lista(lista);
    for(int i=0; i<tam-1; i++){
        remove_no(lista, p);
        insere_depois(lista, q, p);
        p = busca_inicio(lista);
    }
}

void inverte_lista_v2(head *lista){
    //trocar o primeiro com o ultimo
    //trocar o segundo com o penultimo
    //ate o meio

    node *p = busca_inicio(lista);
    node *q = busca_fim(lista);
    int tam = tamanho_lista(lista)/2;

    while(tam>0){
        tam--;
        troca_nos(lista, p, q);
        node *a = p;
        p = busca_proximo(q);
        q = busca_anterior(a);
        
    }
}

void inverte_lista_v3(head **lista){
    //criar nova lista invertida
    head *nova_lista = criar_lista();

    int tam = tamanho_lista(*lista);

    node *a = busca_fim(*lista);
    
    while(a!=NULL){
        remove_no(*lista, a);
        insere_fim(nova_lista, a);
        a = busca_fim(*lista);
    }
    free(*lista);
    *lista = nova_lista;
}




///////////////////////////////////////////////////
///////////////////////////////////////////////////
int main(){
    head *le = criar_lista();

    //cria e insere item no fim da lista
    for(int i=0; i<10; i++){
        node *novo = criar_no(i);
        insere_fim(le, novo);
    }
    imprime(le);
    imprime_reverso(le);

    //cria e insere item na posiÃ§Ã£o 4 da lista
    node *novo = criar_no(-9);
    node *aux = busca_inicio(le);
    for(int i=1; i<4; i++) 
        aux = busca_proximo(aux);
    if(aux) 
        insere_depois(le, aux, novo);
    imprime(le);

    //retira um nÃ³ da lista
    remove_no(le, novo);
    imprime(le);
    free(novo); //libera memÃ³ria


    //busca um nÃ³ com um conteÃºdo especÃ­fico e
    //cria e insere item antes do nÃ³ procurado
    aux = busca_inicio(le);
    node *ant = NULL;
    while(aux!=NULL && aux->info!=5) { //procura nÃ³ com o conteÃºdo 5
        ant = aux;
        aux = busca_proximo(aux);
    }

    novo = criar_no(-9); //nÃ³ que serÃ¡ inserido
    if(aux!=NULL && aux->info==5){ //caso tenha achado o nÃ³ com conteÃºdo 5
        insere_depois(le, ant, novo);
    }
    printf("%d\n", novo->prox->ant->info);
    imprime(le);



    //node *a = busca_inicio(le);
    //remove_no(le, a);
    //free(a);
    //imprime(le);

    inverte_lista_v2(le); 
    imprime(le);

    return 0;
}






#include <stdio.h>
#include <stdlib.h>


/*
    Listas Duplamente Encadeadas Circulares
        O primeiro e Ãºltimo elementos estÃ£o conectados
        Requer atualizaÃ§Ã£o adicional nos terminais da lista
*/

typedef int Item;
//tipo node
typedef struct registro node;
struct registro {
    Item info;
    node *prox; 
    node *ant; 
};

//tipo head
typedef struct cabeca head;
struct cabeca {
    int num_itens;
    node *prox;
    node *ultimo;
};


//PROTÃ“TIPO DAS OPERAÃ‡Ã•ES BÃSICAS
head * criar_lista();
node *criar_no(Item);

int vazia(head *);

void insere_inicio(head *, node *);
void insere_fim(head *, node *);
void insere_depois(head *, node *, node *);
void insere_antes(head *, node *, node *);

node *busca_inicio(head *);
node *busca_fim(head *);

node *busca_anterior(head *, node *);
node *busca_proximo(head *, node *);

node *busca_loop_anterior(node *);
node *busca_loop_proximo(node *);

void remove_no(head *, node *);

//OPERAÃ‡Ã•ES ADICIONAIS
//UTILIZAR FUNÃ‡Ã•ES BASES



head * criar_lista()
{
    head *le = malloc(sizeof(head));
    le->num_itens = 0;
    le->prox = NULL;
    le->ultimo = NULL;
    return le;
}

node *criar_no(Item x)
{
    node *no = malloc(sizeof(node));
    no->ant = NULL;
    no->prox = NULL;
    no->info = x;
    return no;
}

int vazia(head *p)
{ 
    return (p->prox==NULL); 
}

void insere_inicio(head *lista, node *novo)
{  
    if(vazia(lista)) {
        lista->ultimo = novo;
        lista->prox = novo;      //<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        novo->ant = novo;
        novo->prox = novo; 

    } else {
        novo->ant = lista->ultimo;
        novo->prox = lista->prox; 

        novo->ant->prox = novo;
        novo->prox->ant = novo;

    }
    lista->prox = novo;

    lista->num_itens++;  
}

void insere_fim(head *lista, node *novo)
{
    if(vazia(lista)) return insere_inicio(lista, novo);
    
    novo->ant = lista->ultimo; 
    novo->prox = lista->prox; //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    
    lista->prox->ant = novo;  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    
    //cabeca != node
    lista->ultimo->prox = novo;
    lista->ultimo = novo;
    lista->num_itens++;
  
    //cabeca == node
    //node *aux = busca_ultimo(lista);
    //insere_depois(lista, aux, novo);
}

void insere_depois(head *lista, node *ref, node *novo)
{
    if(lista->ultimo == ref) return insere_fim(lista, novo);
    
    novo->ant = ref;
    novo->prox = ref->prox;
    ref->prox->ant = novo;
    ref->prox = novo;
      
    //cabeca != node
    lista->num_itens++;
}

void insere_antes(head *lista, node *ref, node *novo)
{
    if(lista->prox == ref) return insere_inicio(lista, novo);
     
    return insere_depois(lista, ref->ant, novo);
}

node *busca_inicio(head *lista)
{
  return lista->prox;
}

node *busca_fim(head *lista)
{

    //cabeca != node
    return lista->ultimo;
    
}

//se for o primeiro retorna null ou a cabeÃ§a
node *busca_anterior(head *lista, node *no)
{
  if(no->ant==lista->ultimo) return NULL;
  return no->ant;
}

//se for o ultimo retorna null ou a cabeÃ§a 
node *busca_proximo(head *lista, node *no)
{
  if(no->prox==lista->prox) return NULL;
  return no->prox;
}
       
//se for o primeiro retorna o Ãºltimo 
node *busca_loop_anterior(node *no)
{
  return no->ant;
}

//se for o ultimo retorna o primeiro
node *busca_loop_proximo(node *no)
{
  return no->prox;
}

void remove_no(head *lista, node *lixo)
{
    if(busca_loop_proximo(lixo) == lixo) {
        lista->prox = NULL;
        lista->ultimo = NULL;
        
    } else {
        lixo->ant->prox = lixo->prox; 
        lixo->prox->ant = lixo->ant;

        if(lixo==lista->prox) lista->prox = lixo->prox;
        if(lixo==lista->ultimo) lista->ultimo = lixo->ant;
    }
    lista->num_itens--;
}



///////////////////////////////////////////////////
///////////////////////////////////////////////////
void imprime(head *lista){
    printf("%d itens\n", lista->num_itens);
    
    node *a = lista->prox;
    while(a!=NULL) {
        printf("%3d", a->info);
        a = busca_proximo(lista, a);
        //a = busca_loop_proximo(a); ?????
    }
    
    if(lista->ultimo) printf("\nÃºltimo item: %d", lista->ultimo->info);
    printf("\n\n");
}

void imprime_reverso(head *lista){
    printf("Imprime reverso\n");
    printf("%d itens\n", lista->num_itens);
    
    node *a = busca_fim(lista);
    while(a!=NULL) {
        printf("%3d", a->info);
        a = busca_anterior(lista, a);
    }
    
    if(lista->ultimo) printf("\nÃºltimo item: %d", lista->ultimo->info);
    printf("\n\n");
}




///////////////////////////////////////////////////
///////////////////////////////////////////////////

int main(){
    head *le = criar_lista();

    for(int i=5; i>0; i--){
        node *novo = criar_no(i);
        insere_inicio(le, novo);
    }

    for(int i=6; i<10; i++){
        node *novo = criar_no(i);
        insere_fim(le, novo);
    }
    imprime(le);
    imprime_reverso(le);


    node *a = busca_inicio(le);
    for(int i=1; i<5; i++){
        node *b = busca_proximo(le, a);
        remove_no(le, a);
        free(a);
        a = b;
    }
    imprime(le);

    a = busca_fim(le);
    for(int i=0; i<5; i++){
        node *b = busca_anterior(le, a);
        remove_no(le, a);
        free(a);
        a = b;
    }
    imprime(le);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

/*
    FILAS
        TIPO ABSTRATO DE DADOS
            Conjunto de dados encapsulados como um objeto, com um comportamento bem definido
            Esconder internamente as estruturas de dados e a lÃ³gica nos procedimentos
            Ocultamento de informaÃ§Ã£o (caixa preta)
            ManipulaÃ§Ã£o da fila somente atravÃ©s da funÃ§Ãµes
        
        FIFO (first-in first-out) 
            Primeiro elemento inserido Ã© o primeiro a ser processado/retirado
            OperaÃ§Ãµes/funÃ§Ãµes para acesso aos elementos (fechado/caixa preta)
            InserÃ§Ãµes no fim, remoÃ§Ãµes no inÃ­cio
            OperaÃ§Ãµes bÃ¡sicas:
                vazia
                tamanho
                primeiro - busca_inicio
                ultimo - busca_fim
                enfileira - insere_fim 
                desenfileira - remove_inicio
        
    ImplementaÃ§Ã£o com lista estÃ¡tica 
        https://www.ime.usp.br/~pf/algoritmos/aulas/fila.html



    fila[p..u-1]

       0     p                                   u            N-1
 	|     | 111 | 222 | 333 | 444 | 555 | 666 |      |      |     |

    p - inicio da fila
    u - fim da fila

*/

#define N 10
int fila[N];
int p, u;

void criar_fila ()
{
   p = u = 0;
}

int vazia()
{
   return p >= u;
}


int desenfileira()
{
   return fila[p++];
}

void enfileira (int y)
{
   fila[u++] = y;
}

void imprime()
{
    printf("p=%d : u=%d\n", p, u);
    for(int i=p; i<u; i++) printf("%3d", fila[i]);
    printf("\n");
}

void imprime_memoria(int fim)
{
    printf("\nmemoria a partir do endereÃ§o apontado por fila\n");
    for(int i=0; i<fim; i++) printf("%3d", fila[i]);
    printf("\n");
    printf("=================================================\n\n");
}

int main()
{
    criar_fila();
    for(int i=0; i<10; i++) enfileira(i);

    imprime();
    //imprime_memoria(12);

    for(int i=p; i<3; i++) desenfileira();

    imprime();
    //imprime_memoria(12);

    
    //enfileira(-1);

    //imprime();
    //imprime_memoria(12);
    
    
    
    return 0;
}

