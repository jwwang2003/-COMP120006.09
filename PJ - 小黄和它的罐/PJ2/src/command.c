//
//  command.c
//  P1
//
//  Created by Jun Wei Wang on 2022-10-01.
//

// REFACTORED!

#include "command.h"

int getUserInput(void) {
    int ch = getch();
        switch(ch) {
            case 'w':
            case KEY_UP:
                return 2;
            case 's':
            case KEY_DOWN:
                return 3;
            case 'a':
            case KEY_LEFT:
                return 4;
            case 'd':
            case KEY_RIGHT:
                return 5;
            case 'f':
                return 6;
            case 'e':
                return 7;
            case 'r':
                return 1;
            case 'g':       // end game key stroke
                return -1;  // flag for game end signal
            default:
                return 8;   // indicates invalid input
        }
}
