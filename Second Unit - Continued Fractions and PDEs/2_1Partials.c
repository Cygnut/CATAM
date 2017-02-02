#include <catam.h>

int uf,vf,i,j,I,U,V,a[1000],u[1000],v[1000],p[1002],q[1002];

int main(void) {

  printf("Enter numerator:\n");
  fflush(stdout);
  scanf("%i",&uf);
  printf("Enter denominator:\n");
  fflush(stdout);
  scanf("%i",&vf);
 
  u[0]=uf;
  v[0]=vf;
 
  i=0,U=1;

  while (U>0) {
  U=u[i];
  V=v[i];
  I=0;
  while (U>=V) {
    U=U-V;
    I=I+1;}
  a[i]=I;
  u[i+1]=V;
  v[i+1]=U;

  i=i+1;
  }

  /*Didn't divide once!! :D */

  printf("\n");
  printf("Continued fraction form of %i/%i is: ",uf,vf);
  printf("[");
   for(j=0;j<=i-2;j++) {
     printf("%i,",a[j]);
   }
   printf("%i",a[i-1]);
   printf("]\n\n");

   printf("Convergents:\n");

   p[0]=0,p[1]=1,q[0]=1,q[1]=0;

   for(j=2;j<=i+1;j++) {
     p[j]=a[j-2]*p[j-1]+p[j-2];
     q[j]=a[j-2]*q[j-1]+q[j-2];
   }

   for (j=2;j<=i+1;j++) {
     printf("p[%i]=%i      q[%i]=%i\n",j-2,p[j],j-2,q[j]);
   }
   return 0;}
