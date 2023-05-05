//
//  helper.c
//  P1
//
//  Created by Jun Wei Wang on 2022-10-01.
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

int *generateIntialStrat(void) {
    int *randomStrat = (int*)malloc(243 * sizeof(int));
    
    for(int i = 0; i < 243; ++i) {
        randomStrat[i] = randomInt(0,6);
    }
    
    return randomStrat;
}

int partition(int **strategyTable, double *scores, int lt, int rt) {
    int pivot = scores[rt];
    int i = (lt - 1);
    for (int j = lt; j <= rt - 1; ++j) {
        if (scores[j] < pivot) {
            i++;
            double temp = scores[i];
            scores[i] = scores[j];
            scores[j] = temp;
            
            int *t = strategyTable[i];
            strategyTable[i] = strategyTable[j];
            strategyTable[j] = t;
        }
    }
    double temp = scores[i + 1];
    scores[i + 1] = scores[rt];
    scores[rt] = temp;
    
    int *t = strategyTable[i + 1];
    strategyTable[i + 1] = strategyTable[rt];
    strategyTable[rt] = t;
    
    return (i + 1);
}

void customQuickSort(int **strategyTable, double *scores, int lt, int rt) {
    if(lt < rt) {
        int mid = partition(strategyTable, scores, lt, rt);
        customQuickSort(strategyTable, scores, lt, mid - 1);
        customQuickSort(strategyTable, scores, mid + 1, rt);
    }
}

int base3ToBase10(int arr[]) {
    int sum = 0;
    int f = 0;
    for(int i = 0, j = 1; i < 5; ++i) {
        if(!f && arr[i] == 0) continue;
        f = 1;
//        printf("%d ", arr[i]);
        sum += arr[i] * pow(3, j++);
    }
    return sum;
}

int toDeci(int arr[], int base) {
    int len = 5;
    int power = 1; // Initialize power of base
    int num = 0;  // Initialize result
    int i;

    // Decimal equivalent is str[len-1]*1 +
    // str[len-2]*base + str[len-3]*(base^2) + ...
    for (i = len - 1; i >= 0; i--)
    {
        // A digit in input number must be
        // less than number's base
        if (arr[i] >= base)
        {
           printf("Invalid Number");
           return -1;
        }

        num += arr[i] * power;
        power = power * base;
    }

    return num;
}
