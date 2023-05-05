#include<stdio.h>

int fun(int m, int score[], int below[]) {
    int c = 0;
    int avg = 0;
    for(int i = 0; i < m; ++i) {
        avg += score[i];
    }
    avg /= m;
    for(int i = 0; i < m; ++i) {
        if(score[i] < avg) {
            below[c++] = score[i];
        }
    }

    return c;
}

int main(void) {
    
    int score[] = {
        10, 20, 30, 40, 50, 60, 70, 80, 90
    };

    int below[4];

    printf("%d\n"
    , fun(9, score, below)
    );

    for(int i = 0; i < 4; ++i) {
        printf("%d\n", below[i]);
    }

    return 0;
}