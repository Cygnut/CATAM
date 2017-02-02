#include <catam.h>
int i,j,p,x[100];

int Inv(int iv,int jv,int pv) {int m;
 m = iv*jv%pv; 
 return m;}

int MainCL(void) {
printf("Input prime, smaller than 100:\n");
  fflush(stdout);
  scanf("%i",&p);

  for (i=1;i<p;i++) {
  for (j=1;j<p;j++) {
    int n;
    n = Inv(i,j,p);
    if (abs(n-1)<0.5) {x[i-1] = j;}
  }
  }
  printf("\nUnit  Inverse\n");
  for (i=1;i<p;i++) {printf("%i     %i\n",i,x[i-1]);}
  return 0;}
