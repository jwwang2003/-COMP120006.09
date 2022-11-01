//
//  map.h
//  P1
//
//  Created by Jun Wei Wang on 2022-10-16.
//

#ifndef map_h
#define map_h
#include <stdlib.h>
#include <string.h>

typedef struct {
    int **grid;     // grid representing the map; 0 = empty, 1 = JARed
    int height;          // height of grid (y axis)
    int width;          // width of grid (x axis)
} Map;

int randomInt(int a, int b);
int shouldJar(void);
void createMap(Map *map, int height, int width);
int getNode(Map *map, int y, int x);
int boundCheck(Map *map, int playerY, int playerX);

#endif /* map_h */
