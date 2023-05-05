#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#include <ncurses.h>

#include "constants.h"
#include "helper.h"
#include "map.h"
#include "player.h"
#include "game.h"
#include "window.h"
#include "file.h"

#define STRATFILE "stratFile.txt"
#define SEEDFILE "seed.txt"

void setSeed(long int seed) {
    printf("\nSeed has been set as: %ld\n\n", seed);
    srand(seed);
}

void getSeedFromUser(void) {
    long int seed;
    do {
        printf("Enter seed (-1 random, 0 default): ");
    } while(!(scanf("%ld", &seed) > 0));
    
    if(seed == -1) setSeed(time(NULL));
    else if(seed != 0) setSeed(seed);
}

int main(void) {
//    int t[5] = {0, 0, 1, 0, 1};
//    printf("%d\n", toDeci(t, 3));
    
    system("clear");
    
    FILE *stratFile, *seedFile;
    int chickenStrategy[243] = { 0 };
    long int seed = 0;
    
    printf("Welcome to 智能小黄！！！\n\n");
    
    printf("Attempting to read seed from %s...\n", SEEDFILE);
    seedFile = fopen(SEEDFILE, "r");
    
    if(seedFile == NULL) {
        printf("Failed to read seed file! %s does not exist in root directory!\n\n", SEEDFILE);
        getSeedFromUser();
    } else {
        fscanf(seedFile, "%ld", &seed);
        printf("Read seed: %ld\n", seed);
        
        char t;
        do {
            printf("Use this sead? (Y/N)");
            scanf("\n%c", &t);
        } while(!(t == 'N' || t == 'Y'));
                
        if(t == 'Y') {
            setSeed(seed);
        } else {
            getSeedFromUser();
        }
        
    }
    
    printf("Attemping to read strategy file...\n");
    stratFile = fopen(STRATFILE, "r");
    
    if(stratFile == NULL) {
        printf("Failed to read strategy file! %s does not exist in root directory\n\n", STRATFILE);
        
        printf("Enter strategy table: ");
        char s[243];
        scanf("%243s", s);
        
        for(int i = 0; i < 243; ++i)
            if((s[i] - '0') >= 0 && (s[i] - '0') <= 6) chickenStrategy[i] = s[i] - '0';
            else {
                printf("Invalid strategy table! Program exiting\n");
                return 0;
            }
    } else {
        for(int i = 0; i < 243; ++i) chickenStrategy[i] = fgetc(stratFile) - '0';
    }
    
    printf("Read strategy table: ");
    for(int i = 0; i < 243; ++i) printf("%d", chickenStrategy[i]);
    printf("\n\n");
    
    printf("Strategy file analysis:\n");
    int c[7] = { 0 };
    for(int i = 0; i < 243; ++i) c[chickenStrategy[i]]++;
    for(int i = 0; i < 7; ++i) printf("%d | %d\n", i, c[i]);
    
    printf("\nPress a key to start simulating game...");
    getchar();
    getchar();
    
    Map *map = createMap();
    Player *player = initPlayer();
    Game *game = initGame();
    
    initWindow();
    
    while(game->moves < 200) {
        updateWindow(game, map, player);
        selfMove(game, map, player, chickenStrategy);
//        getch();
        usleep(1000 * 10 * 10);
        if(map->numJars - game->jarsPicked == 0) break;
    }
    
    strcpy(game->hint1, "Final score ->");
    strcpy(game->hint2, "");
    
    updateWindow(game, map, player);
    int t = (int)strlen(GAMEOVER_MSG);
    showGameOver(t, GAMEOVER_MSG);
    
    getch();
    
    return 0;
}
