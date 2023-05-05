#include<stdio.h>
#include<math.h>

int main(void) {
  double x, y;

  printf("Enter a point with two coordinates: ");
  scanf("%lf %lf", &x, &y);
  
  printf("Point (%.1lf, %.1lf) ", x, y);

  if(fabs(x) > 10/2.0 || fabs(y) > 5/2.0) printf("is not in the rectangle\n");
  // intersecting also means is inside the rectangle
  else printf("is in the rectangle\n");

  return 0;
}