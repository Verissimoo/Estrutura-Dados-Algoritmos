//LISTA ENCADEADA

//Estrtura:

//- Node = é o nó de junção de elementos numa lista
typedef struct registro node;
struct registro {
    Item info;
    node *prox; 
};
//Sua principal função é servir de guia para inserção e remoção
//de elementos na lista

//-Head = é a cabeçã da lista, onde ela se inicia, serve de
//guia para percorremos ela tendo como referencia o inicio
typedef struct cabeca head;
struct cabeca {
    int num_itens;
    node *prox;
    node *ultimo;
};

//Principais operações com listas

head * criar_lista()
{
    head *le = malloc(sizeof(head));  //cria um ponteiro para a cabeça
    le->num_itens = 0;  //informa o numero de itens
    le->prox = NULL;    //informa que o ponteiro posterior é vazio
    le->ultimo = NULL;  //informa que o ultimo ponteiro da lista é vazio
    return le;          //cria a lista
}

node *criar_no(Item x)
{
    node *no = malloc(sizeof(node));  //cria o espaço na memoria e o no
    no->prox = NULL;  
    no->info = x;  //insere ao conteudo o nó o item declarado como x
    return no;
}

int vazia(head *p)
{
    return (p->prox==NULL);   //declara que após a cabeça o valor é nulo, ou seja, nn tem itens
}

int tamanho_lista(head *lista)
{
    return lista->num_itens;
}

void insere_inicio(head *lista, node *novo)
{  
    //cabeca != node
    if(vazia(lista))lista->ultimo = novo; //se a lista estiver vazia o ultimo item dela se torna o novo
    lista->num_itens++;  //sempre que adicionar um item na lista tem que incrementar o n de itens
    
    novo->prox = lista->prox;   // o novo nó sera o proximo após a cabeça 
    lista->prox = novo;         //apos a cabeça esta o novo item
}

void insere_fim(head *lista, node *novo)
{
    if(vazia(lista)) return insere_inicio(lista, novo);  //se a lista for vazia inere no inicio
        
    novo->prox = NULL;
        
    lista->ultimo->prox = novo; //na lista, o ultimo nó é o novo
    lista->ultimo = novo;       //ultimo item é o novo
    
    lista->num_itens++;         //incrimenta mais um item 
    
}

void insere_depois(head *lista, node *ref, node *novo)
{
    if(lista->ultimo == ref) return insere_fim(lista, novo); //se nessa lista o nó de referencia for o ultimo ent insere no fim
      
    novo->prox = ref->prox; //insere o nó do novo apos o nó do ref
    ref->prox = novo;       //o nó do ref vai apontar para o novo nó 
      
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
    return lista->ultimo;   
}

void remove_no(head *lista, node *lixo)
{
    node *aux = busca_inicio(lista);   //cria um no auxiliar que aponta primeiro para o inicio da lista
    while(aux!=NULL && aux->prox!=lixo) 
        aux = busca_proximo(aux); //percorre a lista ate achar o nó lixo

    if(aux){
        aux->prox = lixo->prox;  //meu nó auxiliar vai ser agora o lixo
        if(lixo == lista->ultimo) lista->ultimo = aux->prox; //coloco o nó que quero excluir como ultimo
        lista->num_itens--;   //tira um item da lista
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

//LISTA DUPLAMENTE ENCAMINHADA
//A diferença dela pra simples é que agora podemos adicionar
//ou remover itens que estao tambem ANTERIORMENTE
//Base:
typedef int Item;

typedef struct registro node;
struct registro {
    Item info;
    node *ant; //<<<<<<<<<<<<<<<<<<<<<<<<<<<
    node *prox;
};
typedef struct cabeca head;
struct cabeca {
    int num_itens;
    node *prox;
    node *ultimo;
};

//Principais operações 

head * criar_lista(); //igual a simples

node *criar_no(Item x)
{
    node *no = malloc(sizeof(node));
    no->ant = NULL;            //Agora tambem tem que declarar um nó anterior
    no->prox = NULL;
    no->info = x;
    return no;
}

int vazia(head *p); // mesma coisa

int tamanho_lista(head *lista); //mesma coisa

node *busca_inicio(head *lista); //mesma coisa

node *busca_anterior(node *no);  //Operação nova so possivel nesse tipo de lista
{
  return no->ant;
}

node *busca_proximo(node *no);  //Mesma coisa

node *busca_fim(head *lista);   //Mesma coisa

void insere_inicio(head *lista, node *novo)
{  
    if(vazia(lista)) lista->ultimo = novo;
    else lista->prox->ant = novo; //variação nova
    lista->num_itens++; 

    novo->ant = NULL;         //se o item foi inserido no inicio seu nó anterior aponta pra nada
    novo->prox = lista->prox;    
    lista->prox = novo;
}

void insere_fim(head *lista, node *novo)
{
    if(vazia(lista)) return insere_inicio(lista, novo);
    
    novo->ant = lista->ultimo; //o nó de tras desse novo item adicionado no fim tem que apontar para o ultimo item
    novo->prox = NULL;  //como ele é o ultimo não pode ter nada após
    
    //cabeca != node
    lista->ultimo->prox = novo;
    lista->ultimo = novo;
    lista->num_itens++;
}

void insere_depois(head *lista, node *ref, node *novo)
{
    if(lista->ultimo =ref->ant= ref) return insere_fim(lista, novo);
    
    novo->ant = ref;        //meu nó de tras aponta para o meu ref
    novo->prox = ref->prox; //meu nó novo aponta para oque esta afrente de ref
    ref->prox->ant = novo;  //meu nó 
    ref->prox = novo;       //apos meu nó em ref esta meu novo item
    
    lista->num_itens++;
}

void insere_antes(head *lista, node *ref, node *novo)
{
    if(lista->prox == ref) return insere_inicio(lista, novo);
     
    return insere_depois(lista, , novo); 
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

//LISTAS CIRCULARES
//A diferença dessa para as demais é que ela nao possui um fim
//ou um começo, o ultimo nó aponta para o primeiro elemento
//Base:
typedef int Item;

typedef struct registro node;
struct registro {
    Item info;
    node *prox; 
    node *ant; 
};

typedef struct cabeca head;
struct cabeca {
    int num_itens;
    node *prox;
    node *ultimo;
};

//Operações

head * criar_lista(); //mesma coisa
node *criar_no(Item); //mesma coisa
int vazia(head *);    //mesma coisa

void insere_inicio(head *lista, node *novo)
{  
    if(vazia(lista)) {
        lista->ultimo = novo;
        lista->prox = novo;      
        novo->ant = novo;
        novo->prox = novo; //um unico item em ciclo

    } else {
        novo->ant = lista->ultimo;  //coloca o novo no no final
        novo->prox = lista->prox;   //faz esse novo no apontar para o inicio

        novo->ant->prox = novo;     //?
        novo->prox->ant = novo;     //?

    }
    lista->prox = novo;

    lista->num_itens++;  
}

void insere_fim(head *lista, node *novo)
{
    if(vazia(lista)) return insere_inicio(lista, novo);
    
    novo->ant = lista->ultimo; //nó traseiro do novo como ultimo 
    novo->prox = lista->prox; //nó da frente apontando para o começo da lista
    
    lista->prox->ant = novo;  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    
    //cabeca != node
    lista->ultimo->prox = novo;  //novo no final do ultimo nó
    lista->ultimo = novo;        //ultimo item é o novo
    lista->num_itens++;          
  
}

void insere_depois(head *lista, node *ref, node *novo) //mesma coisa
{
    if(lista->ultimo == ref) return insere_fim(lista, novo);
    
    novo->ant = ref;
    novo->prox = ref->prox;
    ref->prox->ant = novo;
    ref->prox = novo;
      
    lista->num_itens++;
}

void insere_antes(head *lista, node *ref, node *novo)  //memsa coisa
{
    if(lista->prox == ref) return insere_inicio(lista, novo);
     
    return insere_depois(lista, ref->ant, novo);
}

node *busca_inicio(head *lista)  //mesma coisa

node *busca_fim(head *lista)     //mesma coisa


node *busca_anterior(head *lista, node *no)
{
  if(no->ant==lista->ultimo) return NULL; //se for o primeiro retorna null ou a cabeça
  return no->ant;
}

node *busca_proximo(head *lista, node *no)
{
  if(no->prox==lista->prox) return NULL; //se for o ultimo retorna null ou a cabeça
  return no->prox;
}
       

node *busca_loop_anterior(node *no)
{
  return no->ant;  //se for o primeiro retorna o ultimo
}

node *busca_loop_proximo(node *no)
{
  return no->prox; //se for o ultimo retorna o primeiro
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












