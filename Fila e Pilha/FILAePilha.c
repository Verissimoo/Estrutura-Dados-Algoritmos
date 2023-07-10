//FILA
//É uma lista encadeada com a seguinte carecteristica:
//- O primeiro a entrar é o primeiro a sair;
//Esse tipo de estrutura serve para sistemas onde é do interesse
//do usuario que o primeiro elemento inserido seja o primeiro
//a ser retornado, obdecendo assim a ordem de chegada

//Criando uma fila:
#define N 7;
int fila[N];
int p, u;   //primeiro e ultimo
void criar_fila(){
    p = u = 0;
}
//p/ fila estatica
//Remoção no inicio da fila
int desenfileira(){
    return fila[p++]    //ao incrementar o primeiro elemento da lista é deixado de fora
}
//Inserção no final da fila
int enfileira(int y){
    fila[u++] = y

}
//Fila vazia
void vazia(){
    p >= u;
}

//O problema dessas remoções e inserções é que tem o risco
//da pilha transbordar, se o tamanho maximo é 7, o ultimo
//elemento (u) tem que ser o 6, mas então para não ter problemas
//a pilha adota um comportamento circular, se lotou volta ao inicio
// u+1 == p, o ultimo item se torna o primeiro se não tiver nenhum
//outro elemento ocupando o espaço, e se tiver dar erro
//Exemplos do que fazer para a lista não lotar: 
//Fila estatica circular
void enfileira(int y){
    fila[u++] = y
    if(u == N) u = 0; // se o ultimo elemento for no tamanho maximo da pilha ele vai pra posição 0
}

int desenfileira(){
    int x = fila[p++];
    if(p == N) p = 0;
    return x;
}
void redimensionamento(){
    N *= 2;
    int *novo = malloc(N * sizeof(int));

    int j = 0;
    for(int i = p; i < u; i++, j++){
        novo[j] = fila[i]; 
    }

    p = 0;
    u = j;

    free(fila);
    fila = novo;
    
}
//novo é um espaço de memoria iniciado em 0 que esta sendo
//preenchido com os valores da fila partindo de seu inicio (p);
//no fim a posição do ultimo valor é definida pelo tanto de 
//vezes que o J foi incrementado
//Apos transferir todos os dados da fila para novo, ela é zerada
//e seu tamnho e organização são com base no vetor 'novo'

//Fila encadeiada
typedef int Item;
typedef struct registro node;
struct registro {
    Item info; 
    node *prox;
};
typedef struct cabeca head;
struct cabeca {
    int num_itens;
    node *prox;
    node *ultimo;
};

int vazia(){
    lista->prox == NULL;
}

node *primeiro(head *lista){
    return lista->prox;
}

node *ultimo(head *lista){
    return lista->ultimo;
}

void enfileira(head *lista, Item x){
    node *novo = criar_no(x);

    if(novo){
        novo->prox = NULL;

        if(!vazia(lista)){
            lista->ultimo->prox = novo;
        } else lista->prox = novo;

        lista->ultimo = novo;
        lista->num_itens++;
    }
}

void desenfileira(head *lista){
     node *lixo = primeiro(lista);
    lista->prox = lista->prox->prox; // pula o primeiro elemento

    //cabeca != node
    if(lixo == lista->ultimo) lista->ultimo = NULL;
    lista->num_itens--;

    Item x = lixo->info;  // salva o valor do primeiro elemento no x
    free(lixo); //libera o espaço do primeiro elemento
    return x;   // retorna o valor retirado da lista 

}

//PILHA
//Os ultimos são os primeiros, o contrario da fila
//uma recursão adota esse comportamento por exemplo

//Criando uma pilha:
int *pilha;
int t;
void criar(int n)
{
    pilha = malloc(n*sizeof *pilha);
    t = 0;
}

//Remoção no topo da pilha
int *pilha;
int t;

void desempilha(){
    return pilha[--t];
}

//Inserção no topo da pilha
void empilha(Item y){
    pilha[t++] = y;
}

//Espia
Item espia(){
    return pilha[t-1];
}

//Vazia
int vazia(){
    return t == 0;
}

//Para criar e manipular varias pilhas

typedef struct pilha_t Pilha;
struct pilha_t
{
    Item *item;
    int topo;
};

Pilha *criar(int maxN){
    Pilha *p = malloc(sizeof *p);
    p->item = malloc(maxN*sizeof Item);
    p->topo = 0;
}

int vazia(Pilha *p){
    return p->topo == 0;
}

void empilhar(Pilha *p, Item item){
    p->item[p->topo++] = item;
}

void desempilhar(Pilha *p){
    return p->item[--p->topo];
}

Item desempilhar(Pilha *p){
    return p->item[--p->topo];
}

Item espiar(Pilha *p){
    return p->item[p->topo-1];
}

//Implementação com lista encadeada

head *criar_pilha(){
    head *le = malloc(sizeof(head));
    le->num_itens = 0;
    le->prox = NULL;
    le->ultimo = NULL;
    return le;
}

node *criar_no(Item x){
    node *no = malloc(sizeof(node));
    no->prox = NULL;
    no->info = x;
    return x;
}

int vazia(head *p){
    return(p->prox == NULL);
}

Item espia(head *p){
    return(p->prox->info);
}

void empilha(head *lista, Item x){
    node *novo = criar_no(x);

    if(novo){
        if(vazia(lista)) lista->ultimo = novo;

        novo->prox = lista->prox
        lista->prox = novo;

        lista->num_itens++;
    }
}

Item desempilha(head *lista){
    node *topo = lista->prox;
    lista->prox = topo->prox;

    if(topo == lista->ultimo) lista->ultimo == NULL;
    lista->num_itens--;

    Item x = topo->info;
    free(topo);
    return x;
}




