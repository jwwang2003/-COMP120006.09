//
//  window.h
//  P1
//
//  Created by Jun Wei Wang on 2022-10-21.
//

#ifndef window_h
#define window_h

#include <stdio.h>
#include "map.h"
#include "player.h"
#include "game.h"

void initWindow(void);
void splashScreenMsg(int h, int w, int num, char c[][30]);
void updateWindow(Game *game, Map *map, Player *player);
void showGameOver(int h, int w, int len, char *c);

#endif /* window_h */
