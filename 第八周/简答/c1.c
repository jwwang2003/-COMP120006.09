#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    srand(time(NULL));

    int data[8][7] = { 0 };

    for (int i = 0; i < 8; ++i) {
        for(int j = 0; j < 7; ++j) {
            data[i][j] = rand()%8 + 1;
        }
    }

    printf("\t\tSu M T W Th F Sa\n");
    for(int i = 0; i < 8; ++i) {
        printf("Employee%d\t%d  %d %d %d %d  %d %d\n",
        i, 
        data[i][0],
        data[i][1],
        data[1][2],
        data[i][3],
        data[i][4],
        data[i][5],
        data[i][6]
        );
    }

    return 0;
}