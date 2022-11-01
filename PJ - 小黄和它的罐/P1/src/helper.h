//
//  helper.h
//  P1
//
//  Created by Jun Wei Wang on 2022-11-01.
//

#ifndef helper_h
#define helper_h

#include <stdio.h>

#include <stdlib.h>

// rand_prob(50, 1, 2) would have equal % between 1 or 2
// rand_prob(10, 1, 2) would favor 1 over 2, only 10% change of 2
int randomIntProb(int percent, int min, int max);
int randomInt(int x, int y);

#endif /* helper_h */
