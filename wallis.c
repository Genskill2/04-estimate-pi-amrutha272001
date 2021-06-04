#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
float wallis_pi(int n)
 {
 float pi;
 float prod=1.00;
 for(int i=1;i<=n;i++){
  m=(4.0*i*i)/((4.0*i*i)-1);
  prod=prod*m;
  }
 prod=2*prod;
 return prod;
}
int main(void)
{
  float pi;
  for (int i=0; i<5; i++)
  {
    pi = wallis_pi(i);
    //printf("Wallis called %f %f\n",M_PI,pi);
    if (!(fabs(pi - M_PI) > 0.15))
    {
      //printf("Wallis g %f\n",pi);
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++)
  {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01))
    {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}

