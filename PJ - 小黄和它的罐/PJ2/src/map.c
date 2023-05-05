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
    map->grid = malloc(MAP_H * sizeof(int*));
    
    for (int i = 0; i < MAP_H; ++i) {
        map->grid[i] = malloc(MAP_W * sizeof(int));
        for(int j = 0; j < MAP_W; ++j) {
            map->grid[i][j] = 0;
        }
        
        for(int j = 0; j < MAP_W; ++j) {
            if (i == 0 || i == MAP_H - 1)
                map->grid[i][j] = 2;
            else if (j == 0 || j == MAP_W - 1)
                map->grid[i][j] = 2;
//            else {
//                // since shouldJar returns 0 or 1, empty or jared respectively,
//                // just directly assign the return value to said node
//                if(shouldJar() == 1) {
//                    map->grid[i][j] = 1;
//                    map->numJars++;
//                }
//            }
        }
    }
    
    int **av = (int**)malloc(100 * sizeof(int*));
    int i = 0;
    for(int y = 1; y < 12 - 1; ++y) {
        for(int x = 1; x < 12 - 1; ++x) {
            av[i] = (int*)malloc(2 * sizeof(int));
            av[i][0] = y;
            av[i][1] = x;
            i++;
        }
    }

    for(i = 0; i < 50; ++i) {
        int get = randomInt(0, 100 - i - 1);
        int *temp = av[get];
        av[get] = av[100 - i - 1];
        av[100 - i - 1] = temp;
    }
    
//    for(i = 0; i < 100; ++i) {
//        printf("%d %d\n", av[i][0], av[i][1]);
//    }
//    printf("\n");
//
    for(i = 0; i < 50; ++i) {
        map->grid[av[i][0]][av[i][1]] = 1;
//        printf("%d %d\n", av[i][0], av[i][1]);
        map->numJars++;
    }
    
//    for(i = 0; i < 12; ++i) {
//        for(int j = 0; j < 12; ++j) {
//            printf("%d ", map->grid[i][j]);
//        }
//        printf("\n");
//    }
    
//     free up memory
    for(i = 0; i < 100; ++i) {
        free(av[i]);
    }
    free(av);
    
    return map;
}

void freeMap(Map *map) {
    for (int i = 0; i < MAP_H; ++i) {
        free(map->grid[i]);
    }
    free(map->grid);
    free(map);
    
    return;
}

int getNode(Map *map, int y, int x) {
    return map->grid[y][x];
}

int boundCheck(int playerY, int playerX) {
    return (((MAP_H - 2) >= playerY && playerY >= 1) && (MAP_W - 2) >= playerX && playerX >= 1);
}

void getSurround(Map *map, int playerY, int playerX, int arr[]) {
    int up = playerY - 1;
    int down = playerY + 1;
    int left = playerX - 1;
    int right = playerX + 1;
    
    arr[0] = map->grid[up][playerX];
    arr[1] = map->grid[playerY][left];
    arr[2] = map->grid[playerY][playerX];
    arr[3] = map->grid[playerY][right];
    arr[4] = map->grid[down][playerX];
}
