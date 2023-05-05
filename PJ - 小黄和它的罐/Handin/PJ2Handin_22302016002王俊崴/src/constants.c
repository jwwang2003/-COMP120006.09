//
//  constants.c
//  P1
//
//  Created by Jun Wei Wang on 2022-10-01.
//

// REFACTORED!

#include "constants.h"

const char WELCOME_MSGS[2][STRLEN] = {
    "PRESS A KEY",
    "TO START!"
};

const char GAMEOVER_MSG[STRLEN] = "GAME OVER!";
const char INSTRUCTION_MSGS[6][STRLEN] = {
    "Movement:",
    "WASD or arrows",
    "Action:",
    "E - Pick up | R - Random",
    "F - Stay/Skip | G - Exit",
    "[A] to ack",
};

const char GAME_MSGS[6][STRLEN] = {
    "Game started! GL!",
    "You've hit a wall! (-5)",
    "Jar picked up! (+10)",
    "No jar here! (-2)",
    "Squatting on a jar...",
    "Invalid keystroke!"
};

const int pDisplacement[4][2] = {
    {-1, 0},    // up
    {1, 0},     // down
    {0, -1},    // left
    {0, 1}      // right
};

const char actionName[7][STRLEN] = {
    "Random move",
    "Moved up!",
    "Moved down!",
    "Moved left!",
    "Moved right!",
    "Skipped move!",
    "Attempt pick up jar!"
};
