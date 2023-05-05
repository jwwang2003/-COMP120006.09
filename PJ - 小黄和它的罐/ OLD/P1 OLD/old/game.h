//
//  game.h
//  P1
//
//  Created by Jun Wei Wang on 2022-10-22.
//

#ifndef game_h
#define game_h

#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <ctype.h>

#include "player.h"
#include "map.h"
#include "command.h"

typedef struct {
    int score;
    int moves;
    char hint1[50];
    char hint2[50];
} Game;

void initGame(Game *game);

int run(Game *game, Map *map, Player *player);

//void showWelcome(int h, int w);
#endif /* game_h */
