#include<stdio.h>

  int m(int list[4]) {
    int v = list[0];
    for (int i = 1; i < 4; i++)
      if (v < list[i])
        v = list[i];
    return v;
  }
  int main() {
    int values[2][4] = {{3, 4, 5, 1}, {33, 6, 1, 2}};

    for (int row = 0; row < 2; row++) {
      printf("%d ",m(values[row]));
    }
  }
