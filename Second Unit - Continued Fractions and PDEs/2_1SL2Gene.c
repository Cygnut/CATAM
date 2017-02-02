#include <catam.h>

int M[2][2],m,n,i,j,f,I,U,V,a[1000],u[1000],v[1000],p[1000],q[1000];

int main(void) {

  printf("Input your element of SL2(Z):\n");

  for (m=0;m<=1;m++) {
  for (n=0;n<=1;n++) {
    int k;
    printf("Input element in row %i, column %i:\n",m+1,n+1);
    fflush(stdout);
    scanf("%i",&k);
    M[m][n]=k;
  }
  }
  if (M[0][0]*M[1][1]-M[0][1]*M[1][0]==1) {

  u[0]=M[0][0],v[0]=M[1][0];
 
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

   I=ceil(i/2);

   for (j=0;j<=I+2;j++) {
     a[2*j+1]=-a[2*j+1];}

   /*"i-1" is the value of N in a.*/

   if (i%2==0) {
     f=(M[0][1]-p[i])/p[i+1];}
   else {f=(M[0][1]+p[i])/p[i+1];}

   printf("\nExpansion in terms of S & T is:\n");

   if ((i-1)%4==0) {printf("-");}
   if ((i-1)%4==1) {printf("-");} 

  for (j=0;j<=i-1;j++) {
     printf("(T^%iS)",a[j]);
   }
   printf ("T^%i\n",f);
  }

  else {printf("That's not in SL2(Z)!");}

   return 0;
}
