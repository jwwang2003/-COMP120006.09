//
//  map.h
//  P1
//
//  Created by Jun Wei Wang on 2022-11-01.
//

// REFACTORED!

#ifndef map_h
#define map_h
#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "helper.h"

typedef struct {
    int **grid;     // grid representing the map; 0 = empty, 1 = JARed
    int numJars;
//    int height;          // height of grid (y axis)
//    int width;          // width of grid (x axis)
} Map;

int randomInt(int a, int b);
int shouldJar(void);
Map *createMap(void);
int getNode(Map *map, int y, int x);
int boundCheck(int playerY, int playerX);

#endif /* map_h */

