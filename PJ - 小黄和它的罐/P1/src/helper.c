//
//  helper.c
//  P1
//
//  Created by Jun Wei Wang on 2022-11-01.
//

#include "helper.h"

/**
 实现一个randomInt(int x, int y)函数返回一个x~y之间的随机数，每个随机数的概率就近似为 1/(y-x)
 y always bigger than x
 */
int randomInt(int x, int y) {
    if (x > y) return -1;
    return rand() % (y + 1 - x) + x;
}
