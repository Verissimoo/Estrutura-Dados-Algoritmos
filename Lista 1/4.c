#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{

    //a = largura
    //b = comprimento
    //c = altura
  int a, b, c;
  int x, y, z;
  int contA, contB, contC;
  int totalH, totalV;

  printf("Digite o tamanho do container:\n");
  scanf("%d %d %d", &a, &b, &c);

  printf("Digite o tamanho do navio:\n");
  scanf("%d %d %d", &x, &y, &z);

  if(x>a && y>b && z>c){
        if(x>a){
            contA = abs(x / a);
        };
        if(y>b){
            contB = abs(y / b);
        };
        if(z>c){
            contC = abs(z / c);
        };

  };

  //contA = numero de containers que cabem na horizontal
  //contB = numero de containers que cabem no comprimento
  //contC = numero de containers que cabem empilhados
  //total = quantos entao cabem no navio ?

  totalH = contA * contB;
  totalV = totalH * contC;

  printf("%d\n", totalV);


   return 0;
}