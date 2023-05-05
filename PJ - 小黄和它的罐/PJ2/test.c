#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int randomInt(int x, int y) {
    if (x > y) return -1;
    return rand() % (y + 1 - x) + x;
}


int main() {
    int **av = (int**)malloc((12 - 2) * (12 - 2) * sizeof(int*));
    int i = 0;
    for(int y = 1; y < 12 - 1; ++y) {
        for(int x = 1; x < 12 - 1; ++x) {
            av[i] = (int*)malloc(2 * sizeof(int));
            av[i][0] = y;
            av[i][1] = x;
            printf("%d %d\n", av[i][0], av[i][1]);
            i++;
        }
    }

    for(i = 0; i < 50; ++i) {
        printf("%d %d\n", 0, (12 - 2) * (12 - 2) - i - 1);
        int get = randomInt(0, (12 - 2) * (12 - 2) - i - 1);
        int *temp = av[get];
        av[get] = av[(12 - 2) * (12 - 2) - i - 2];
        av[(12 - 2) * (12 - 2) - i - 2] = temp;
        printf("%d\n", get);
    }

    for(i = 0; i < 100; ++i) {
        printf("%d %d\n", av[i][0], av[i][1]);
    }

    return 0;
}