//
//  window.h
//  P1
//
//  Created by Jun Wei Wang on 2022-10-01.
//

// REFACTORED!

#ifndef window_h
#define window_h

#include <stdio.h>

#include "constants.h"
#include "map.h"
#include "player.h"
#include "game.h"

void initWindow(void);
void splashScreenMsg(int num, const char c[][STRLEN]);
void updateWindow(Game *game, Map *map, Player *player);
void showGameOver(int len, const char c[STRLEN]);

#endif /* window_h */
