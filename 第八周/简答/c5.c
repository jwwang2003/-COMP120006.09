#include <stdio.h>

int check(int y, int x, int arr[][4], int w, int h) {
    int r = 0;
    int c = 0;
    int d1 = 0;
    int d2 = 0;
    for(int i = x; i < w; ++i) {
        if(arr[y][i] == arr[y][x]) r++;
        else break;
    }
    for(int i = x - 1; i >= 0; --i) {
        if(arr[y][i] == arr[y][x]) r++;
        else break;
    }
    for(int i = y; i < h; ++i) {
        if(arr[i][x] == arr[y][x]) c++;
        else break;
    }
    for(int i = y - 1; i >= 0; --i) {
        if(arr[i][x] == arr[y][x]) c++;
        else break;
    }

    int count = 0;
    for(int i = y, j = x; i >= 0 && j >= 0 && count < 4; --i, --j, ++count) {
        if(arr[i][j] == arr[y][x]) d1++;
        else break;
    }

    count = 0;
    for(int i = y + 1, j = x + 1; i < h && j < w && count < 4; ++i, ++j, ++count) {
        if(arr[i][j] == arr[y][x]) d1++;
        else break;
    }

    count = 0;
    for(int i = y, j = x; i >= 0 && j < w && count < 4; --i, ++j, ++count) {
        if(arr[i][j] == arr[y][x]) d2++;
        else break;
    }

    count = 0;
    for(int i = y + 1, j = x - 1; i < h && j >= 0 && count < 4; ++i, --j, ++count) {
        if(arr[i][j] == arr[y][x]) d2++;
        else break;
    }

    return r > 3 || c > 3 || d1 > 3 || d2 > 3;
}

int solve(int arr[][4]) {
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            if(check(i, j, arr, 4, 4)) return 1;
        }
    }
}

int main(void) {
    int test[][4] = {
        {1, 2, 3, 1},
        {2, 3, 1, 2},
        {1, 1, 3, 1},
        {1, 2, 3, 1},
    };
    
    if(solve(test)) {
        printf("Has repeating!\n");
    } else {
        printf("No repeating!\n");
    }

    return 0;
}