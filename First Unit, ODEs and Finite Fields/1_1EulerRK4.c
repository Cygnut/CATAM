#include <catam.h>
int opt;
double dydx(double x,double y) {
  return -6*y-2*x*x*x+11*x*x-20*x-4;}
double k1,k2,k3,k4,h,x[2500],y[2500],t[2500],E[2500];
int i,n;
int MainCL(void) {

  h= ReadDoubleCL("Enter step-size:",0.01);
  n=ReadIntCL("Enter number of steps (<100):",50);
  x[0]=0;
  y[0]=4;

  for (i=0;i<n;i++) {
    x[i]=h*i;
    t[i]=4*exp(-6*x[i])-x[i]*x[i]*x[i]/3+2*x[i]*x[i]-4*x[i];
  }
do
  {
    printf("1: Use Euler's Method \n");
    printf("2: Use RK4's Method \n");
    printf("3: Plot <Exact> solution \n");
    printf("4: Quit..");
    printf("\nMake your choice:\n\n");
    fflush(stdout);
    scanf("%d",&opt);
    switch(opt)
      {
      case 1:
	printf("By Euler's Method:\n\n");
     for (i=1;i<n;i++) {
    y[i]=y[i-1]+h*dydx(x[i-1],y[i-1]);
    E[i]=y[i]-t[i];
  }
  
  printf("x:          y:          Global Error:");   
  printf("\n");
  for (i=0;i<n;i++) {
    printf("%f    %f    %f\n",x[i],y[i],E[i]);}
  
  PauseCL();
  XRangeCL(0,4);
  YRangeCL(-5,5);
  YAxisLabelCL("Estimate/Exact");
  XYCurveCL(x,y,n,1,JOIN,BlueCC,AUTOAXES); 
break;
case 2:
  printf("By Runge-Kutta's (4) Method:\n\n");    
 for (i=1;i<n;i++) {
    k1=h*dydx(x[i-1],y[i-1]);
    k2=h*dydx(x[i-1]+0.5*h,y[i-1]+0.5*k1);
    k3=h*dydx(x[i-1]+0.5*h,y[i-1]+0.5*k2);
    k4=h*dydx(x[i-1]+h,y[i-1]+k3);
    y[i]=y[i-1]+(k1+2*k2+2*k3+k4)/6;
    E[i]=y[i]-t[i];
  }

  printf("x:          y:          Global Error:");
  printf("\n");
  for (i=0;i<n;i++) {
    printf("%f    %f    %f\n",x[i],y[i],E[i]);} 

  PauseCL();
  XRangeCL(0,4);
  YRangeCL(-5,5);
  YAxisLabelCL("Estimate/Exact");
  XYCurveCL(x,y,n,1,JOIN,RedCC,AUTOAXES);
break;
case 3:
  XRangeCL(0,4);
  YRangeCL(-5,5);
  YAxisLabelCL("Estimate/Exact");
  XYCurveCL(x,t,n,1,JOIN,GreenCC,AUTOAXES);
      }
  }
 while(opt<4);
 return 0;}



