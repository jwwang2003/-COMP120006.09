#include<stdio.h>
#include<stdint.h>
#include<math.h>

int main(void) {
  int n;
  int v[10001], t[10001];

  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d %d", &v[i], &t[i]);
  }

  int temp[10001];
  // for(int i = 0; i < n; ++i) {
  //   printf("%f\n", (4.5/v[i])*3600.0 + t[i]);
  // }

  double min = INT32_MAX;

  for(int i = 0; i < n; ++i) {
    if(t[i] < 0) continue;
    // printf("%f\n", (4.5/v[i])*3600.0 + t[i]);
    double timeToFinish = ((4.5/v[i])*3600.0 + t[i]);
    min = min > timeToFinish ? timeToFinish : min;
  }

  printf("%d\n", (int)ceil(min));
}