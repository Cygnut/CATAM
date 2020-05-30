#include <catam.h>
double mu;
double tiny;

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

double Om(double x, double y) 
{
  return -0.5*mu*d1(x,y)*d1(x,y)-0.5*(1-mu)*d2(x,y)*d2(x,y)-mu/d1(x,y)-(1-mu)/d2(x,y);
}

double J(double x, double y, double u, double v) 
 {
   return 0.5*u*u+0.5*v*v+Om(x,y);
 }

int MainCL(void)
   
{
  double aberr=1e-4;
  double relerr=1e-4;
  double dtmin=1e-9;
  double x[4];
  double ji;
  double xdot[4];
  double t;
  double tfinal;
  double xdata[1000];
  double ydata[1000];
  double tdata[1000];
  double Jdata[1000];
  int nres;
  int i;
  double dt;
  int nleft;

  t=0;
  mu=ReadDoubleCL("Enter mu:",0.5);
  tiny=ReadDoubleCL("Enter maximal variance of J allowed",1e-3);
  x[0]=ReadDoubleCL("Enter initial x-coordinate:",0.25);
  x[1]=ReadDoubleCL("Enter initial y-coordinate:",0);
  x[2]=ReadDoubleCL("Enter initial velocity in the x-direction:",0);
  x[3]=ReadDoubleCL("Enter initial velocity in the y-direction:",0);
  tfinal=ReadDoubleCL("Enter time you want to integrate up to:",15);
  dt=1e-4;
  nleft=(int)(tfinal/dt);
  dt=tfinal/nleft;
  nres=0;

  ji=J(x[0],x[1],x[2],x[3]);
  while (nleft>0) {
    if (!RkfCL(4,aberr,relerr,&t,&dt,dtmin,F,x,xdot,&nleft)) {
      printf("End: Criteria for accurate RKf use\nfalls outside of tolerances :(");
      HaltCL();
    }
    if (nres<1000) {
      xdata[nres]=x[0];
      ydata[nres]=x[1];
      tdata[nres]=t;
      Jdata[nres]=J(x[0],x[1],x[2],x[3]);
      nres++;
      if (fabs(Jdata[nres]-ji)<tiny) {printf("End: J varies unnacceptably");HaltCL();}
    }
  }
  PauseCL();
   XAxisLabelCL("x");
   YAxisLabelCL("y"); 
   /* XYZCurveCL(tdata,xdata,ydata,nres,1,JOIN,RedCC,AUTOAXES);*/ 
   XYCurveCL(xdata,ydata,nres,1,JOIN,BlueCC,AUTOAXES);
  
   printf("Variation of J along path:\n\n");
   printf("Time:       J:\n");
  for (i=0;i<10;i++) {printf("%lf    %lf\n",tdata[100*i],Jdata[100*i]);}
  printf("\nValue of J initially: %lf\n",ji);
  return 0;}
