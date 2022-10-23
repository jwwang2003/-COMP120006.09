//
//  game.c
//  P1
//
//  Created by Jun Wei Wang on 2022-10-22.
//

#include "game.h"

char actionName[7][35] = {
    "Random move",
    "Moved up!",
    "Moved down!",
    "Moved left!",
    "Moved right!",
    "Skipped move!",
    "Attempt pick up jar!"
};

void append(char* s, char c) {
    int len = (int)strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}

void initGame(Game *game) {
    game->score = 0;
    game->moves = 0;
    strcpy(game->hint1, "Game started! GL!");
    strcpy(game->hint2, "");
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
                strcpy(game->hint2, "You've hit a wall!");
            }
            break;
        case 2:
            game->moves++;
            strcpy(game->hint1, actionName[userIn - 1]);
            if(movePlayerUp(map, player) == 0) {
                game->score -= 5;
                strcpy(game->hint2, "You've hit a wall!");
            }
            break;
        case 3:
            game->moves++;
            strcpy(game->hint1, actionName[userIn - 1]);
            if(movePlayerDown(map, player) == 0) {
                game->score -= 5;
                strcpy(game->hint2, "You've hit a wall!");
            }
            break;
        case 4:
            game->moves++;
            strcpy(game->hint1, actionName[userIn - 1]);
            if(movePlayerLeft(map, player) == 0) {
                game->score -= 5;
                strcpy(game->hint2, "You've hit a wall!");
            }
            break;
        case 5:
            game->moves++;
            strcpy(game->hint1, actionName[userIn - 1]);
            if(movePlayerRight(map, player) == 0) {
                game->score -= 5;
                strcpy(game->hint2, "You've hit a wall!");
            }
            break;
        case 6:
            game->moves++;
            strcpy(game->hint1, actionName[userIn - 1]);
            break;
        case 7:
            if(pickUpJar(map, player)) {
                game->score += 10;
                strcpy(game->hint2, "Jar picked up!");
            } else {
                game->score -= 2;
                strcpy(game->hint2, "No jar here!");
            }
            break;
        case 8:
            strcpy(game->hint1, "Invalid keystroke!");
    }
    
    if(hasJar(map, player->y, player->x)) {
        strcpy(game->hint2, "Squatting on a jar...");
    }
    
    return 0;
}
