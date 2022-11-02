//
//  main.c
//  P1
//
//  Created by Jun Wei Wang on 2022-10-01.
//

// REFACTORED!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <ncurses.h> // special sause

#include "constants.h"
#include "helper.h"
#include "map.h"
#include "player.h"
#include "game.h"
#include "window.h"

int main(void) {
    srand((uint) time(NULL));
    
    initWindow();
        
    int t = sizeof(WELCOME_MSGS)/sizeof(WELCOME_MSGS[0]);
    splashScreenMsg(t, WELCOME_MSGS);
    getchar();
    
    t = sizeof(INSTRUCTION_MSGS)/sizeof(INSTRUCTION_MSGS[0]);
    splashScreenMsg(t, INSTRUCTION_MSGS);
    while (getchar() != 'a') { continue; };
    
    Map *map = createMap();
    Player *player = initPlayer();
    Game *game = initGame();
    
    do {
        updateWindow(game, map, player);
    } while(run(game, map, player) != -1);
    
    strcpy(game->hint1, "Final score ->");
    strcpy(game->hint2, "");
    
    updateWindow(game, map, player);
    t = (int)strlen(GAMEOVER_MSG);
    showGameOver(t, GAMEOVER_MSG);
    
    // cleanup
    free(map);
    free(player);
    free(game);
    
    return 0;
}
