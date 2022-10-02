#include<stdio.h>
#include <stdbool.h>

void printGrid(int x, int y, int dX, int dY, bool grid[][10]) {
  for(int r = 0; r < 10; ++r) {
    for(int c = 0; c < 10; ++c) {
      printf("｜");
      if(r == y && c == x) printf("start");
      else if(r == (y + dY) && c == (x + dX)) /* printf("end"); */ printf(" end");
      else if(grid[r][c]) /* printf("o"); */ printf("  o");

      printf("\t");
    }
    printf("｜\n");
  }
}

int main(void) {
  int x, y;
  scanf("(%d, %d)", &x, &y);
  
  int dX = 6, dY = 3;

  bool grid[10][10] = { 0 };
  
  for(int i = y; i < y + dY; ++i) {
    grid[i][x] = 1;
  }

  for(int i = x; i < x + dX; ++i) {
    grid[y + dY][i] = 1;
  }

  printf("Now you’re at (%d, %d)\n", x + dX, y + dY);
  printGrid(x, y, dX, dY, grid);

  return 0;
}