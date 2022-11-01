//
//  main.c
//  P1
//
//  Created by Jun Wei Wang on 2022-11-01.
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
        
    int t = sizeof(WELCOME_MSG)/sizeof(WELCOME_MSG[0]);
    splashScreenMsg(t, WELCOME_MSG);
    getchar();
    
    t = sizeof(INSTRUCTION_MSGS)/sizeof(INSTRUCTION_MSGS[0]);
    splashScreenMsg(t, INSTRUCTION_MSGS);
    while (getchar() != 'a') { continue; };
    
    Map map;
    createMap(&map);
    Player player;
    initPlayer(&player);
    Game game;
    initGame(&game);
    
    do {
        updateWindow(&game, &map, &player);
    } while(run(&game, &map, &player) != -1);
    
    strcpy(game.hint1, "Final score ->");
    strcpy(game.hint2, "");
    
    updateWindow(&game, &map, &player);
    t = (int)strlen(GAMEOVER_MSG);
    showGameOver(t, GAMEOVER_MSG);
    
    return 0;
}
