#include <catam.h>

double tiny=0.005;
double p,h,ky1,ky2,ky3,ky4,kz1,kz2,kz3,kz4,x[1000],y[1000],z[1000],t[1000],E[1000];
int i,n;

  double dydx(double y,double z) {
      return z;}
  double dzdx(double y,double z) {
      return -z-p*p*y;}

int MainCL(void) {
  x[0]=0;
  y[0]=0;
  z[0]=1;
   
  p=ReadDoubleCL("Enter value of p",1);
  h=ReadDoubleCL("Enter step-size",0.01);
  n=ReadIntCL("Enter number of steps",50);
  
 for (i=1;i<n;i++) {
    x[i]=i*h;
    ky1=h*dydx(y[i-1],z[i-1]);
    kz1=h*dzdx(y[i-1],z[i-1]);
    ky2=h*dydx(y[i-1]+0.5*ky1,z[i-1]+0.5*kz1);
    kz2=h*dzdx(y[i-1]+0.5*ky1,z[i-1]+0.5*kz1);
    ky3=h*dydx(y[i-1]+0.5*ky2,z[i-1]+0.5*kz2);
    kz3=h*dzdx(y[i-1]+0.5*ky2,z[i-1]+0.5*kz2);
    ky4=h*dydx(y[i-1]+ky3,z[i-1]+kz3);
    kz4=h*dzdx(y[i-1]+ky3,z[i-1]+kz3);
    y[i]=y[i-1]+(ky1+2*ky2+2*ky3+ky4)/6;
    z[i]=z[i-1]+(kz1+2*kz2+2*kz3+kz4)/6;
 }

 if (fabs(p)+tiny<0.5) {for (i=0;i<n;i++) {
   t[i]=(2/sqrt(1-4*p*p))*exp(-0.5*x[i])*sinh(0.5*x[i]*sqrt(1-4*p*p));}}

 if (fabs(p)-tiny>0.5) {for (i=0;i<n;i++) {
   t[i]=(2/sqrt(4*p*p-1))*exp(-0.5*x[i])*sin(0.5*x[i]*sqrt(4*p*p-1));}} 

 if (fabs(p-0.5)<tiny) {for (i=0;i<n;i++) {t[i]=x[i]*exp(-0.5*x[i]);}}
 
 for (i=0;i<n;i++) {E[i]=y[i]-t[i];}

 printf("x:          y:          Global Error:");   
 printf("\n");
  for (i=0;i<n;i++) {
    printf("%f    %f    %f\n",x[i],y[i],E[i]);}

  PauseCL();
  XYCurveCL(x,y,n,1,JOIN,BlueCC,AUTOAXES);  
  return 0;
}
