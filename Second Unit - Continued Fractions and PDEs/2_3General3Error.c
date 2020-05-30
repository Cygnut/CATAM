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
  double X,Y,U,V;
  double xdot[4];
  double t;
  double tfinal;
  double xdata[1000];
  double ydata[1000];
  double tdata[1000];
  double Jdata[1000];
  int nres;
  int i;
  int use;
  double dt;
  int nleft;

  use=0;
  mu=ReadDoubleCL("Enter mu:",0.5);
  tiny=ReadDoubleCL("Enter maximal variance of J allowed",1e-3);
  X=ReadDoubleCL("Enter initial x-coordinate:",0.25);
  Y=ReadDoubleCL("Enter initial y-coordinate:",0);
  U=ReadDoubleCL("Enter initial velocity in the x-direction:",0);
  V=ReadDoubleCL("Enter initial velocity in the y-direction:",0);
  tfinal=ReadDoubleCL("Enter time you want to integrate up to:",15);

  printf("Note: Standard RKf4 use has absolute\nerror 1e-4, relative error at 1e-4\nand initial time step at (of\norder) 1e-4.\n");
 
  while (use<3) {

    for (i=0;i<4;i++) {xdot[i]=0;}
    x[0]=X;x[1]=Y;x[2]=U;x[3]=V;
    for (i=0;i<1000;i++) {
      xdata[i]=0;
      ydata[i]=0;
      tdata[i]=0;
      Jdata[i]=0;
    }

    t=0;
    printf("\nEnter max absolute error\n on use #%i of RKf\n",use+1);
    fflush(stdout);
    scanf("%lf",&aberr);
    printf("\nEnter max relative error\n on use #%i of RKf\n",use+1);
    fflush(stdout);
    scanf("%lf",&relerr);
    printf("\nEnter initial time step\n on use #%i of RKf\n",use+1);
    fflush(stdout);
    scanf("%lf",&dt);

  nleft=(int)(tfinal/dt);
  dt=tfinal/nleft;
  nres=0;

  ji=J(x[0],x[1],x[2],x[3]);
  while (nleft>0) {
    if (!RkfCL(4,aberr,relerr,&t,&dt,dtmin,F,x,xdot,&nleft)) {
      printf("\n\nEnding on Use %i: Criteria for accurate\n RKf use falls outside\n of tolerances :(\n",use+1);
      HaltCL();
    }
    if (nres<1000) {
      xdata[nres]=x[0];
      ydata[nres]=x[1];
      tdata[nres]=t;
      Jdata[nres]=J(x[0],x[1],x[2],x[3]);
      nres++;
      if (fabs(Jdata[nres]-ji)<tiny) {printf("Ending on Use %i:\n J varies unnacceptably.\n",use+1);
      HaltCL();
}
    }
  }
  PauseCL();
   XAxisLabelCL("x");
   YAxisLabelCL("y"); 
   if (use==0) {XYCurveCL(xdata,ydata,nres,1,JOIN,RedCC,AUTOAXES);
   }
   if (use==1) {XYCurveCL(xdata,ydata,nres,1,JOIN,YellowCC,PRESET);
   }
   if (use==2) {XYCurveCL(xdata,ydata,nres,1,JOIN,GreenCC,PRESET);
   }
  
   use++;
  }
  
  printf("\n\nUse 1: Red,\nUse 2: Yellow,\nUse 3: Green."); 

  return 0;}
