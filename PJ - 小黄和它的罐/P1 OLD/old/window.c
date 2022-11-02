//
//  window.c
//  P1
//
//  Created by Jun Wei Wang on 2022-10-21.
//

#include "window.h"
#include "map.h"

#include <math.h>
#include <string.h>
#include <ncurses.h>

void initWindow(void) {
    initscr();  // init ncurses
    raw();
    keypad(stdscr, TRUE);
    noecho();
    
    clear();    // clear terminal display
    move(0,0);

    refresh();
}

void drawShallowBox(int h, int w) {
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < (w * 2); ++j) {
            if ((i == 0 || i == h - 1) || (j == 0 || j == (w * 2) - 1))
                mvprintw(i, j, "+");
        }
    }
}

void drawCenteredText(int h, int w, char c[30]) {
    int windowWidth = w * 2;
    
    int len = (int)strlen(c);
    mvprintw(h/ 2, (windowWidth - len) / 2, c);
}

void drawCenteredText_2d(int h, int w, int num, char c[][30]) {
    int windowWidth = w * 2;
    
    for(int i = 0; i < num; ++i) {
        int len = (int)strlen(c[i]);
        mvprintw((h - num) / 2 + i, (windowWidth - len) / 2, c[i]);
    }
}

void splashScreenMsg(int h, int w, int num, char c[][30]) {
    clear();
    move(0,0);
    
    drawShallowBox(h, w);
    drawCenteredText_2d(h, w, num, c);
    
    move(h, 0); // move cursor back to the last line
    
    refresh();
}

//void showWelcome(int h, int w) {
//    clear();
//    move(0,0);
//
//    int windowWidth = w * 2;
//
//    drawShallowBox(h, w);
//
//    int numInstructions = sizeof(WELCOME_MSG)/sizeof(WELCOME_MSG[0]);
//    drawCenteredText_2d(h, w, numInstructions, WELCOME_MSG);
//
//    move(h, 0); // move cursor back to the last line
//
//    refresh();
//
//    return;
//}
//
//void showInstructions(int h, int w) {
//    clear();
//    move(0,0);
//
//    drawShallowBox(h, w);
//
//    int numInstructions = sizeof(INSTRUCTION_MSGS)/sizeof(INSTRUCTION_MSGS[0]);
//    drawCenteredText_2d(h, w, numInstructions, INSTRUCTION_MSGS);
//
//    move(h, 0); // move cursor back to the last line
//
//    refresh();
//
//    return;
//}

char *getSymbol(int i) {
    switch (i) {
        case 0:
            return " ";
        case 1:
            return "@";
        case 2:
            return "#";
        default:
            return "?";
    }
}

void updateWindow(Game *game, Map *map, Player *player) {
    clear();
    move(0,0);
    
    for(int i = 0; i < map->height; ++i) {
        for(int j = 0; j < map->width; ++j) {
            mvprintw(i, j * 2, getSymbol(map->grid[i][j]));
        }
    }
    
    mvprintw(player->y, player->x * 2, "!");
    
    int h1Len = (int)strlen(game->hint1);
    int h2Len = (int)strlen(game->hint2);
    int hLen = (h1Len > h2Len) ? h1Len : h2Len;
    hLen += 2;
    
    mvprintw(map->height , 0, "%s", game->hint1);
    mvprintw(map->height, hLen, "Score:   %d", game->score);
    mvprintw(map->height + 1, 0, "%s", game->hint2);
    mvprintw(map->height + 1, hLen, "# moves: %d", game->moves);
    
    move(map->height + 2, 0);
    
    refresh();
    
    return;
    
//    for(int i = 0; i < w + 2; ++i) {
//        mvprintw(0, i * 2, "#");
//        mvprintw(h + 1, i * 2, "#");
//    }
//
//    for(int i = 0; i < h; ++i) {
//        mvprintw(i + 1, 0, "#");
//        mvprintw(i + 1, (w + 1) * 2, "#");
//    }
    
//    for(int y = 1; y <= h; ++y) {
//        for(int x = 1; x <= w; ++x) {
//            switch(map[y - 1][x - 1]) {
//                case 0:
//                    mvprintw(y, x * 2, " ");
//                    break;
//                case 1:
//                    mvprintw(y, x * 2, "@");
//                    break;
//                default:
//                    break;
//            }
//        }
//    }
}

void showGameOver(int h, int w, int len, char *c) {
    int windowWidth = w * 2;
    
    // fill the top with #
    for(int i = 0; i <  windowWidth - 1; ++i) {
        mvprintw(0, i, "#");
    }
    
    // move cursor to the middle and print game over text
    mvprintw(0, (windowWidth - len) / 2, c);
    move(h + 2, 0); // move cursor back to the last line
    
    refresh();  // flush output to the actual terminal
    
    return;
}
