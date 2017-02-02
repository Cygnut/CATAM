#include <catam.h>
#include <float.h>

double e;
int f;

int main(void) {

  e=log2(DBL_EPSILON);
  printf("Base 2 logarithm of test epsilon = %lf\n",e);

  e=2,f=0;
  while (1+e!=1) {e=e/2;f--;}

  printf("Machine epsilon is worked out to be 2 to the power %i\n",f+2);

 return 0;}
