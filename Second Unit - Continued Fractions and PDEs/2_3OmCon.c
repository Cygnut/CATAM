#include <catam.h>
double mu;

  double d1(double x, double y)
{
  return pow((x+1-mu)*(x+1-mu)+y*y,0.5);
}
  double d2(double x, double y)
{
  return pow((x-mu)*(x-mu)+y*y,0.5);
}
  double Om(double x, double y) 
{
  return -0.5*mu*d1(x,y)*d1(x,y)-0.5*(1-mu)*d2(x,y)*d2(x,y)-mu/d1(x,y)-(1-mu)/d2(x,y);
}
   
int MainCL(void) {
  double x[50];
  double y[50];
  double z[50][50];
  int i;
  int j;
  mu=0.5;
  while (mu<2) {
  mu=ReadDoubleCL("Enter mu:",0.5);

 for (i=0;i<50;i++) {
    x[i]=-2+(double)i/12.5;
    y[i]=-2+(double)i/12.5;
 }  
 for (i=0;i<50;i++) {
 for (j=0;j<50;j++) {
      z[i][j]=Om(x[i],y[j]);
     }
 }
  
 j=0;
 j=ReadIntCL("'1' for a surface, '2' for a contour plot",1);

   if(j==2) {
 XYZContourCL(x,y,z,50,50,1,50,50,-5,0,CONTOURS2D,RedCC,AUTOAXES);
   }
   if(j==1) {
 XYZSurfaceCL(x,y,z,50,50,1,50,WIREFRAME,RedCC,WhiteCC,AUTOAXES);
   }

  XYSymbolCL(mu,0,TRIANGLE);
  XYSymbolCL(mu-1,0,SQUARE); 
  XYSymbolCL(mu-0.5,0.866025,XCROSS);
  XYSymbolCL(mu-0.5,-0.866025,XCROSS);
  PauseCL();
  WClearCL();
  }

 return 0;
}
