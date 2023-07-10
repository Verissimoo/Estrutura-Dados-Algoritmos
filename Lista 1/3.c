#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
  int Xm, Ym, Xr, Yr;
  int cruzamentos;

  printf("Digite as cordenadas:\n");
  scanf("%d %d %d %d", &Xm, &Ym, &Xr, &Yr);

  cruzamentos = abs(Xm - Xr) + abs(Ym - Yr);

  printf("%d\n", cruzamentos);

   return 0;
}
