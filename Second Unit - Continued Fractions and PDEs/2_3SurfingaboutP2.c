#include <catam.h>

double d2(double x,double y) 
{
  return pow(y*y+(x-0.5)*(x-0.5),0.5);
}

double J(double x,double y,double u, double v)
{
  return 0.5*u*u+0.5*v*v-0.5/d2(x,y);
}

void F(double t, double *x, double *xdot)
{
  xdot[0]=x[2];
  xdot[1]=x[3];
  xdot[2]=2*x[3]-0.5*(x[0]-0.5)/pow(d2(x[0],x[1]),3);
  xdot[3]=-2*x[2]-0.5*x[1]/pow(d2(x[0],x[1]),3);
}

int MainCL(void) {

  double aberr=1e-4;
  double relerr=1e-4;
  double dtmin=1e-9;
  double x[4];
  double xdot[4];
  double t;
  double a;
  double tfinal;
  double xdata[1000];
  double ydata[1000];
  double udata[1000];
  double vdata[1000];
  double tdata[1000];
  int nres;
  int i;
  double dt;
  int nleft;

  t=0;
  a=ReadDoubleCL("Enter radius of ideal orbit:",0.1);
  x[0]=0.5+a;
  x[1]=0;
  x[2]=0;
  x[3]=a*(-1+sqrt(1+1/(2*pow(a,3))));
  tfinal=ReadDoubleCL("Enter time you want to integrate up to:",15);
  dt=1e-4;
  nleft=(int) (tfinal/dt);
  nres=0;
  while (nleft>0) {
    if(!RkfCL(4,aberr,relerr,&t,&dt,dtmin,F,x,xdot,&nleft)) {
      printf("Falls outside of tolerances :(");
      HaltCL();
    }
    if (nres<1000) {
      xdata[nres]=x[0];
      ydata[nres]=x[1];
      udata[nres]=x[2];
      vdata[nres]=x[3];
      tdata[nres]=t;
      nres++;
    }
  }
  PauseCL();
  printf("Enter 1 for a 2D representation\nor 2 for a 3D one.\n");
  fflush(stdout);
  scanf("%i",&i);
  if (i==1) {
    XAxisLabelCL("x");
    YAxisLabelCL("y");
  XYCurveCL(xdata,ydata,nres,1,JOIN,BlueCC,AUTOAXES);
  }
  if (i==2) {
  XYZCurveCL(tdata,xdata,ydata,nres,1,JOIN,BlueCC,AUTOAXES);
  XAxisLabelCL("t");
  YAxisLabelCL("x");
  ZAxisLabelCL("y");
  }
  printf("\n\nSample data of distance for\nP2 and J during the motion:\n\n");
  printf("Time:       P2 dist.:   J:\n");
  for (i=0;i<10;i++) {printf("%lf    %lf   %lf\n",tdata[100*i],d2(xdata[100*i],ydata[100*i]),J(xdata[100*i],ydata[100*i],udata[100*i],vdata[100*i]));}
  printf("\n\n\n\n");
  PauseCL();
  return 0;}


