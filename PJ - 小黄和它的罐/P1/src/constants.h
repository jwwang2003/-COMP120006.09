//
//  constants.h
//  P1
//
//  Created by Jun Wei Wang on 2022-10-01.
//

// REFACTORED!

#ifndef constants_h
#define constants_h

#include <stdio.h>

#define STRLEN 100   // set each string to 100 characters, should be plenty

extern const char WELCOME_MSGS[2][STRLEN];
extern const char GAMEOVER_MSG[STRLEN];
extern const char INSTRUCTION_MSGS[6][STRLEN];
extern const char GAME_MSGS[6][STRLEN];

// inner walls are also contained in the grid
// therefore the grid must be 2 units more on
// both axis to allow for a 10x10 playable space
#define MAP_H 12
#define MAP_W 12

// player displacement coordinates
extern const int pDisplacement[4][2];

extern const char actionName[7][STRLEN];

#endif /* constants_h */
