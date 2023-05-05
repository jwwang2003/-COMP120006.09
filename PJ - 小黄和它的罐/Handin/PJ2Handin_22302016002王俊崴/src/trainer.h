//
//  trainer.h
//  PJ2
//
//  Created by Jun Wei Wang on 2022-12-23.
//

#ifndef trainer_h
#define trainer_h

#include <stdio.h>
#include <string.h>

#include "constants.h"
#include "helper.h"
#include "map.h"
#include "player.h"
#include "game.h"
#include "file.h"

void train(int **strategyTable, double *scores);
void generateOffspring(int *par1, int *par2, int *child1, int *child2);
int **getEmptyStrategyTable(void);

#endif /* trainer_h */
