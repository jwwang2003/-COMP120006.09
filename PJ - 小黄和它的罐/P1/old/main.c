#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

#include "map.h"
#include "player.h"
#include "game.h"
#include "window.h"

// inner walls are also contained in the grid
// therefore the grid must be 2 units more on
// both axis to allow for a 10x10 playable space
const int MAP_HEIGHT = 12;  // y axis
const int MAP_WIDTH = 12;   // x axis

char WELCOME_MSG[2][30] = {
    "PRESS A KEY",
    "TO START!"
};
char GAMEOVER_MSG[30] = "GAME OVER!";
char INSTRUCTION_MSGS[6][30] = {
    "Movement:",
    "WASD or arrows",
    "Action:",
    "E - Pick up | R - Random",
    "F - Stay/Skip | G - Exit",
    "[A] to ack",
};

int main(void) {
    srand((uint)time(NULL));   // Initialization, should only be called once!
    
    initWindow();
    
    int t = sizeof(WELCOME_MSG)/sizeof(WELCOME_MSG[0]);
    splashScreenMsg(MAP_HEIGHT, MAP_WIDTH, t, WELCOME_MSG);
    getchar();
    
    t = sizeof(INSTRUCTION_MSGS)/sizeof(INSTRUCTION_MSGS[0]);
    splashScreenMsg(MAP_HEIGHT, MAP_WIDTH, t, INSTRUCTION_MSGS);
    while (getchar() != 'a') { continue; };
    
    Map map;
    createMap(&map, MAP_HEIGHT, MAP_WIDTH);
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
    showGameOver(MAP_HEIGHT, MAP_WIDTH, t, GAMEOVER_MSG);
    
//    showGameOver(MAP_HEIGHT, MAP_WIDTH);
    
//    showWelcome(MAP_HEIGHT, MAP_WIDTH);
    
//    int **grid = createMap(MAP_HEIGHT, MAP_WIDTH);
//
//    updateDisplay(grid, 0, 0, MAP_HEIGHT, MAP_WIDTH);
//
//    Map map;
//    initscr();
//
//    move(10, 20);
//    printw("Hello World!!");
//    refresh(); // you should do this frequently, to flush changes from memory to screen
//    
////    printf("%d", test(1, 5));
//
//    //printing();
//
//    //moving_and_sleeping();
//
//    //colouring();
//
//    addstr("\npress any key to exit...");
//    refresh();
//
//    getch();
//
//    endwin();
//    getchar();
//    
//    showGameOver(MAP_HEIGHT, MAP_WIDTH);

    return EXIT_SUCCESS;
}
