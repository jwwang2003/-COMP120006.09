//
//  map.c
//  P1
//
//  Created by Jun Wei Wang on 2022-10-16.
//

#include "map.h"

/**
 实现一个randomInt(int x, int y)函数返回一个x~y之间的随机数，每个随机数的概率就近似为 1/(y-x)
 y always bigger than x
 */
int randomInt(int x, int y) {
    if (x > y) return -1;
    return rand() % (y + 1 - x) + x;
}

// decides whether we jar the node or not
// generate any whole number between 0 and 1
// achieving a 50/50 chance of either
int shouldJar(void) {
    return randomInt(0, 1) != 0;
}

// create a map with specified height and width
// return the map
void createMap(Map *map, int height, int width) {
    
//  initializing the grid
    map->grid = malloc(height * sizeof(*map->grid));
    
    for (int i = 0; i < height; ++i) {
        map->grid[i] = malloc(width * sizeof(*map->grid[i]));
        
        for(int j = 0; j < height; ++j) {
            if (i == 0 || i == height - 1)
                map->grid[i][j] = 2;
            else if (j == 0 || j == width - 1)
                map->grid[i][j] = 2;
            else
                // since shouldJar returns 0 or 1, empty or jared respectively,
                // just directly assign the return value to said node
                map->grid[i][j] = shouldJar();
        }
    }
    
    map->height = height;
    map->width = width;
}

int getNode(Map *map, int y, int x) {
    return map->grid[y][x];
}

int boundCheck(Map *map, int playerY, int playerX) {
    return ((map->height - 2) >= playerY && playerY >= 1) && ((map->width - 2) >= playerX && playerX >= 1);
}
