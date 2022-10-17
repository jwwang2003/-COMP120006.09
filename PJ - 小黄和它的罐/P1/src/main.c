#include<ncurses.h>
#include<stdlib.h>

#include"map.h"

int main(void)
{
    initscr();

    move(10, 20);
    printw("Hello World!!");
    refresh(); // you should do this frequently, to flush changes from memory to screen
    
    printf("%d", test(1, 5));

    //printing();

    //moving_and_sleeping();

    //colouring();

    addstr("\npress any key to exit...");
    refresh();

    getch();

    endwin();

    return EXIT_SUCCESS;
}
