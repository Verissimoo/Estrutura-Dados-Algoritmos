#include <stdio.h>
#include <stdlib.h>

#define max 100


int main()
{

 int m;   // tanto de numeros q terao na operação
 int resultado = 0;
 int n = 0;
 char op = '\0' ;
 char c;
 int cont[max];
 int nmax = 0;


 while(m != 0){
     printf("Digite o tamanho da sua sequencia (maximo %d)\n", max);
     scanf("%d", &m);

 printf("Digite %d numeros:\n", m);
 for(int i=0; i< m; i++){
    scanf("%d%c", &n, &c);

    if(op == '+'){
        resultado += n;
    } else if(op == '-'){
        resultado -= n;
    } else if(op == '\0'){
        resultado = n;
    }
    op = c;
    cont[i] = resultado;

 }
  nmax ++;
 }

 for(int j=0; j< nmax -1; j++){
    printf("Teste %d\n", j+1);
    printf("%d\n", cont[j]);
    printf("\n");
   }

 return 0;
}

