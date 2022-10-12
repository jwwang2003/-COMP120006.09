#include<stdio.h>
#include<stdlib.h>

const int GRIDSIZE = 10;

void createMap(int **array) {
  array = malloc(GRIDSIZE * sizeof(*array));
  for (int i = 0; i < GRIDSIZE; ++i) array[i] = malloc(GRIDSIZE * sizeof(*array[i]));


}

int main(void) {
  int **map;

  createMap(map);
}