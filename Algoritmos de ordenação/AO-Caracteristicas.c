//CARACTERISTICAS:

//1-Complexidade assintotica (custo) 
/*   
- O(N^2) = ideal para arquivos pequenos pois faz muitas
comparações, porem sao simples
Ex:

- O(n log n) = adequado para arquivos grandes, pois faz menos
comparações porem comparações complexas
Ex: 

*/

//2-Estabilidade (`)
/*
- Referesse a capacidade do algoritmo se manter ordenado tendo
2 valores "iguais" porem um tendo que manter uma ordem instavel
entre eles
Ex: 1, 1`, 2, 3

*/

//3-Adaptativa
/*
- É quando o algortimo aproveita a ordenação que o vetor ja possui
*/

//4-Memoria extra
/*
- In place = quando o algoritmo para se ordenar nn depende
da criação de outro array auxiliar
*/

//5-Algortimos de ordenação interna
/*
-Metodos eficientes:
   -Adequado para arquivos maiores
   -Custo O(n log n) (vantagem)
   -Mais complexos
-Metodos elementares:
   -Mais simples, otimo para arquivos pequenos
   -Custo O(n^2) (desvantagem)
*/

//Defines para otimizar:
#define key(A) A
#define less(A, B) (key(A) < key(B)) // Verifica se B é menor que A
#define exch(A, B) { Item t=A; A=B; B=t; } // Swap A e B
#define compexch(A, B) if(less(B, A)) exch(A, B) //Verifica e Swapa

