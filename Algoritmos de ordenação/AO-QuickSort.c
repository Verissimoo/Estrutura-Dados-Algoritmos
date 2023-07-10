//Quick sort

//Metodo Eficiente (um dos mais utilizados);
//1-Complexidade: - Melhor caso: O(n log n ) = chaves dististas ou aleatorias
//                - Pior caso: n^2/2 = itens repetidos ou quase ordenados     
//2-Estabilidade: Depende, no geral não é, mas se o pivor for o elemento mais a direta e modificar o codigo ele pode ser;
//3-Adaptividade: ele não aproveita a ordenação;
//3-Memoria: In-place;

//Logica
/*
- A logica desse algoritmo é semelhante a do Merge, porem teremos
um Pivor agora;
- Esse pivo é inicialmente o primeiro ou o ultimo elemento do vetor
- Ele percorre o vetor comparando cada elemento com o pivor
e separando em 2 subgrupos, os de elementos menores que o pivor
e o de elementos maiores que ele(Na versão do Cormem isso é feito
in-place, as versões mais antigas separava em 2 vetores aux)
- Dessa forma o pivot vai estar na sua posição correta no vetor
- Apos isso o algortimo por ser recursivo vai fazendo essa
procura pelo pivor e particionando em cada subgrupo que vai sendo
gerado
- O programa faz isso ate que os subvetores seja uma comparação
de 2 elementos, onde vai seguir a mesma logica, 1 vai ser o pivo
e o outro argumento vai ser comparado com ele e ordenado se
necessario
- A função QuickSort age de forma recursiva e possui outra função
dentro, seus argumentos e a estrututa sao da seguinte forma:
   1- QuickSort(v, l, r)
      1.1 - pos = Partition(v, l, r) =  reparte o vetor com o pivor no meio
      1.2 - QuickSort(v, l, pos-1) = Reparte o subvetor de elemenos menor que o pivo
      1.3 - QuickSort(v, pos+1,r ) = Reparte o subvetor de elemenos maior que o pivo
- Como o pivor sempre estara na posição certa, quando se tem um vetor
de apenas 1 elemento para ser partido ele retornara ele mesmo na posição certa
    - Partition(v, 2, 3-1);
    - Particion(v, 4+1, 5);

*/

//Codigo:

//Cria 2 subvetores aux com os valores menores e maiores que o pivot
int partition(int *v,  int l, int r)
{  
	int i = l;
	int j = r+1;
	int pivot = v[l];

    while (i<j)
    {
        while (v[++i] < pivot && i < r);
        while (v[--j] > pivot && j > l);
        if (i < j)
        {
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }

    int aux = v[l];
    v[l] = v[j];
    v[j] = aux;

    return j;

}

//Puxa os elementos maiores que o pivt para o fim do vetor
int partitionCORMEM(int *v, int l, int r) 
{
    int pivot = v[r];
    int j = l;
    for(int i=l; i<r; i++)
    {
        if(less(v[i],pivot)){
            exch(v[i], v[j]);
            j++;
        }
    }

    exch(v[r], v[j]);

    return j;
}

void quick_sortC(int *v,  int l, int r)
{
    if(r<=l) return;
    
    int p = partitionCORMEM(v, l, r);
	quick_sortC(v, l, p-1);
	quick_sortC(v, p+1, r);
}


//Procura no vetor onde o pivot deve ficar e da um swap para la
int partitionRSEDGEWICK(int *v, int l, int r)
{
    int i=l-1, j=r, pivot = v[r];
    
    while(1)
    {
        while(v[++i] < pivot);
        while(pivot < v[--j]) if(j==l) break;
        if(i>=j) break;
        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    

    return i;
}

void quick_sortR(int *v,  int l, int r)
{
    if(r<=l) return;

    int p = partitionRSEDGEWICK(v, l, r);
	quick_sortR(v, l, p-1);
	quick_sortR(v, p+1, r);
}


//Otimizado
void quick_sortRM3(int *v,  int l, int r)
{
    if(r<=l) return;

    compexch(v[l], v[(l+r)/2]);
    compexch(v[l], v[r]);
    compexch(v[r], v[(l+r)/2]);

    int p = partitionRSEDGEWICK(v, l, r);
	quick_sortRM3(v, l, p-1);
	quick_sortRM3(v, p+1, r);
}

