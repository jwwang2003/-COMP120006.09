//
//  game.c
//  P1
//
//  Created by Jun Wei Wang on 2022-11-01.
//

// REFACTORED!

#include "game.h"

void append(char* s, char c) {
    int len = (int)strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}

Game *initGame(void) {
    Game *game = (Game*)malloc(sizeof(Game));
    game->score = 0;
    game->moves = 0;
    game->jarsPicked = 0;
    strcpy(game->hint1, GAME_MSGS[0]);
    strcpy(game->hint2, "");
    
    return game;
}

int run(Game *game, Map *map, Player *player) {
    int userIn = getUserInput();
    
    strcpy(game->hint2, "");
        
    switch(userIn) {
        case -1:
            return -1;
        case 1:
            game->moves++;
            strcpy(game->hint1, actionName[userIn - 1]);
            if(movePlayerRandom(map, player) == 0) {
                game->score -= 5;
                strcpy(game->hint2, GAME_MSGS[1]);
            }
            break;
        case 2:
            game->moves++;
            strcpy(game->hint1, actionName[userIn - 1]);
            if(movePlayerUp(map, player) == 0) {
                game->score -= 5;
                strcpy(game->hint2, GAME_MSGS[1]);
            }
            break;
        case 3:
            game->moves++;
            strcpy(game->hint1, actionName[userIn - 1]);
            if(movePlayerDown(map, player) == 0) {
                game->score -= 5;
                strcpy(game->hint2, GAME_MSGS[1]);
            }
            break;
        case 4:
            game->moves++;
            strcpy(game->hint1, actionName[userIn - 1]);
            if(movePlayerLeft(map, player) == 0) {
                game->score -= 5;
                strcpy(game->hint2, GAME_MSGS[1]);
            }
            break;
        case 5:
            game->moves++;
            strcpy(game->hint1, actionName[userIn - 1]);
            if(movePlayerRight(map, player) == 0) {
                game->score -= 5;
                strcpy(game->hint2, GAME_MSGS[1]);
            }
            break;
        case 6:
            game->moves++;
            strcpy(game->hint1, actionName[userIn - 1]);
            break;
        case 7:
            if(pickUpJar(map, player)) {
                game->score += 10;
                game->jarsPicked++;
                strcpy(game->hint2, GAME_MSGS[2]);
            } else {
                game->score -= 2;
                strcpy(game->hint2, GAME_MSGS[3]);
            }
            break;
        case 8:
            strcpy(game->hint1, GAME_MSGS[5]);
    }
    
    if(hasJar(map, player->y, player->x)) {
        strcpy(game->hint2, GAME_MSGS[4]);
    }
    
    return 0;
}
