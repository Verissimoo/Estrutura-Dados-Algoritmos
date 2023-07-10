//Insertion Sort

//Metodo elementar;
//1-Complexidade: meida: O(N^2/4); pior caso: N^2; melhor caso: n-1
//2-Estabilidade: É instavel;
//3-Adaptividade: ele é um dos algoritmos que melhor aproveita a ordenação
//3-Memoria: In-place;

//Logica:
/*
-Ele segue a mesma logica de organizar um jogo de cartas na mão
-Por meio de duas variaveis ele percorre o vetor, j(j=i) e j-1
-Ele compara o valor de j com o de j-1, seu antecessor, e caso
o J seja maior ele da um swap com o j-1
-Apos essa analise e esse possivel swap as variaveis são 
desencrementadas enquanto tiver argumentos atras delas,
dessa forma conferindo e ordendando ate nao ter mais nenhum
valor anterior
-Enquanto essas 2 variaveis vão sendo desencrementadas o I
fica fixo na ultima posição do vetor onde parou a verificação,
enquanto o J e o J-1 vão verificando
-Após essas variaveis chegarem ao fim o J retorna para onde
esta o I, e esse I é incrementado 
*/

//Codigo:
void insertion_sort(int v[], int l, int r)
{
    for(int i=l+1; i<=r; i++)
    {
        for(int j=i; j>l && v[j]<v[j-1]; j--){
            int a = v[j];
            v[j] = v[j-1];
            v[j-1] = a;
        }
    }
}

