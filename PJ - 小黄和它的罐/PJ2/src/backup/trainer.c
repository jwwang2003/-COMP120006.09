//
//  trainer.c
//  PJ2
//
//  Created by Jun Wei Wang on 2022-12-23.
//

#include "trainer.h"

int **getEmptyStrategyTable(void) {
    int **table = (int**)malloc(200 * sizeof(int*));
    for(int i = 0; i < 200; ++i) {
        table[i] = (int*)malloc(243 * sizeof(int));
        for (int j = 0; j < 243; ++j) {
            table[i][j] = 0;
        }
    }
    return table;
}

void freeStrategyTable(int **strategyTable) {
    for(int i = 0; i < 200; ++i) {
        free(strategyTable[i]);
    }
    free(strategyTable);
    return;
}

void generateOffspring(int *par1, int *par2, int *child1, int *child2) {
    /**
     Test code
     int *par1, *par2, *child1, *child2;
     
     par1 = (int*)malloc(sizeof(int*) * 243);
     par2 = (int*)malloc(sizeof(int*) * 243);
     child1 = (int*)malloc(sizeof(int*) * 243);
     child2 = (int*)malloc(sizeof(int*) * 243);
     
     for(int i = 0; i < 243; ++i) {
         par1[i] = 0;
         par2[i] = 1;
     }
     
     generateOffspring(par1, par2, child1, child2);
     
     for(int i = 0; i < 243; ++i) {
         printf("%d", child1[i]);
     }
     printf("\n");
     for(int i = 0; i < 243; ++i) {
         printf("%d", child2[i]);
     }
     */
    int i = 0;
    int j = 0;
    while(i < 243) {
        if(i > (j + 1)*60 && (j + 2)*60 < 243) {
            ++j;
        }
        
        int shouldMutate = randomInt(0, 400) == 0;
        if(shouldMutate) {
            if(randomInt(0, 1) == 0) {
                child1[i] = randomInt(0, 6);
            }
            if(randomInt(0, 1) == 1) {
                child2[i] = randomInt(0, 6);
            }
        } else {
            if(j % 2 == 0) {
                child1[i] = par1[i];
                child2[i] = par2[i];
            } else {
                child1[i] = par2[i];
                child2[i] = par1[i];
            }
        }
        
        ++i;
    }
}

void simulateGame(int chickenID, int **strategyTable, double *scores) {
    // initialize game
    Map *map = createMap();
    Player *player = initPlayer();
    Game *game = initGame();
    
    // simulate chicken game and add score to scoreboard
    int resultScore = autoRun(game, map, player, strategyTable[chickenID]);
    scores[chickenID] += resultScore;
    
    // free up memory
    freeMap(map);
    freePlayer(player);
    freeGame(game);
}

// favors top performers (result is sorted from lowest to highest, therefore favors last)
int biasedRandChicken(void) {
    int randChick = randomInt(1, 20099);
//    floor((-1 + sqrtf(1 + 8*randChick))/2.0);
//    floor((2.0*randChick)/200);
    int chickID = floor((-1 + sqrtf(1 + 8 * randChick))/2.0);
    return chickID;
}

void train(int **strategyTable, double *scores) {
    // have all 200 小黄 play the game 100 times and average the score
    for(int i = 0; i < 200; ++i) {
        for(int j = 0; j < 100; ++j) {
            simulateGame(i, strategyTable, scores);
        }
        scores[i] = scores[i] / 100.0;
    }
    
    customQuickSort(strategyTable, scores, 0, 200 - 1);
    
    int **newStrategyTable = getEmptyStrategyTable();
    int newStratCounter = 0;
    
    // proceed with 95 tries in selecting two chickens and
    // geneating two offspring from those two chickens
    for (int counter = 0; counter < 95; ++counter) {
        int chick1 = biasedRandChicken();
        int chick2;
        do {
            chick2 = biasedRandChicken();
        } while (chick1 == chick2);
        
        generateOffspring(strategyTable[chick1],
                          strategyTable[chick2],
                          newStrategyTable[newStratCounter],
                          newStrategyTable[newStratCounter + 1]
                          );
        
        newStratCounter += 2;
    }
    
    for(; newStratCounter < 200; ++newStratCounter) {
        for(int j = 0; j < 243; ++j) {
            newStrategyTable[newStratCounter][j] = strategyTable[newStratCounter][j];
        }
    }
    
    memcpy(&strategyTable[0][0], &newStrategyTable[0][0], sizeof(int) * 200 * 243);
    freeStrategyTable(newStrategyTable);
    
    return;
}
