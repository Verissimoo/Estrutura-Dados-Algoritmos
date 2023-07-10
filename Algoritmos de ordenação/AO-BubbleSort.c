//Bubble Sort

//Metodo elementar;
//1-Complexidade: O(N^2); comparações = N^2/2, trocas = N;
//2-Estabilidade: Não estavel;
//3-Adaptividade: ele nao aproveita a info de estar ordenado;
//3-Memoria: In-place;

//Logica:
/*
1-Ele percorre o vetor começando pelo final, vindo de tras pra
frente, fazendo comparações com seu elemento anterior, como
j e j-1;
2-Quando é identificado um valor de j-1 maior que o de j eles
fazem uma troca de posição, e seguem adiante ate o fim do vetor
identificando par por par qual o maior e seguindo ou trocando eles;
3-Quando chegam no inicio do vetor ele voltam para o fim,
reiniciando o mesmo processo, repetidas vezes ate o vetor
por fim ficar ordenado;
*/

//Codigo:

int bubble_sort(int v[], int l, int r){
    //flutuar o ultimo elemento em direcao ao topo
    //quem flutua? ultimo elemento
    //como flutua? comparando com o adjacente
    for(int i=l; i<=r; i++){
        for(int j=r; j>i; j--)
        {
            if(v[j] < v[j-1]){
                int a = v[j];
                v[j] = v[j-1];
                v[j-1] = a;
            }
        }
    }
    
}









