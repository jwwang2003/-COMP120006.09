#include <stdio.h>

const int ROW = 10, COL = 10;

void printSeparator() {
  for(int i = 0; i < COL; ++i) printf("———");
  printf("—\n");
}

void printRow(int *arr) {
  printf("｜");
  for(int i = 0; i < COL; ++i) {
    if(arr[i] == 1) printf("@");
    else if (arr[i] == 2) printf("!");
    else printf(" ");
    printf("｜");
  }
  printf("\n");
}

int main(void) {
  int grid[ROW][COL] = {0};

  grid[0][0] = 2;

  grid[2][3] = 1;
  grid[3][3] = 1;

  grid[2][6] = 1;
  grid[3][6] = 1;

  grid[5][2] = 1;
  grid[6][3] = 1;
  grid[6][4] = 1;
  grid[6][5] = 1;
  grid[6][6] = 1;
  grid[5][7] = 1;

  for(int i = 0; i < ROW; ++i) {
    printSeparator();
    printRow(grid[i]);
  }

  printSeparator();
  
  return 0;
}