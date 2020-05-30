#include <catam.h>

double tiny=5e-20;
int p,i,j,k,t,l,q,I,J,ra,rb,ca,cb,m,n;
int ranka,rankb,rankab,rankanb;
int x[100];
int Xa[10][10],Ya[10][10],Xda[10][10],TXa[10][10],Ka[10][10],KTa[10][10],La[10],Sa[10],Ta[10],Ua[10];
int Xb[10][10],Yb[10][10],Xdb[10][10],TXb[10][10],Kb[10][10],KTb[10][10],Lb[10],Sb[10],Tb[10],Ub[10];
int Sum[20][10],TSum[20][10],Sumo[20][10],TXs[20][10],Ks[20][10],Ls[20],Ss[20],Ts[20],Us[20];
int Sumod[20][10],Ys[20][10];
int Inv(int iv,int jv,int pv) {int m;
 m = iv*jv%pv;
 return m;}
int MainCL(void) {
  ranka=0;
  rankb=0;
  rankab=0;
  rankanb=0;

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
     printf("Input common number of columns of \nmatrices A and B:\n");
     fflush(stdout);
     scanf("%i",&ca);
     printf("Input number of rows of matrix A:\n");
     fflush(stdout);
     scanf("%i",&ra);
     printf("Input number of rows of matrix B:\n");
     fflush(stdout);
     scanf("%i",&rb);
     cb=ca;
     
     printf("Let the row space of A be U,of B be W,\nthe space of their intersection, UnW,\nand the space of their sum be U+W");
  
     printf("\n\nFor matrix A\n");
  for (m=0;m<ra;m++) {
  for (n=0;n<ca;n++) {
    int k;
    printf("Input element in row %i, column %i:\n",m+1,n+1);
    fflush(stdout);
    scanf("%i",&k);
    Xa[m][n]=k%p;
    Xda[m][n]=k&p;
    Ka[m][n]=0;
  }
  }

     printf("\n\nFor matrix B\n");
  for (m=0;m<rb;m++) {
  for (n=0;n<cb;n++) {
    int k;
    printf("Input element in row %i, column %i:\n",m+1,n+1);
    fflush(stdout);
    scanf("%i",&k);
    Xb[m][n]=k%p;
    Xdb[m][n]=k&p;
    Kb[m][n]=0;
  }
  }

  for (m=0;m<10;m++) {
    for (n=0;n<10;n++) {
      Sum[m][n]=Xa[m][n];
    }
  }

  for (m=10;m<20;m++) {
    for (n=0;n<10;n++) {
      Sum[m][n]=Xb[m-10][n];
    }
  }
  
/*---Initial Output---*/

  printf("\nMatrix A:\n\n");
  for (m=0;m<ra;m++) {
  for (n=0;n<ca;n++) {
    if (abs(n-ca+1)<tiny) {printf(" %i \n",Xa[m][n]);}
    else {printf(" %i ",Xa[m][n]);}   
  }
  }

  printf("\nMatrix B:\n\n");
  for (m=0;m<rb;m++) {
  for (n=0;n<cb;n++) {
    if (abs(n-cb+1)<tiny) {printf(" %i \n",Xb[m][n]);}
    else {printf(" %i ",Xb[m][n]);}   
  }
  }

  /*------------------------------------A--------------------------------------*/

/*---Echeloning A---*/

  for (I=0;I<ra;I++) {
  for (J=I;J<ra;J++) {
    
double Ti[10],yoo[10];
int T[10],Tf[10],Tx[10],yo[10];

 for (i=0;i<ra;i++) {
   T[i]=0;
   Ti[i]=0;
   Tx[10];
   yoo[i]=0;
   Tf[i]=0;
   yo[i]=0;}

  for (i=0;i<ra;i++) {
    int Xsumi;
    Xsumi = 0; 
    for (j=0;j<ca;j++) {if (Xa[i][j] <0.5) {Xsumi = Xsumi + 1;}
    else {j=ca;}
    }
    T[i] = Xsumi;
    }

for (i=0;i<ra;i++) {Ti[i]=T[i]+i*(0.01);}

for (i=0;i<ra;i++) {
   int ord;
   ord=0; 
  for (j=0;j<ra;j++) {
    if (Ti[j]-Ti[i]<tiny) {ord=ord+1;} }
   yo[i] = ord-1; }

 for (i=0;i<ra;i++) {
   int y;
   y=0;
   y=yo[i];
   yoo[y]=Ti[i]; }

 for (i=0;i<ra;i++) {
 for (j=0;j<ra;j++) {
   double m;
   int n;
   m=0;
   n=0;
   m=yoo[i]-j;
   n=rint(100*m);
    if (abs(m)<1) {yo[i]=n;j=ra;}
   }
   }

 for (i=0;i<ra;i++) {
  int y;
  y=0;
  y=yo[i];
  Tf[y]=i;}

 for (i=0;i<ra;i++) {
   int V;
 V=Tf[i];
 for (j=0;j<ca;j++) {
   TXa[V][j]=Xa[i][j];} } 

 for (i=0;i<ra;i++) {
    int Xsumi;
    Xsumi = 0; 
    for (j=0;j<ca;j++) {if (TXa[i][j] <0.5) {Xsumi = Xsumi + 1;}
    else {j=ca;} }
    Tx[i] = Xsumi;
    }

  for (i=J;i<ra;i++) {
    int l,in,li;
    l=0;
    in=0;
    li=0;
    in=Tx[i];
    l=TXa[i][in];
    li=x[l-1];
    if (in-ca<tiny) {for (j=0;j<ca;j++) {TXa[i][j]=li*TXa[i][j]%p;}
    }
    }

if (abs(Tx[J]-ca)>0.5)
  {for (i=J+1;i<ra;i++) { 
    if (abs(Tx[i]-Tx[J])<tiny) {
      for (j=0;j<ca;j++) {
    TXa[i][j]=(TXa[i][j]-TXa[J][j]+p)%p;
   }
   }
   }
   }

   for (i=0;i<ra;i++) {
   for (j=0;j<ca;j++) {
     Xa[i][j]=TXa[i][j];
   }
   }

   }
   }

  for (i=0;i<ra;i++) {
    for (j=0;j<ca;j++) {
      Xda[i][j]=Xa[i][j];
    }
  }

  /*---Basis output for U---*/

 for (i=0;i<ra;i++) {
    int Xsumi;
    Xsumi = 0; 
    for (j=0;j<ca;j++) {if (Xda[i][j] <0.5) {Xsumi = Xsumi + 1;}
    else {j=ca;}
    }
    Sa[i] = Xsumi;
    }

 printf("\nBasis vector/s for row space of A, U\n");

 for (i=0;i<ra;i++) { 
   if (abs(Sa[i]-ca)>tiny) {
   ranka = ranka + 1;
   for (j=0;j<ca;j++) {
   if (abs(j-ca+1)<tiny) {printf(" %i \n\n",Xda[i][j]);}    
   else {printf(" %i \n",Xda[i][j]);}
   }
 }
 }

 if (abs(ranka)<tiny) {printf("None - Trivial, U={0}.\n\n");}
 else printf("dimU=%i.\n\n",ranka);

/*---Basis Location for Uo---*/

 for (i=0;i<ra;i++) {
/*Removing current degeneracy*/
 for (m=1;m<ca+1;m++) {
   int s,g;
 for (k=0;k<ra;k++) {
    int Ysumi;
    Ysumi = 0; 
    for (j=0;j<ca;j++) {if (Xda[k][j] <0.5) {Ysumi = Ysumi + 1;}
    }
    Ua[k] = Ysumi;
    }
 for (j=0;j<ra;j++) {
   g=Sa[ra-1-j];
   if (abs(Ua[ra-1-j]-ca+1)<tiny) {for (k=0;k<ca;k++) 
             {Xda[ra-1-j][k]=0;
              Xda[k][g]=0;}
   La[g]=1;}
 }
 }
 for (j=i+1;j<ra;j++) {
    int a;
    a=Xda[i][Sa[j]];
    for (k=0;k<ca;k++) {
     int t;
         t=Sa[j];  
         Ya[j][k]=Xda[j][k]*a;
         Xda[i][k]=(Xda[i][k]-Ya[j][k]+p)%p;
         Ya[j][k]=0;
     }
     }
     }

 for (i=0;i<ra;i++) {
   if (abs(Sa[i]-ca)>tiny) {
  for (j=Sa[i]+1;j<ca;j++) {
    Ka[Sa[i]][j]=(p-Xda[i][j])%p;
   }
   }
   }

 for (i=0;i<11;i++) {
    int Xsumi;
    Xsumi = 0;
    Sa[i]=ca;
    for (j=0;j<ca;j++) {if (Ka[i][j] <0.5) {Xsumi = Xsumi + 1;}
    else {j=ca;}
    }
    Sa[i] = Xsumi;
    }

 for (i=0;i<ca;i++) {
   if (abs(La[i]-1)>tiny) {if (abs(Sa[i]-ca)<tiny) {Ka[i][i]=1;}}
   }

 for (i=0;i<10;i++) {
   for (j=0;j<ca;j++) {
     KTa[i][j]=Ka[j][i];
   }
 }

 for (i=0;i<10;i++) {
   for (j=0;j<ca;j++) {
     Sumo[i][j]=KTa[i][j];
   }
 }
 /*
for (m=0;m<10;m++) {
  for (n=0;n<10;n++) {
    if (abs(n-9)<tiny) {printf(" %i (%i)\n",Ka[m][n],KTa[m][n]);}
    else {printf(" %i (%i)",Ka[m][n],KTa[m][n]);}   
  }
  }
 */
 /*---------------------------------End A------------------------------------*/

 /*-----------------------------------B--------------------------------------*/

/*---Echeloning B---*/

  for (I=0;I<rb;I++) {
  for (J=I;J<rb;J++) {
    
double Ti[10],yoo[10];
int T[10],Tf[10],Tx[10],yo[10];

 for (i=0;i<rb;i++) {
   T[i]=0;
   Ti[i]=0;
   Tx[10];
   yoo[i]=0;
   Tf[i]=0;
   yo[i]=0;}

  for (i=0;i<rb;i++) {
    int Xsumi;
    Xsumi = 0; 
    for (j=0;j<cb;j++) {if (Xb[i][j] <0.5) {Xsumi = Xsumi + 1;}
    else {j=cb;}
    }
    T[i] = Xsumi;
    }

for (i=0;i<rb;i++) {Ti[i]=T[i]+i*(0.01);}

for (i=0;i<rb;i++) {
   int ord;
   ord=0; 
  for (j=0;j<rb;j++) {
    if (Ti[j]-Ti[i]<tiny) {ord=ord+1;} }
   yo[i] = ord-1; }

 for (i=0;i<rb;i++) {
   int y;
   y=0;
   y=yo[i];
   yoo[y]=Ti[i]; }

 for (i=0;i<rb;i++) {
 for (j=0;j<rb;j++) {
   double m;
   int n;
   m=0;
   n=0;
   m=yoo[i]-j;
   n=rint(100*m);
    if (abs(m)<1) {yo[i]=n;j=rb;}
   }
   }

 for (i=0;i<rb;i++) {
  int y;
  y=0;
  y=yo[i];
  Tf[y]=i;}

 for (i=0;i<rb;i++) {
   int V;
 V=Tf[i];
 for (j=0;j<cb;j++) {
   TXb[V][j]=Xb[i][j];} } 

 for (i=0;i<rb;i++) {
    int Xsumi;
    Xsumi = 0; 
    for (j=0;j<cb;j++) {if (TXb[i][j] <0.5) {Xsumi = Xsumi + 1;}
    else {j=cb;} }
    Tx[i] = Xsumi;
    }

  for (i=J;i<rb;i++) {
    int l,in,li;
    l=0;
    in=0;
    li=0;
    in=Tx[i];
    l=TXb[i][in];
    li=x[l-1];
    if (in-cb<tiny) {for (j=0;j<cb;j++) {TXb[i][j]=li*TXb[i][j]%p;}
    }
    }

if (abs(Tx[J]-cb)>0.5)
  {for (i=J+1;i<rb;i++) { 
    if (abs(Tx[i]-Tx[J])<tiny) {
      for (j=0;j<cb;j++) {
    TXb[i][j]=(TXb[i][j]-TXb[J][j]+p)%p;
   }
   }
   }
   }

   for (i=0;i<rb;i++) {
   for (j=0;j<cb;j++) {
     Xb[i][j]=TXb[i][j];
   }
   }

   }
   }

  for (i=0;i<rb;i++) {
    for (j=0;j<cb;j++) {
      Xdb[i][j]=Xb[i][j];
    }
  }

  /*---Basis output for W---*/

 for (i=0;i<rb;i++) {
    int Xsumi;
    Xsumi = 0; 
    for (j=0;j<cb;j++) {if (Xdb[i][j] <0.5) {Xsumi = Xsumi + 1;}
    else {j=cb;}
    }
    Sb[i] = Xsumi;
    }

 printf("\nBasis vector/s for row space of B, W\n");

 for (i=0;i<rb;i++) { 
   if (abs(Sb[i]-cb)>tiny) {
   rankb = rankb + 1;
   for (j=0;j<cb;j++) {
   if (abs(j-cb+1)<tiny) {printf(" %i \n\n",Xdb[i][j]);}    
   else {printf(" %i \n",Xdb[i][j]);}
   }
 }
 }

 if (abs(rankb)<tiny) {printf("None - Trivial, W={0}.\n\n");}
 else printf("dimW=%i.\n\n",rankb);

/*---Basis Location for Wo---*/

 for (i=0;i<rb;i++) {
/*Removing current degeneracy*/
 for (m=1;m<cb+1;m++) {
   int s,g;
 for (k=0;k<rb;k++) {
    int Ysumi;
    Ysumi = 0; 
    for (j=0;j<cb;j++) {if (Xdb[k][j] <0.5) {Ysumi = Ysumi + 1;}
    }
    Ub[k] = Ysumi;
    }
 for (j=0;j<rb;j++) {
   g=Sb[rb-1-j];
   if (abs(Ub[rb-1-j]-cb+1)<tiny) {for (k=0;k<cb;k++) 
             {Xdb[rb-1-j][k]=0;
              Xdb[k][g]=0;}
   Lb[g]=1;}
 }
 }
 for (j=i+1;j<rb;j++) {
    int a;
    a=Xdb[i][Sb[j]];
    for (k=0;k<cb;k++) {
     int t;
         t=Sb[j];  
         Yb[j][k]=Xdb[j][k]*a;
         Xdb[i][k]=(Xdb[i][k]-Yb[j][k]+p)%p;
         Yb[j][k]=0;
     }
     }
     }

 for (i=0;i<rb;i++) {
   if (abs(Sb[i]-cb)>tiny) {
  for (j=Sb[i]+1;j<cb;j++) {
    Kb[Sb[i]][j]=(p-Xdb[i][j])%p;
   }
   }
   }

 for (i=0;i<11;i++) {
    int Xsumi;
    Xsumi = 0;
    Sb[i]=cb;
    for (j=0;j<cb;j++) {if (Kb[i][j] <0.5) {Xsumi = Xsumi + 1;}
    else {j=cb;}
    }
    Sb[i] = Xsumi;
    }

 for (i=0;i<cb;i++) {
   if (abs(Lb[i]-1)>tiny) {if (abs(Sb[i]-cb)<tiny) {Kb[i][i]=1;}}
   }


 for (i=0;i<10;i++) {
   for (j=0;j<cb;j++) {
     KTb[i][j]=Kb[j][i];
   }
 }

 /*
for (m=0;m<10;m++) {
  for (n=0;n<10;n++) {
    if (abs(n-9)<tiny) {printf(" %i (%i)\n",Kb[m][n],KTb[m][n]);}
    else {printf(" %i (%i)",Kb[m][n],KTb[m][n]);}   
  }
  }
 */

 for (i=10;i<20;i++) {
   for (j=0;j<cb;j++) {
     Sumo[i][j]=KTb[i-10][j];
   }
 }

/*---------------------------------A+B---------------------------------------*/

/*---Echeloning A+B---*/

  for (I=0;I<20;I++) {
  for (J=I;J<20;J++) {
    
double Ti[20],yoo[20];
int T[20],Tf[20],Tx[20],yo[20];

 for (i=0;i<20;i++) {
   T[i]=0;
   Ti[i]=0;
   Tx[10];
   yoo[i]=0;
   Tf[i]=0;
   yo[i]=0;}

  for (i=0;i<20;i++) {
    int Xsumi;
    Xsumi = 0; 
    for (j=0;j<ca;j++) {if (Sum[i][j] <0.5) {Xsumi = Xsumi + 1;}
    else {j=ca;}
    }
    T[i] = Xsumi;
    }

for (i=0;i<20;i++) {Ti[i]=T[i]+i*(0.01);}

for (i=0;i<20;i++) {
   int ord;
   ord=0; 
  for (j=0;j<20;j++) {
    if (Ti[j]-Ti[i]<tiny) {ord=ord+1;} }
   yo[i] = ord-1; }

 for (i=0;i<20;i++) {
   int y;
   y=0;
   y=yo[i];
   yoo[y]=Ti[i]; }

 for (i=0;i<20;i++) {
 for (j=0;j<20;j++) {
   double m;
   int n;
   m=0;
   n=0;
   m=yoo[i]-j;
   n=rint(100*m);
    if (abs(m)<1) {yo[i]=n;j=20;}
   }
   }

 for (i=0;i<20;i++) {
  int y;
  y=0;
  y=yo[i];
  Tf[y]=i;}

 for (i=0;i<20;i++) {
   int V;
 V=Tf[i];
 for (j=0;j<ca;j++) {
   TSum[V][j]=Sum[i][j];} } 

 for (i=0;i<20;i++) {
    int Xsumi;
    Xsumi = 0; 
    for (j=0;j<ca;j++) {if (TSum[i][j] <0.5) {Xsumi = Xsumi + 1;}
    else {j=ca;} }
    Tx[i] = Xsumi;
    }

  for (i=J;i<20;i++) {
    int l,in,li;
    l=0;
    in=0;
    li=0;
    in=Tx[i];
    l=TSum[i][in];
    li=x[l-1];
    if (in-ca<tiny) {for (j=0;j<ca;j++) {TSum[i][j]=li*TSum[i][j]%p;}
    }
    }

 if (abs(Tx[J]-ca)>0.5)
  {for (i=J+1;i<20;i++) { 
    if (abs(Tx[i]-Tx[J])<tiny) {
      for (j=0;j<ca;j++) {
    TSum[i][j]=(TSum[i][j]-TSum[J][j]+p)%p;
   }
   }
   }
   }

   for (i=0;i<20;i++) {
   for (j=0;j<ca;j++) {
     Sum[i][j]=TSum[i][j];
   }
   }

   }
   }


  /*---Basis output for U+W---*/

 for (i=0;i<20;i++) {
    int Xsumi;
    Xsumi = 0; 
    for (j=0;j<10;j++) {if (Sum[i][j] >0.5) {Xsumi = Xsumi + 1;}
    }
    Sa[i] = Xsumi;
    }

 printf("\nBasis vector/s for the space U+W\n\n");

 for (i=0;i<20;i++) { 
   if (abs(Sa[i])>0.5) {
   rankab = rankab + 1;
   for (j=0;j<ca;j++) {
   if (abs(j-ca+1)<tiny) {printf(" %i \n\n",Sum[i][j]);}    
   else {printf(" %i \n",Sum[i][j]);}
   }
 }
 }

 if (abs(rankab)<tiny) {printf("None - Trivial, U+W={0}.\n\n");}
 else printf("dimU+W=%i.\n\n",rankab);

 /*-----------------------------Basis for UnW---------------------------------*/

  for (I=0;I<20;I++) {
  for (J=I;J<20;J++) {
    
double Ti[20],yoo[20];
int T[20],Tf[20],Tx[20],yo[20];

 for (i=0;i<20;i++) {
   T[i]=0;
   Ti[i]=0;
   Tx[10];
   yoo[i]=0;
   Tf[i]=0;
   yo[i]=0;}

  for (i=0;i<20;i++) {
    int Xsumi;
    Xsumi = 0; 
    for (j=0;j<ca;j++) {if (Sumo[i][j] <0.5) {Xsumi = Xsumi + 1;}
    else {j=ca;}
    }
    T[i] = Xsumi;
    }

for (i=0;i<20;i++) {Ti[i]=T[i]+i*(0.01);}

for (i=0;i<20;i++) {
   int ord;
   ord=0; 
  for (j=0;j<20;j++) {
    if (Ti[j]-Ti[i]<tiny) {ord=ord+1;} }
   yo[i] = ord-1; }

 for (i=0;i<20;i++) {
   int y;
   y=0;
   y=yo[i];
   yoo[y]=Ti[i]; }

 for (i=0;i<20;i++) {
 for (j=0;j<20;j++) {
   double m;
   int n;
   m=0;
   n=0;
   m=yoo[i]-j;
   n=rint(100*m);
    if (abs(m)<1) {yo[i]=n;j=20;}
   }
   }

 for (i=0;i<20;i++) {
  int y;
  y=0;
  y=yo[i];
  Tf[y]=i;}

 for (i=0;i<20;i++) {
   int V;
 V=Tf[i];
 for (j=0;j<ca;j++) {
   TXs[V][j]=Sumo[i][j];} } 

 for (i=0;i<20;i++) {
    int Xsumi;
    Xsumi = 0; 
    for (j=0;j<ca;j++) {if (TXs[i][j] <0.5) {Xsumi = Xsumi + 1;}
    else {j=ca;} }
    Tx[i] = Xsumi;
    }

  for (i=J;i<20;i++) {
    int l,in,li;
    l=0;
    in=0;
    li=0;
    in=Tx[i];
    l=TXs[i][in];
    li=x[l-1];
    if (in-ca<tiny) {for (j=0;j<ca;j++) {TXs[i][j]=li*TXs[i][j]%p;}
    }
    }

if (abs(Tx[J]-ca)>0.5)
  {for (i=J+1;i<20;i++) { 
    if (abs(Tx[i]-Tx[J])<tiny) {
      for (j=0;j<ca;j++) {
    TXs[i][j]=(TXs[i][j]-TXs[J][j]+p)%p;
   }
   }
   }
   }

   for (i=0;i<20;i++) {
   for (j=0;j<ca;j++) {
     Sumo[i][j]=TXs[i][j];
   }
   }

   }
   }

  for (i=0;i<20;i++) {
    for (j=0;j<ca;j++) {
      Sumod[i][j]=Sumo[i][j];
    }
  }

/*---Basis Location---*/

 for (i=0;i<20;i++) {
    int Xsumi;
    Xsumi = 0; 
    for (j=0;j<ca;j++) {if (Sumo[i][j] <0.5) {Xsumi = Xsumi + 1;}
    else {j=ca;}
    }
    Ss[i] = Xsumi;
    }

 for (i=0;i<20;i++) {
/*Removing current degeneracy*/
 for (m=1;m<ca+1;m++) {
   int s,g;
 for (k=0;k<20;k++) {
    int Ysumi;
    Ysumi = 0; 
    for (j=0;j<ca;j++) {if (Sumod[k][j] <0.5) {Ysumi = Ysumi + 1;}
    }
    Us[k] = Ysumi;
    }
 for (j=0;j<20;j++) {
   g=Ss[19-j];
   if (abs(Us[19-j]-ca+1)<tiny) {for (k=0;k<ca;k++) 
             {Sumod[19-j][k]=0;
              Sumod[k][g]=0;}
   Ls[g]=1;}
 }
 }
 for (j=i+1;j<20;j++) {
    int a;
    a=Sumod[i][Ss[j]];
    for (k=0;k<ca;k++) {
     int t;
         t=Ss[j];
         Ys[j][k]=Sumod[j][k]*a;
         Sumod[i][k]=(Sumod[i][k]-Ys[j][k]+p)%p;
         Ys[j][k]=0;
     }
     }
     }

 for (i=0;i<20;i++) {
   if (abs(Ss[i]-ca)>tiny) {
  for (j=Ss[i]+1;j<ca;j++) {
    Ks[Ss[i]][j]=(p-Sumod[i][j])%p;
   }
   }
   }

 for (i=0;i<21;i++) {
    int Xsumi;
    Xsumi = 0;
    Ss[i]=ca;
    for (j=0;j<ca;j++) {if (Ks[i][j] <0.5) {Xsumi = Xsumi + 1;}
    else {j=ca;}
    }
    Ss[i] = Xsumi;
    }

 for (i=0;i<ca;i++) {
   if (abs(Ls[i]-1)>tiny) {if (abs(Ss[i]-ca)<tiny) {Ks[i][i]=1;}}
   }

 for (i=0;i<ca;i++) {
    int Xsumi;
    Xsumi = 0;
    for (j=0;j<ca;j++) {if (Ks[j][i] <0.5) {Xsumi = Xsumi + 1;}
    else {j=ca;}
    }
    Ss[i] = Xsumi;
    }

/*Basis Output*/

 printf("\nBasis vector/s for the space UnW\n\n");

 for (i=0;i<ca;i++) { 
   if (abs(Ss[i]-ca)>tiny) {
   rankanb = rankanb + 1;
   for (j=0;j<ca;j++) {
   if (abs(j-ca+1)<tiny) {printf(" %i \n\n",Ks[j][i]);}    
   else {printf(" %i \n",Ks[j][i]);}
   }
 }
 }

 if (abs(rankanb)<tiny) {printf("None - Trivial, UnW={0}.\n\n");}
 else printf("dimUnW=%i.",rankanb);

 return 0;}

