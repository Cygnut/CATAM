#include <catam.h>

double epsilon;
double pi=3.1415926535897932;
double r,t,x[1000],xl[1000],xu[1000];

int a[1000],p[1000],q[1000],i,j,M,option;

int floint(double X) {
  int I;
    I=0;
    while(X>0) {X=X-1;I=I+1;}
    return I-1;}

int main(void) {

  epsilon=pow(2,-52);

  do {

  printf("\nSelect which real to approximate via continued fractions:\n");
  printf("1: pi,\n");
  printf("2: 2*pi,\n");
  printf("3: pi^2,\n");
  printf("4: e,\n");
  printf("5: e^1/2,\n");
  printf("6: 2*e,\n");
  printf("7: sqrt(3)*tan(1/sqrt(3)),\n");
  printf("8: 1/2*(1+sqrt(13)),\n");
  printf("9: *Or*, enter an non-square integer in [1,20]u[280,300] for square rooting\n and then finding the continued fraction of:\n");
  printf("(Note: A square integer, n, has continued fraction form [n-1])");
  printf("10: <Or>, enter a decimal to be approximated..\n\n");
  fflush(stdout);
  scanf("%i",&option);

  switch(option) {
    case 1:
    r=pi;
    xl[0]=(1-epsilon)*r;
    xu[0]=(1+epsilon)*r;
    x[0]=r;
    break;
    case 2:
    r=pi;
    xl[0]=(1-epsilon)*r;
    xu[0]=(1+epsilon)*r;
    xl[0]=(1-epsilon)*2*xl[0];
    xu[0]=(1+epsilon)*2*xu[0];
    x[0]=2*pi;
    break;
    case 3:
    r=pi;
    xl[0]=(1-epsilon)*r;
    xu[0]=(1+epsilon)*r;
    xl[0]=(1-epsilon)*pow(xl[0],2);
    xu[0]=(1+epsilon)*pow(xu[0],2);
    x[0]=pow(pi,2);
    break;
    case 4:
    r=1;
    xl[0]=(1-epsilon)*r;
    xu[0]=(1+epsilon)*r;
    xl[0]=(1-epsilon)*exp(xl[0]);
    xu[0]=(1+epsilon)*exp(xu[0]);
    x[0]=exp(1);
    break;
    case 5:
    r=0.5;
    xl[0]=(1-epsilon)*r;
    xu[0]=(1+epsilon)*r;
    xl[0]=(1-epsilon)*exp(xl[0]);
    xu[0]=(1+epsilon)*exp(xu[0]);
    x[0]=exp(0.5);
    break;
    case 6:
    r=1;
    xl[0]=(1-epsilon)*r;
    xu[0]=(1+epsilon)*r;
    xl[0]=(1-epsilon)*2*exp(xl[0]);
    xu[0]=(1+epsilon)*2*exp(xu[0]);
    x[0]=2*exp(1);
    break;
    case 7:
    r=0.3333333333333333;
    xl[0]=(1-epsilon)*r;
    xu[0]=(1+epsilon)*r;
    xl[0]=(1-epsilon)*(tan(sqrt(xl[0])))/sqrt(xl[0]);
    xu[0]=(1+epsilon)*(tan(sqrt(xu[0])))/sqrt(xu[0]);
    x[0]=tan(sqrt(r))/sqrt(r);
    break;
    case 8:
    r=13;
    xl[0]=(1-epsilon)*r;
    xu[0]=(1+epsilon)*r;
    xl[0]=(1-epsilon)*0.5*(1+sqrt(13));
    xu[0]=(1+epsilon)*0.5*(1+sqrt(13));
    x[0]=0.5*(1+sqrt(13));
    break;
    case 9:
    printf("\n\n");
    scanf("%lf",&t);
    r=sqrt(t);
    x[0]=r;
    xl[0]=(1-epsilon)*t;
    xu[0]=(1+epsilon)*t;
    xl[0]=(1-epsilon)*sqrt(xl[0]);
    xu[0]=(1+epsilon)*sqrt(xu[0]);
    break;
    case 10:
    printf("\n\n");
    scanf("%lf",&r);
    x[0]=r;
    xl[0]=(1-epsilon)*r;
    xu[0]=(1+epsilon)*r;
    break;
    default:
    printf("\nUnrecognized input :( ");
    break;
  }


  M=0,i=0;

  while (M==0) {

    a[i]=floint(x[i]);
    x[i+1]=1/(x[i]-a[i]);
    xl[i+1]=1/(xu[i]-a[i]);
    xu[i+1]=1/(xl[i]-a[i]);

    xl[i+1]=xl[i+1]-epsilon*xl[i+1];
    xu[i+1]=xu[i+1]+epsilon*xu[i+1];

    if(floint(xl[i])!=floint(xu[i])) {M=1;}
    if(i>0) {
    if(x[i+1]==0) {M=2;}
    }
    i=i+1;
   }
 
 
   printf("\n\nContinued fraction form of this real is:\n");
   printf("[");
   for(j=0;j<=i-3;j++) {
   printf("%i,",a[j]);
   }
   printf("%i]",a[i-2]);


   printf("\n\nConvergents:\n");

   p[0]=0,p[1]=1,q[0]=1,q[1]=0;

   for(j=2;j<=i;j++) {
     p[j]=a[j-2]*p[j-1]+p[j-2];
     q[j]=a[j-2]*q[j-1]+q[j-2];
   }

   for (j=2;j<=i;j++) {
     printf("p[%i]=%i      q[%i]=%i\n",j-2,p[j],j-2,q[j]);
   }

  } while (option<10);

  return 0;}
