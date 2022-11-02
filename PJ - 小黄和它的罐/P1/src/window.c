//
//  window.c
//  P1
//
//  Created by Jun Wei Wang on 2022-10-01.
//

// REFACTORED!

#include "window.h"

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

void drawShallowBox(void) {
    for(int i = 0; i < MAP_H; ++i) {
        for(int j = 0; j < (MAP_W * 2); ++j) {
            if ((i == 0 || i == MAP_H - 1) || (j == 0 || j == (MAP_W * 2) - 1))
                mvprintw(i, j, "+");
        }
    }
}

void drawCenteredText(char c[STRLEN]) {
    int windowWidth = MAP_W * 2;
    
    int len = (int)strlen(c);
    mvprintw(MAP_H / 2, (windowWidth - len) / 2, c);
}

void drawCenteredText_2d(int num, const char c[][STRLEN]) {
    int windowWidth = MAP_W * 2;
    
    for(int i = 0; i < num; ++i) {
        int len = (int)strlen(c[i]);
        mvprintw((MAP_H - num) / 2 + i, (windowWidth - len) / 2, c[i]);
    }
}

void splashScreenMsg(int num, const char c[][STRLEN]) {
    clear();
    move(0,0);
    
    drawShallowBox();
    drawCenteredText_2d(num, c);
    
    move(MAP_H, 0); // move cursor back to the last line
    
    refresh();
}

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
    
    for(int i = 0; i < MAP_H; ++i) {
        for(int j = 0; j < MAP_W; ++j) {
            mvprintw(i, j * 2, getSymbol(map->grid[i][j]));
        }
    }
    
    mvprintw(player->y, player->x * 2, "!");
    
    int h1Len = (int)strlen(game->hint1);
    int h2Len = (int)strlen(game->hint2);
    int hLen = (h1Len > h2Len) ? h1Len : h2Len;
    hLen += 2;
    
    mvprintw(MAP_H, 0, "%s", game->hint1);
    mvprintw(MAP_H, hLen, "Score:   %d", game->score);
    mvprintw(MAP_H + 1, 0, "%s", game->hint2);
    mvprintw(MAP_H + 1, hLen, "# moves: %d", game->moves);
    mvprintw(MAP_H + 2, hLen, "Jars collected: %d", game->jarsPicked);
    mvprintw(MAP_H + 3, hLen, "Jars stat: %d/%d (%d)", map->numJars - game->jarsPicked, (MAP_H - 2)*(MAP_W - 2), map->numJars);
    
    move(MAP_H + 2, 0);
    
    refresh();
    
    return;
}

void showGameOver(int len, const char c[STRLEN]) {
    int windowWidth = MAP_W * 2;
    
    // fill the top with #
    for(int i = 0; i <  windowWidth - 1; ++i) {
        mvprintw(0, i, "#");
    }
    
    // move cursor to the middle and print game over text
    mvprintw(0, (windowWidth - len) / 2, c);
    move(MAP_H + 2, 0); // move cursor back to the last line
    
    refresh();  // flush output to the actual terminal
    
    return;
}
