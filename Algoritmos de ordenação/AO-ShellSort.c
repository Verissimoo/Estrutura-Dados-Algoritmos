//Shell Sort

//Metodo elementar;
//1-Complexidade: 
   //- Com pior sequencia de intervalos de h: O(n^2)
   //- Melhor caso com boa sequencias de int: O(n log n)
//2-Estabilidade: Ele não pode garantir a ordem relativa dos itens
//3-Adaptividade: Ele não aproveita a ordenação existe, pois de qualquer forma efetua as divisões de H
//3-Memoria: In-place;

//Logica:
/*
-O fato do Insertion Sort aproveitar muito bem a ordem relativa
dos itens fez com que o Shell Sort fosse uma melhora desse algoritmo
-Levando esse pricipio em consideração temos uma nova variavel
nesse algoritmo
-o H, que é determinado pelo valor da divisão por 3
do tamanho R do vetor, apos pegar esse valor coloque ele na
seguinte formula:
1- h = 1; ele é menor que o valor da divisão ?
2- Se ele for: 3 * 1(h) + 1; atualize o valor de H com esse valor
3- h = 4; Ele é menor que o valor da divisão ?
4- Se ele for: 3 * 4(h) + 1; atualize o valor de H com esse valor
5- Quando o H for maior que o tamanho da partição de vetor
defina ele como a primeira area a ser percorrida
- Apos isso sua variavel j=i começa na posição de H
- E a variavel j-h começa na posição 0
- Ele compara quem é o maior entre esses dois valores e dependendo
faz um swap colocando o menor na posição do j-h
- Apos isso as variaveis são incrementedas e segue fazendo
essas comparações
-Quando o a variavel j=i chega ao fim o valor atual de H
é divido por 3, e esse novo valor passa a sera a nova area
a ser comparada
-Dessa forma então o vetor j-h volta para a posição 0 e a
j=i pro novo valor de h, seguindo fazendo comparações
- A unica coisa que muda esse processo é o seguinte:
- Quando as variaveis estão se encaminhando mais para o meio
do vetor, apos ser feito um swap nessas comparações, o programa
verifica se ele possui antecessor
- Esse antecessor se trata do valor de H sendo reduzido ao j-h
- Se o valor de H fosse 3 e o vetor fizesse um swap onde o
j-h estivesse na posição 5, o algoritmo verificaria na posição
2, (5-3);
- Se tiver mais posições para tras, o programa vai repetindo isso
ate chegar onde não da mais pra reduzir o H no vetor
- Apos isso, as variavei j=i e j-h são incrementadas e voltam
para o mesmo processo em loop ate o valor de H sendo divido
por 3 chegue a 1;
- Quando ele chega em 1 se inicia o Insertion Sort, onde ele
vai comparar item com item des do inicio do vetor;
- Mas agora a vantagem é que ele estara ja parcialmente organizado,
nisso trazendo um aumento bastante significativo no desempenho
do Insertion Sort, e tornando esse metodo bastente valido
*/

//Codigo:

void shell_sort(int v[], int l, int r)
{
    int h = 1;
    while(h < (r-l+1)/3) h = 3*h+1;

    while(h>=1){
        for(int i=l+h; i<=r; i++)
        {
            for(int j=i; j>=l+h && v[j]<v[j-h]; j-=h)
            {
                int a = v[j];
                v[j] = v[j-h];
                v[j-h] = a;
            }
        }
        h = h/3;
    }
}