#include <catam.h>

int uf,vf,i,j,I,U,V,hcf,a[1000],u[1000],v[1000],p[1002],q[1002];

int main(void) {

  printf("Enter u:\n");
  fflush(stdout);
  scanf("%i",&uf);
  printf("Enter v:\n");
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

   p[0]=0,p[1]=1,q[0]=1,q[1]=0;

   for(j=2;j<=i+1;j++) {
     p[j]=a[j-2]*p[j-1]+p[j-2];
     q[j]=a[j-2]*q[j-1]+q[j-2];
   }

   hcf=u[0]/p[i+1];

   if (hcf==1) {printf("\n  *u & v are coprime!*\n");}
   else {printf("\n  The hcf of u & v is %i\n",hcf);}

   if (uf*q[i]-vf*p[i]>0) {printf(" and: %iu - %iv = %i",q[i],p[i],hcf);}
   else {printf(" and: %iv - %iu = %i",p[i],q[i],hcf);}  

   return 0;}

