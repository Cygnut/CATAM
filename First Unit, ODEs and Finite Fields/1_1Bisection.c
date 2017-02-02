#include <catam.h>

double a,b,m,pa,pb,phalf;
double p,h,e,ky1,ky2,ky3,ky4,kz1,kz2,kz3,kz4,x[1000000],y[1000000],z[1000000];
int i,n;
WindowCT w;

  double dydx(double y,double z) {
      return z;}
  double dzdx(double y,double z) {
      return -z-p*p*y;}

double xone(double h) {
     n = (1/h)+1;
      x[0]=0;
      y[0]=0;
      z[0]=1;
 for (i=1;i<n+1;i++) {
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

return y[n];}

int MainCL(void) {
  x[0]=0;
  y[0]=0;
  z[0]=1;

 e=ReadDoubleCL("Epsilon:",0.0000001);
 h=ReadDoubleCL("Step-size (dividing 1 naturally):",0.001);
 PrintfCL(1,1,"Now, please enter the interval required to search in");
 PrintfCL(1,2,"for an eigenvalue estimate.");
 PrintfCL(1,3,"For the first, try (3,4);");
 PrintfCL(1,4,"Second, try (6,7);");
 PrintfCL(1,5,"Third, (9,10).");
 PrintfCL(1,6,"And so on.");

 a=ReadDoubleCL("Left side of interval:",3);
 b=ReadDoubleCL("Right side of interval:",4);

 do {
 
 m=0.5*(a+b);
 p=a;
 pa=xone(h);
 p=b;
 pb=xone(h);
 p=m;
 phalf=xone(h);
 
 if (pa>0) {if (phalf>0) {a=m;} else {b=m;}}
 if (pa<0) {if (phalf>0) {b=m;} else {a=m;}}

 } while (fabs(phalf)>e); 

 PrintfCL(1,7,"Eigenvalue estimate is %f.",m);

 w = WindowCL(0.1,0.1,0.9,0.7);
 WShowCL(w);
 WTitleCL("Graph for approximated eigenvalue soln");
  PauseCL();
  XRangeCL(0,4);
  YRangeCL(-5,5);
  XAxisLabelCL("x");
  YAxisLabelCL("Estimate, Y");
  XYCurveCL(x,y,n+1,1,JOIN,BlueCC,AUTOAXES); 


return 0;}
