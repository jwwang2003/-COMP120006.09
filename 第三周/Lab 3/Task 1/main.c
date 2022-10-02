#include<stdio.h>
#include<math.h>

double sigmoid(double x) {
  double result;
  result = 1 / (1 + exp(-x));
  return result;
}

struct Cell1 {
  int a, b, c;
  float k1, k2, k3;
  float x;
  float y;
};
typedef struct Cell1 Cell1;

struct Cell2 {
  float z, m;
};
typedef struct Cell2 Cell2;

int main(void) {
  Cell1 cell1;

  scanf("%d,%d,%d", &cell1.a, &cell1.b, &cell1.c);
  scanf("%f,%f,%f", &cell1.k1, &cell1.k2, &cell1.k3);
  float k;
  scanf("%f", &k);

  cell1.x = cell1.a*cell1.k1 + cell1.b*cell1.k2 + cell1.c*cell1.k3;
  cell1.y = sigmoid(cell1.x);

  Cell2 cell2;
  cell2.z = cell1.y*k;
  cell2.m = sigmoid(cell2.z);

  printf("a:%d;k1:%.1f-->\n", cell1.a, cell1.k1);
  printf("b:%d;k2:%.1lf—->x:%.3lf; y:%.3f; ky:%.3f-->z:%.3f;m:%.3f\n", cell1.b, cell1.k2, cell1.x, cell1.y, k, cell2.z, cell2.m);
  printf("c:%d;k3:%.1f—>\n", cell1.c, cell1.k3);

  return 0;
}