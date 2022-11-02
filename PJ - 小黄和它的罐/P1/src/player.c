//
//  player.c
//  P1
//
//  Created by Jun Wei Wang on 2022-11-01.
//

// REFACTORED!

#include "player.h"

Player *initPlayer(void) {
    Player *p = (Player*)malloc(sizeof(Player));
    p->y = 1;
    p->x = 1;
    
    return p;
}

// return 0 if player exceeds wall bounds, aka hits a wall
int movePlayer(Map *m, Player *p, const int d[2]) {
    if(boundCheck(p->y + d[0], p->x + d[1])) {
        // new coordinates is within bounds
        p->y += d[0];
        p->x += d[1];
    } else return 0;
    
    return 1;
}

int movePlayerRandom(Map *m, Player *p) {
    int i = randomInt(2, 7);
    
    switch (i) {
        case 2:
            return movePlayerUp(m, p);
        case 3:
            return movePlayerDown(m, p);
        case 4:
            return movePlayerLeft(m, p);
        case 5:
            return movePlayerRight(m, p);
        case 6:
            return 1;
        case 7:
            return pickUpJar(m, p);
    }
    
    return 0;
}

int movePlayerUp(Map *m, Player *p) {
//    int d[2] = {-1, 0};
    return movePlayer(m, p, pDisplacement[0]);
}

int movePlayerDown(Map *m, Player *p) {
//    int d[2] = {1, 0};
    return movePlayer(m, p, pDisplacement[1]);
}

int movePlayerLeft(Map *m, Player *p) {
//    int d[2] = {0, -1};
    return movePlayer(m, p, pDisplacement[2]);
}

int movePlayerRight(Map *m, Player *p) {
//    int d[2] = {0, 1};
    return movePlayer(m, p, pDisplacement[3]);
}

// checks if the current node has jar before making a move
// if there is, remember to deduct points for not picking up
int hasJar(Map *m, int y, int x) {
    if(getNode(m, y, x) == 1) {
        return 1;
    }
    return 0;
}

int pickUpJar(Map *m, Player *p) {
    if(hasJar(m, p->y, p->x)) {
        m->grid[p->y][p->x] = 0;    // set current node as empty after picking up
    } else return 0;    // return 0 indicating there was no jar
    
    // return 1 to indicate jar successfully picked up
    return 1;
}
