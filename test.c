#include<stdio.h>

int main(void) {
  int a = 5, b, c;
  printf("%d", (b = a + 2) - (a = 1));
}