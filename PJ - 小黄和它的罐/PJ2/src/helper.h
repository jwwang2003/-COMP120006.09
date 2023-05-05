//
//  helper.h
//  P1
//
//  Created by Jun Wei Wang on 2022-10-01.
//

#ifndef helper_h
#define helper_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int randomInt(int x, int y);
int *generateIntialStrat(void);
void customQuickSort(int **strategyTable, double *scores, int lt, int rt);
int base3ToBase10(int arr[]);
int toDeci(int arr[], int base);

#endif /* helper_h */
