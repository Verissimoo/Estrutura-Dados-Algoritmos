//Merge sort

//Metodo Eficiente;
//1-Complexidade: O(n log n) em todos os casos;
//2-Estabilidade: É estavel!;
//3-Adaptividade: ele não aproveita a ordenação;
//3-Memoria: Não é in-place pos ele cria um vetor auxiliar;

//Logica
/*
-A ideia do algoritmo é ele repartir pela metade o vetor
varias vezes com o proposito desses subvetores, quando forem
compostos por somente 1 elementos faça assim comparações
e salve esse subvetor num vetor auxiliar com a posição correta
dos elementos comparados 1 com 1 a principio, posteriomente as
comparações começam a ser feitas de subvetores de 2 elementos
com outros subvetores do mesmo tamanho, ate por fim esses subv
que vao aumentando se tornem as 2 metades do vetor, e a
comparação final seja o desfeixo da ordenação

-Esse algortimo usa a ideia da recursividade, por conta disso
seu custo é (n log n) sendo dessa forma bem eficaz;
-O algoritmo é composto por 2 funções:
   - Merge-sort()
       1- Na primeira chamada ele recebe como argumento: 
             (int *v, int l, int r), dessa forma partindo ao
             meio o vetor e declarando como "m" o meio
       2- a partir disso as partições vao ser feitas usando o m:
            (v, l, m) = do inicio ate o meio
            (v, m+1, r) =  do meio ate o final
       3- ele faz isso sucessetivamente (recursividade) ate q os
       subvetors sejam de tamanho 1;
   - Merge()
       1- Apos o vetor ser separados em subvetores de tamanho 1
       entra em cena o Mege
       2- Sua função é comparar esses subvetores e salvar em um
       vetor auxiliar de tamanho 2 qual a ordem correta dos dois
       elementos que foram comparados. Essa comparação é feita
       com o auxilio de duas variaveis, I e J;
       3- Ele recebe como argumento de sua função a posição dos
       elementos do vetor que ele quer organizar:
        (v, 0, 0, 1) =  compara o elemento 0 com o 1
        (v, 2, 2, 3) =  compara o elemento 2 com o 3
       4- Apos serem feitas essas comparações ele salva a posição
       correta desses 2 elementos na variavel auxiliar e atualiza
       a original com essa parte em ordem, assim sucessivamente
       comparando de 1 em 1 e salvando em vetores auxiliares de 
       tamanho 2 esses resultados
       5- Apos a comparação de elemento com elemento o programa
       começa a fazer a comparação de subvetores com subvetores
       e salvando na variavel auxiliar os resultados dessas
       comparações:
         (v, 0, 1, 3) = compara os elementos 0 e 1 (que ja estao
         ordenados) com os elementos 2 e 3(tbm estão), gravando
         assim em subvetor aux de tamanho 4 os resultados dessas
         comparações de forma ordenada e substituindo no original
       6- E faz esse processo com o lado antes do meio e com o lado
       pos meio tambem, por meio da recursividade, e apos essas
       metades estarem ordenadas uma é comparada com a outra e 
       devidamente ordenada.
       7- O merge pode ser substituido por um insertion short,
       apos as repartições ele se torna bem eficaz;
*/

//Codigo:

void merge(int *v, int l, int m, int r)
{
    //quanto espaÃ§o?
    int tam = r+1-l;

    //alocar espaÃ§o auxiliar
    int *aux = malloc(tam*sizeof(int));

    //auxiliares
    int i=l; //inicio do sub-vetor esquerdo
    int j=m+1; //inicio do sub-vetor direito
    int k=0; //inicio do vetor auxiliar

    //ordenar em aux[k]
    while(k<tam) //condiÃ§Ã£o de parada do aux
    {
        if(i>m) //ordenou todo o primeiro sub-vetor
            aux[k++] = v[j++];//consome o segundo sub-vetor -> ordene no aux

        else if (j>r) //ordenou todo o segundo sub-vetor
            aux[k++] = v[i++];//consome o primeiro sub-vetor -> ordene no aux

        else if (v[i] < v[j]) //testar sub-vetores
            aux[k++] = v[i++];//ordene no aux
        else
            aux[k++] = v[j++];//ordene no aux
    }

    k=0; //indice do aux
    for(i=l; i<=r; i++) //indice do v
        v[i] = aux[k++];//copiar o aux[k] para v[i]
        
    //liberar memÃ³ria
    free(aux);
   
}

void merge_sort(int *v, int l, int r)
{
    if (l >= r) return;
    int m = (r+l)/2;
    merge_sort(v, l, m);
    merge_sort(v, m+1, r);
    merge(v, l, m, r);
}
