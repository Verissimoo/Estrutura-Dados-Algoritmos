//Selection Short

//Metodo elementar;
//1-Complexidade: O(N^2); comparações = N^2/2, trocas = N;
//2-Estabilidade: Não estavel;
//3-Adaptividade: ele não aproveita a ordenação;
//3-Memoria: In-place;

//Logica: 
/*
1-Ele primeiramente percorre todo o vetor com a intenção de
identificar o menor valor, ele faz isso por meio de uma variavel
auxiliar que percorre o vetor gravando nela o indice do menor
valor encontrado
2-Apos percorrer o vetor ele ve qual indice ficou registrado
como o menor valor, e faz um swap(uma troca) com o elemento da
primeira posição do vetor
-Depois ele incrimenta a variavel que auxilia ele a percorrer 
o vetor para poder começar a nova verificação a partir do segundo
elemento, pois o menor menumero ja esta na primeira posição
3-E assim sucetivamente ate percorrer todos os elementos do vetor
*/

//Codigo:

void selection_sort(int v[], int l, int r){
    int menor;

    for(int i=l; i<=r; i++){
        //procurar o menor para trocar com a primeira posicao
        //indice do menor elemento inicialmente
        menor = i;

        //procurar elemento menor
        for(int j=i+1; j<=r; j++) {
            if(v[j] < v[menor]) {
                menor = j;
            } 
        }

        //se achar um menor?
        if(v[i] != v[menor]){
            int a = v[i];
            v[i] = v[menor];
            v[menor] = a;
        }
    }
    
}


