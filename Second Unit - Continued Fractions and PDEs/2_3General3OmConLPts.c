#include <catam.h>
double mu;
double tiny;
double ji;
double eql,eqm,eqr;
int k,I;
WindowCT w1,w2;

  double d1(double x, double y)
{
  return pow((x+1-mu)*(x+1-mu)+y*y,0.5);
}
  double d2(double x, double y)
{
  return pow((x-mu)*(x-mu)+y*y,0.5);
}
  void F(double t, double *x, double *xdot)
 {
  xdot[0]=x[2];
  xdot[1]=x[3];
  xdot[2]=2*x[3]+x[0]-mu*(x[0]+1-mu)/pow(d1(x[0],x[1]),3)-(1-mu)*(x[0]-mu)/pow(d2(x[0],x[1]),3);
  xdot[3]=-2*x[2]+x[1]-mu*x[1]/pow(d1(x[0],x[1]),3)-(1-mu)*x[1]/pow(d2(x[0],x[1]),3);
 }

double Om(double x, double y, double ji) 
{
  return -0.5*mu*d1(x,y)*d1(x,y)-0.5*(1-mu)*d2(x,y)*d2(x,y)-mu/d1(x,y)-(1-mu)/d2(x,y)-ji;
}

double MinusOmx(double x)
{
  return -1*(-0.5*mu*pow(x+1-mu,2)-0.5*(1-mu)*pow(x-mu,2)-mu/fabs(x+1-mu)-(1-mu)/fabs(x-mu));
}

double J(double x, double y, double u, double v) 
 {
   return 0.5*u*u+0.5*v*v+Om(x,y,0);
 }

int MainCL(void)
   
{
  double xx[50],yy[50],zz[50][50];
  double aberr=1e-4;
  double relerr=1e-4;
  double dtmin=1e-9;
  double x[4];
  double xdot[4];
  double a,t;
  double tfinal;
  double xdata[1000];
  double ydata[1000];
  double tdata[1000];
  double Jdata[1000];
  int nres;
  int i,j;
  double dt;
  int nleft;

  t=0;
  mu=ReadDoubleCL("Enter mu:",0.5);
  tiny=ReadDoubleCL("Enter maximal variance of J allowed:",1e-3);
  x[0]=ReadDoubleCL("Enter initial x-coordinate:",mu-0.5);
  x[1]=ReadDoubleCL("Enter initial y-coordinate:",0.867025);
  x[2]=ReadDoubleCL("Enter initial velocity in the x-direction:",0);
  x[3]=ReadDoubleCL("Enter initial velocity in the y-direction:",0);
  tfinal=ReadDoubleCL("Enter time you want to integrate up to:",15);
  dt=1e-4;
  nleft=(int)(tfinal/dt);
  dt=tfinal/nleft;
  nres=0;

  a=J(x[0],x[1],x[2],x[3]);
  
  while (nleft>0) {
    if (!RkfCL(4,aberr,relerr,&t,&dt,dtmin,F,x,xdot,&nleft)) {
      printf("End: Falls outside of Rkf tolerances :(");
      HaltCL();
	}
    if (nres<1000) {
      xdata[nres]=x[0];
      ydata[nres]=x[1];
      tdata[nres]=t;
      Jdata[nres]=J(x[0],x[1],x[2],x[3]);
      nres++;
      if (fabs(Jdata[nres]-a)<tiny) {printf("End: J varies unnacceptably");HaltCL();}
    }
  }

  ji=a;
 for (i=0;i<50;i++) {
   xx[i]=-2+(double)i/12.5;
   yy[i]=-2+(double)i/12.5;
 }
 for (i=0;i<50;i++) {
   for (j=0;j<50;j++) {
     zz[i][j]=Om(xx[i],yy[j],a);
   }
 }
 
 XYZContourCL(xx,yy,zz,50,50,1,50,1,-0.0001,0,CONTOURS2D,RedCC,AUTOAXES);

 /* Equilibria */

  eql=MinCL(MinusOmx,-5,mu-1,1e-6);
  eqm=MinCL(MinusOmx,mu-1,mu,1e-6);
  eqr=MinCL(MinusOmx,mu,5,1e-6);

  printf("Equilibrium points (X) are approx. at:\n(%lf,0.866025);\n(%lf,-0.866025);\n(%lf,0);\n(%lf,0);\n(%lf,0).",mu-0.5,mu-0.5,eql,eqm,eqr);
  PauseCL();
  XYSymbolCL(mu,0,TRIANGLE);
  XYSymbolCL(mu-1,0,SQUARE); 
  XYSymbolCL(mu-0.5,0.866025,XCROSS);
  XYSymbolCL(mu-0.5,-0.866025,XCROSS);
  XYSymbolCL(eql,0,XCROSS);
  XYSymbolCL(eqm,0,XCROSS);
  XYSymbolCL(eqr,0,XCROSS);
  XAxisLabelCL("x");
  YAxisLabelCL("y"); 
  XYCurveCL(xdata,ydata,nres,1,JOIN,BlueCC,PRESET);
  
  PauseCL();
  w1=WindowCL(0.1,0.1,0.1,0.1);
  WShowCL(w1);
  WTitleCL("Motion in x direction");
  XAxisLabelCL("t");
  YAxisLabelCL("x"); 
  XYCurveCL(tdata,xdata,nres,1,JOIN,BlueCC,AUTOAXES);
  
  PauseCL();
  w2=WindowCL(0.5,0.5,0.8,0.8);
  WShowCL(w2);
  WTitleCL("Motion in y direction");
  XAxisLabelCL("t");
  YAxisLabelCL("y"); 
  XYCurveCL(tdata,ydata,nres,1,JOIN,BlueCC,AUTOAXES);
  
 return 0;}
