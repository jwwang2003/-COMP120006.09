//
//  file.c
//  PJ2
//
//  Created by Jun Wei Wang on 2022-12-23.
//

#include "file.h"

#define SEEDFILE "./SEED.txt"
#define STRATFILE "./STRAT.txt"

void writeSead(long seed) {
    FILE *fp;
    
    fp = fopen(SEEDFILE, "w+");
    fprintf(fp, "%ld", seed);
    
    return;
}

long readRead(void) {
    FILE *fp;
    long result;
    
    fp = fopen(SEEDFILE, "r");
    fscanf(fp, "%ld", &result);
    
    return result;
}

void writeStratFile(int *arr) {
    FILE *fp;
    
    fp = fopen(STRATFILE, "w+");
    for(int i = 0; i < POSSIBILITIES; ++i) {
        fprintf(fp, "%d", arr[i]);
    }
    
    fclose(fp);
}

int *readStratFile(char *c) {
    FILE *fp;
    int *strats = (int*)malloc(POSSIBILITIES * sizeof(int));
    
    if(c == NULL) {
        fp = fopen(STRATFILE, "r");
    } else {
        fp = fopen(c, "r");
    }
    
    for(int i = 0; i < POSSIBILITIES; ++i) {
        strats[i] = fgetc(fp) - '0';
    }
    
    fclose(fp);
    
    return strats;
}
