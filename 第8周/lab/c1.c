#include <stdio.h>
#include <string.h>

int n;
char grid[10][10];
char travelled[10][10];

int d[8][2] = {
    { -1, 0 },  // down
    { 1, 0 },   // up
    { 0, -1 },  // left
    { 0 , 1 },  // right
    { -1, -1 }, // down-left
    { -1, 1 },  // down-right
    { 1, -1 },  // up-left
    { 1, 1 },   // up-right
};

int check(int y, int x) {
    if((y >= 0 && y <= 10) && (x >= 0 && x <= 10)) {
        return grid[y][x] == '*';
    }
        
    else return 0;
}

int getNeighbors(int y, int x) {
    int count = 0;
    for(int i = 0; i < 8; ++i) {
        // printf("%d %d\n", y + d[i][0], x + d[i][1]);
        if(check(y + d[i][0], x + d[i][1]))
            count++;
    }
    
    return count;
}

void readGrid(char g[10][10]) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(j == 0) scanf("\n%c", &g[i][j]);
            else scanf("%c", &g[i][j]);
        }
    }
}

int main(void) {
    scanf("%d", &n);

    readGrid(grid);

    readGrid(travelled);

    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < n; ++j) {
    //         printf("%c", grid[i][j]);
    //     }
    //     printf("\n");
    // }

    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < n; ++j) {
    //         printf("%c", travelled[i][j]);
    //     }
    //     printf("\n");
    // }

    // int ans[10][10];
    // memset(ans, 0, sizeof(ans));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(travelled[i][j] == '.') {
                printf("%c", '.');
            } else {
                printf("%d", getNeighbors(i, j));
            }            
        }
        printf("\n");
    }

    return 0;
}