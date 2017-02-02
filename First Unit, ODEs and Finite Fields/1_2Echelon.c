#include <catam.h>

double tiny=5e-20;
int p,i,j,k,l,I,J,r,c,m,n;
int x[100],X[10][10],TX[10][10];
int Inv(int iv,int jv,int pv) {int m;
 m = iv*jv%pv; 
 return m;}

int MainCL(void) {
   
  printf("Input prime, smaller than 100:\n");
     fflush(stdout);
     scanf("%i",&p);

  for (i=1;i<p;i++) {
  for (j=1;j<p;j++) {
    int n;
    n = Inv(i,j,p);
    if (abs(n-1)<tiny) {x[i-1] = j;}
  }
  }


/*---Main---*/

     printf("Input number of rows:\n");
     fflush(stdout);
     scanf("%i",&r);
     printf("Input number of columns:\n");
     fflush(stdout);
     scanf("%i",&c);
     
      
  for (m=0;m<r;m++) {
  for (n=0;n<c;n++) {
    int k;
    printf("Input element in row %i, column %i:\n",m+1,n+1);
    fflush(stdout);
    scanf("%i",&k);
    X[m][n]=k%p;
  }
  }

/*---Initial Output---*/

  for (m=0;m<r;m++) {
  for (n=0;n<c;n++) {
    if (abs(n-c+1)<tiny) {printf(" %i \n",X[m][n]);}
    else {printf(" %i ",X[m][n]);}   
  }
  }

  for (I=0;I<r;I++) {
  for (J=I;J<r;J++) {
    
double Ti[10],yoo[10];
int T[10],Tf[10],Tx[10],yo[10];

 for (i=0;i<r;i++) {
   T[i]=0;
   Ti[i]=0;
   Tx[10];
   yoo[i]=0;
   Tf[i]=0;
   yo[i]=0;}

  for (i=0;i<r;i++) {
    int Xsumi;
    Xsumi = 0; 
    for (j=0;j<c;j++) {if (X[i][j] <0.5) {Xsumi = Xsumi + 1;}
    else {j=c;}
    }
    T[i] = Xsumi;
    }

for (i=0;i<r;i++) {Ti[i]=T[i]+i*(0.01);}

for (i=0;i<r;i++) {
   int ord;
   ord=0; 
  for (j=0;j<r;j++) {
    if (Ti[j]-Ti[i]<tiny) {ord=ord+1;} }
   yo[i] = ord-1; }

 for (i=0;i<r;i++) {
   int y;
   y=0;
   y=yo[i];
   yoo[y]=Ti[i]; }

 for (i=0;i<r;i++) {
 for (j=0;j<r;j++) {
   double m;
   int n;
   m=0;
   n=0;
   m=yoo[i]-j;
   n=rint(100*m);
    if (abs(m)<1) {yo[i]=n;j=r;}
   }
   }

 for (i=0;i<r;i++) {
  int y;
  y=0;
  y=yo[i];
  Tf[y]=i;}

 for (i=0;i<r;i++) {
   int T;
 T=Tf[i];
 for (j=0;j<c;j++) {
   TX[T][j]=X[i][j];} } 

 for (i=0;i<r;i++) {
    int Xsumi;
    Xsumi = 0; 
    for (j=0;j<c;j++) {if (TX[i][j] <0.5) {Xsumi = Xsumi + 1;}
    else {j=c;} }
    Tx[i] = Xsumi;
    }

  for (i=J;i<r;i++) {
    int l,in,li;
    l=0;
    in=0;
    li=0;
    in=Tx[i];
    l=TX[i][in];
    li=x[l-1];
    if (in-c<tiny) {for (j=0;j<c;j++) {TX[i][j]=li*TX[i][j]%p;}
    }
    }

if (Tx[J]!=c)
  {for (i=J+1;i<r;i++) { 
    if (abs(Tx[i]-Tx[J])<tiny) {
      for (j=0;j<c;j++) {
	TX[i][j]=(TX[i][j]-TX[J][j]+p)%p;
   }
   }
   }
   }

   for (i=0;i<r;i++) {
   for (j=0;j<c;j++) {
     X[i][j]=TX[i][j];
   }
   }

   }
   }

/*---Final Output---*/

 printf("\nEchelon form of given Matrix\n over the Field Z modulo %i\n",p);
  for (m=0;m<r;m++) {
  for (n=0;n<c;n++) {
    if (abs(n-c+1)<tiny) {printf(" %i \n",X[m][n]);}
    else {printf(" %i ",X[m][n]);}   
  }
  }
 
return 0;}
