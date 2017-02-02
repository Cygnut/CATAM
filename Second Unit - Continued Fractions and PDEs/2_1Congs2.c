#include <catam.h>

int uf,vf,b,bh,k,n,B,i,j,I,U,V,hcf,soln,a[1000],u[1000],v[1000],p[1002],q[1002];

int main(void) {

  printf("For the given eqn of form:\n\n");
  printf("         ax=b (mod n)     \n\n");

  printf("Enter a:\n");
  fflush(stdout);
  scanf("%i",&uf);
  printf("Enter b:\n");
  fflush(stdout);
  scanf("%i",&b);
  printf("Enter n:\n");
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

   hcf=0,k=0;
   while (u[0]>=p[i+1]) {
     u[0]=u[0]-p[i+1];
     hcf++;
   }
   B=vf;
   while (B>=hcf) {
     B=B-hcf;
     k++;
   }
  B=b;
  bh=0;
 while (B>=hcf) {
   B=B-hcf;
   bh++;
}
  if (B>0) {printf("No solns to this eqn.");}
  else {
   soln=(q[i]*bh+k)%k;
   if (uf*q[i]-vf*p[i]>0) {
   printf("Solns are: %i (mod %i)",soln,k);}
   else {soln=(-soln+k)%k;
   printf("Solns are: %i (mod %i)",soln,k);}  
  }
   return 0;}

