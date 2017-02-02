#include <catam.h>
double mu;
double a,b,c,d;
double eql,eqm,eqr;
double x[10000],y[10000];
int i,I;


  double d1(double x, double y)
{
  return pow((x+1-mu)*(x+1-mu)+y*y,0.5);
}
  double d2(double x, double y)
{
  return pow((x-mu)*(x-mu)+y*y,0.5);
}

double MinusOmx(double x)
{
  return -1*(-0.5*mu*pow(x+1-mu,2)-0.5*(1-mu)*pow(x-mu,2)-mu/fabs(x+1-mu)-(1-mu)/fabs(x-mu));
}

double Omx(double x)
{
  return (-0.5*mu*pow(x+1-mu,2)-0.5*(1-mu)*pow(x-mu,2)-mu/fabs(x+1-mu)-(1-mu)/fabs(x-mu));
}

double Omay(double y, double a)
{
 return -0.5*mu*d1(a,y)*d1(a,y)-0.5*(1-mu)*d2(a,y)*d2(a,y)-mu/d1(a,y)-(1-mu)/d2(a,y);
}

double Omeqtri(double x) 
{
 return -0.5*mu*d1(x,0.8660254)*d1(x,0.8660254)-0.5*(1-mu)*d2(x,0.8660254)*d2(x,0.8660254)-mu/d1(x,0.8660254)-(1-mu)/d2(x,0.8660254);
}


int MainCL(void) {
  double u[500],v[500];
  int i;

  mu=ReadDoubleCL("Enter mu:",0.5);

  CurveCL(Omx,-2,2,100,RedCC,AUTOAXES);

  for (i=0;i<10000;i++) {
    x[i]=-2+(double)i/2500;
    y[i]=MinusOmx(x[i]);
  }
 
  a=1,b=2;

  eql=MinCL(MinusOmx,-5,mu-1,1e-6);
  eqm=MinCL(MinusOmx,mu-1,mu,1e-6);
  eqr=MinCL(MinusOmx,mu,5,1e-6);

  printf("eql = %lf\neqm = %lf\neqr = %lf",eql,eqm,eqr);
  PauseCL();
  WClearCL();
  a=ReadDoubleCL("\n\nEnter equilibrium point",mu-0.5);

  for(i=0;i<50;i++) {
    u[i]=-2+(double)(i/12.5);
    v[i]=Omay(u[i],a);
  }

  printf("\n\nEquilibrium point in y direction");
  XYCurveCL(u,v,50,1,JOIN,RedCC,AUTOAXES);

  PauseCL();
  WClearCL();
  printf("\n\nEquilateral equilibrium \npoint in x direction");
  CurveCL(Omeqtri,-2,2,100,BlueCC,AUTOAXES);

  return 0;
}
