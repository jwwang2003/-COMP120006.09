//
//  map.c
//  P1
//
//  Created by Jun Wei Wang on 2022-10-01.
//

// REFACTORED!

#include "map.h"

// decides whether we jar the node or not
// generate any whole number between 0 and 1
// achieving a 50/50 chance of either
int shouldJar(void) {
    return randomInt(0, 1);
}

// create a map with specified height and width
Map *createMap(void) {
    Map *map = (Map*)malloc(sizeof(Map));
//  initializing the grid
    map->numJars = 0;
    map->grid = malloc(MAP_H * sizeof(*map->grid));
    
    for (int i = 0; i < MAP_H; ++i) {
        map->grid[i] = malloc(MAP_W * sizeof(*map->grid[i]));
        
        for(int j = 0; j < MAP_W; ++j) {
            if (i == 0 || i == MAP_H - 1)
                map->grid[i][j] = 2;
            else if (j == 0 || j == MAP_W - 1)
                map->grid[i][j] = 2;
            else {
                // since shouldJar returns 0 or 1, empty or jared respectively,
                // just directly assign the return value to said node
                if(shouldJar() == 1) {
                    map->grid[i][j] = 1;
                    map->numJars++;
                }
            }
        }
    }
    
    return map;
}

int getNode(Map *map, int y, int x) {
    return map->grid[y][x];
}

int boundCheck(int playerY, int playerX) {
    return (((MAP_H - 2) >= playerY && playerY >= 1) && (MAP_W - 2) >= playerX && playerX >= 1);
}
