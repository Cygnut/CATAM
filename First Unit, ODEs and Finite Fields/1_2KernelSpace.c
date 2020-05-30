#include <catam.h>

double tiny=5e-20;
int p,i,j,k,t,l,q,I,J,r,c,m,n,ker;
int x[100],X[10][10],Y[10][10],Xd[10][10],TX[10][10],K[10][10],L[10],S[10],T[10],U[10];
int Inv(int iv,int jv,int pv) {int m;
 m = iv*jv%pv; 
 return m;}
int MainCL(void) {
  ker=0;  
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
    Xd[m][n]=k&p;
    K[m][n]=0;
  }
  }

/*---Initial Output---*/

  for (m=0;m<r;m++) {
  for (n=0;n<c;n++) {
    if (abs(n-c+1)<tiny) {printf(" %i \n",X[m][n]);}
    else {printf(" %i ",X[m][n]);}   
  }
  }

/*---Echeloning---*/

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
   int V;
 V=Tf[i];
 for (j=0;j<c;j++) {
   TX[V][j]=X[i][j];} } 

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

if (abs(Tx[J]-c)>0.5)
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

  for (i=0;i<r;i++) {
    for (j=0;j<c;j++) {
      Xd[i][j]=X[i][j];
    }
  }

/*---Basis Location---*/

 for (i=0;i<r;i++) {
    int Xsumi;
    Xsumi = 0; 
    for (j=0;j<c;j++) {if (X[i][j] <0.5) {Xsumi = Xsumi + 1;}
    else {j=c;}
    }
    S[i] = Xsumi;
    }

 for (i=0;i<r;i++) {
/*Removing current degeneracy*/
 for (m=1;m<c+1;m++) {
   int s,g;
 for (k=0;k<r;k++) {
    int Ysumi;
    Ysumi = 0; 
    for (j=0;j<c;j++) {if (Xd[k][j] <0.5) {Ysumi = Ysumi + 1;}
    }
    U[k] = Ysumi;
    }
 for (j=0;j<r;j++) {
   g=S[r-1-j];
   if (abs(U[r-1-j]-c+1)<tiny) {for (k=0;k<c;k++) 
             {Xd[r-1-j][k]=0;
              Xd[k][g]=0;}
   L[g]=1;}
 }
 }
 for (j=i+1;j<r;j++) {
    int a;
    a=Xd[i][S[j]];
    for (k=0;k<c;k++) {
     int t;
         t=S[j];
         Y[j][k]=Xd[j][k]*a;
         Xd[i][k]=(Xd[i][k]-Y[j][k]+p)%p;
         Y[j][k]=0;
     }
     }
     }

 for (i=0;i<r;i++) {
   if (abs(S[i]-c)>tiny) {
  for (j=S[i]+1;j<c;j++) {
    K[S[i]][j]=(p-Xd[i][j])%p;
   }
   }
   }

 for (i=0;i<11;i++) {
    int Xsumi;
    Xsumi = 0;
    S[i]=c;
    for (j=0;j<c;j++) {if (K[i][j] <0.5) {Xsumi = Xsumi + 1;}
    else {j=c;}
    }
    S[i] = Xsumi;
    }

 for (i=0;i<c;i++) {
   if (abs(L[i]-1)>tiny) {if (abs(S[i]-c)<tiny) {K[i][i]=1;}}
   }

 for (i=0;i<c;i++) {
    int Xsumi;
    Xsumi = 0; 
    for (j=0;j<c;j++) {if (K[j][i] <0.5) {Xsumi = Xsumi + 1;}
    else {j=c;}
    }
    S[i] = Xsumi;
    }

/*Basis Output*/

 printf("\nBasis vector/s\n");

 for (i=0;i<c;i++) { 
   if (abs(S[i]-c)>tiny) {
   ker = ker + 1;
   for (j=0;j<c;j++) {
   if (abs(j-c+1)<tiny) {printf(" %i \n\n",K[j][i]);}    
   else {printf(" %i \n",K[j][i]);}
   }
 }
 }

 if (abs(ker)<tiny) {printf("None - Kernel is trivial.\nMatrix Nullity is hence nil.");}
 else printf("Matrix nullity is %i.",ker);
 
 return 0;}
