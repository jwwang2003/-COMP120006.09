#include <stdio.h>
#include <math.h>

int main(void) {
  double a, b, c, Wa, Wb, Wc;

  scanf("%lf %lf %lf\n%lf %lf %lf", &a, &b, &c, &Wa, &Wb, &Wc);

  double x = a*Wa + b*Wb + c*Wc;

  double y = 1/(1 + exp(-x));

  printf("%.16lf", y);
  
  return 0;
}