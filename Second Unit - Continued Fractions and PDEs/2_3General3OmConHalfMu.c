#include <catam.h>
/*Specifically for the equal mass case only!*/
double mu=0.5;
double ji;

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

double J(double x, double y, double u, double v) 
 {
   return 0.5*u*u+0.5*v*v+Om(x,y,0);
 }

int MainCL(void)
   
{
  double X[50],Y[50],Z[50][50];
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
  x[0]=ReadDoubleCL("Enter initial x-coordinate:",0.25);
  x[1]=ReadDoubleCL("Enter initial y-coordinate:",0);
  x[2]=ReadDoubleCL("Enter initial velocity in the x-direction:",0);
  x[3]=ReadDoubleCL("Enter initial velocity in the y-direction:",-1.3);
  tfinal=ReadDoubleCL("Enter time you want to integrate up to:",15);
  dt=1e-4;
  nleft=(int)(tfinal/dt);
  dt=tfinal/nleft;
  nres=0;

  a=J(x[0],x[1],x[2],x[3]);
  
  while (nleft>0) {
    if (!RkfCL(4,aberr,relerr,&t,&dt,dtmin,F,x,xdot,&nleft)) {
      printf("Falls outside of tolerances :(");
      HaltCL();
    }
    if (nres<1000) {
      xdata[nres]=x[0];
      ydata[nres]=x[1];
      tdata[nres]=t;
      Jdata[nres]=J(x[0],x[1],x[2],x[3]);
      nres++;
    }
  }

  ji=a;
  for (i=0;i<50;i++) {
   X[i]=-2+(double)i/12.5;
   Y[i]=-2+(double)i/12.5;
 }
 for (i=0;i<50;i++) {
   for (j=0;j<50;j++) {
     Z[i][j]=Om(X[i],Y[j],ji);
   }
 }

 XYZContourCL(X,Y,Z,50,50,1,50,1,-0.0001,0,CONTOURS2D,RedCC,AUTOAXES);
 

  PauseCL();
   XAxisLabelCL("x");
   YAxisLabelCL("y"); 
   XYCurveCL(xdata,ydata,nres,1,JOIN,BlueCC,PRESET);
   printf("Sample data of J during the motion:\n\n");
   printf("Time:        J:\n");
  for (i=0;i<10;i++) {printf("%lf     %lf\n",tdata[100*i],Jdata[100*i]);}
  printf("\n\nJ = %lf initially\n",ji);
  return 0;}
