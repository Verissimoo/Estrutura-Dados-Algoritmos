// Diferença na execução de uma variavel declarada 
/* 
int = %d
float = %f
char = %c
string = %s
exemplo: printf("%d\n", var1)
*/

// Vetor/array unidimensional
/*
- Usado quando se tem a intenção de guardar elementos
- ex: ler valores inteiro e printar na ordem inversa

-Inicialização na declaração
   int lista[3] = {10, 20, 30};

-Opções de saidas
   &lista[0]; = endereço do primeiro elemento do array
   lista[0]; = conteudo do primeiro elemento do array (10)

-Inicialização pela entrada padrão
   int vetor[5];

   int i=0;
   while(i<5){
    printf("Digite o valor do argumento\n ");
    scanf("%d", &vetor[i]);
    i++;
   };
   for(i=0;i<5; i++){
     printf("Valores armazenados:\n");
     printf("%d\n", vetor[i]);
   }
   return 0;

-Atribuindo valores pelo indice
   int total[10];
   total[2] = 20;
-Acessando o valor individualmente
   int x = total[2];

-Igualando vetores
   int vetorA[3], vetorB[3];
   int i;


   for(i=0;i<3;i++){
    printf("Digite os numeros\n");
    scanf("%d\n", &vetorA[i]);
   };

   for(i=0;i<3;i++){
    vetorB[i] = vetorA[i];
    printf("Vetor copiado\n");
   };

   for(i=0; i<3;i++){
   printf("%d\n", vetorB[i]);
   };

MATRIX:
int a[ 3 ][ 5 ] = { {10, 6, 7, 12 , 11 } , {23 ,32 ,14 ,52 ,22 } ,
{ 33 ,17 ,18 ,54 ,28 } } ;

*/
//PONTEIROS E MEMORIA
/*
void troca (int *i, int *j) {
   int temp;
   temp = *i;
   *i = *j;
   *j = temp;
}

void trocaSimples (int *p){
    *p = 5;
};

int main()
{
   int a = 3;
   int b = 9;
   troca(&a, &b);
   printf("%d , %d\n", a, b);

   int p1 = 10;
   trocaSimples(&p1);
   printf("%d\n", p1);

   int *p, *q;
   p = &a;
   q = &b;
   troca(p, q);
   printf("%d, %d\n", a, b);

   return 0;

Recurção:

int fat(int n){
        if(n==0) return 1;
        return n * fat(n-1);
    }

    int x = fat(5);

    printf("%d", x);

   return 0;
}
}

//É uma função que chama ela mesma
//Ela possui uma condição de parada e uma forma de reduzir o N
de tal forma que esse N venha chegar em algum momento na condição
estabelecida
//Os resultados obtidos em cada rodada enquanto N era desencrementado
sao guardados em forma de PILHA, ou seja, o primeiro resultado
fica na base e o ultimo antes da condição no topo
//Quando é atingido a condição de parada essa pilha é disfeita
retornando primeiramente o ultimo resultado, pois ele esta no
topo da pilha
//Quando a pilha esta sendo disfeita, o simbolo que esta antes
da recursão na função simboliza justamente oque sera feito com
cada valor armazenado nos returns, nesse caso do fatorial, os
valores sao multiplicados entre si 

//O conceito de usar recursividade gira em torno de pegar um
problema, dividir ele em partes menores, resolver cada parte
e por fim juntar tudo



//ANALISE DE ALGORITMOS 
Manual de como calcular a eficiencia do algoritmo
//Deve se definir a complexidade do algortimo primeiro
Função de custo f(n):
   - O custo vai ser definido a partir do tamanho de N;
   - Exemplo de casos assim é uma função que procura vetores,
   o tamanho do custo pra fazer essa procura vai ser medido
   a partir do tamanho desse vetor
Função de custo f(n) = 1;
   - Não dependem do tamanho de N, ou seja, o tamanho do N nao
   altera seu custo
   - Exemplos: Atribuições, operações aritmetica, acesso a memoria
Função de custo f(n) = n;
   - Possui uma complexidade linear, ou seja, quanto maior o valor
   da operação maior seu custo
   exemplo: for, laços de repetição são otimos para descrever esse
   tipo, pois, quanto maior o numero de loops feitos maior o custo
Função de custo f(n) = n^2
   - Complexidade quadratica
   - Um for dentro de outro for representa perfeitamente esse tipo
   - um exemplo é um codigo de ordenação
Função de custo f(n) = n^3
   - Complexidade cubica
   - 2 for dentro de 1 for
   - Usado muito para percorrer matrizes
Função de custo f(n) = 2^n
   - Complexidade exponencial
   - Problemas onde precisa ser verificado uma serie de possibilidades
   - Recursão é um grande exemplo, cada vez que um novo retorno
   é feito e a recursão volta é como se estivessemos num processo
   de: 2^1(primeiro return) 2^2(segundo), 2^3(), e assim por diante
Função de custo f(n) = log n
   - Complexidade logaritmica
   - É o inverso da exponencial, vai indo mais lento a medida
   que N cresce
Função dde custo f(n) = n log n
    - Pega um problema, divide ele em subproblemas, resolve todos
    e depois junta, um metodo de divisão e conquista
    - O chamamento de função é exatamente isso

//COMO CALCULAR OS CUSTO

- A mais utilizada é a notação O
- Para f (n) = n^2 + 2n + 1, sua complexidade em O(n^2)

   











*/


