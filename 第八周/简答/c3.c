#include<stdio.h>
#include<string.h>

int check(char g[3][3], char p, int y, int x) {
    int r = 0;
    int c = 0;
    int d1 = 0;
    int d2 = 0;
    for(int i = x; i < 3; ++i) {
        if(g[y][i] == p) r++;
        else break;
    }
    for(int i = x - 1; i >= 0; --i) {
        if(g[y][i] == p) r++;
        else break;
    }
    for(int i = y; i < 3; ++i) {
        if(g[i][x] == p) c++;
        else break;
    }
    for(int i = y - 1; i >= 0; --i) {
        if(g[i][x] == p) c++;
        else break;
    }

    for(int i = 0; i < 3; ++i) {
        if(g[i][i] == p) d1++;
        else break;
    }
    for(int i = 0; i < 3; ++i) {
        if(g[i][2-i] == p) d2++;
        else break;
    }
    return r == 3 || c == 3 || d1 == 3 || d2 == 3;
}

int main(void) {
    char grid[3][3];
    memset(grid, ' ', sizeof(grid));

    int turn = 1;

    for(int i = 0; i < 13; ++i) printf("-");
    printf("\n");
    for(int i = 0; i < 3; ++i) {
        printf("| %c | %c | %c |\n", grid[i][0], grid[i][1], grid[i][2]);
        for(int i = 0; i < 13; ++i) printf("-");
        printf("\n");
    }
    
    while(1) {
        int r, c;

        do {
            printf("Enter a row (0, 1 , or 2) for player ");
            if(turn) printf("X: ");
            else printf("O: ");
            scanf("%d", &r);
        } while (!(r >= 0 && r < 3));

        do {
            printf("Enter a column (0, 1, or 2) for player ");
            if(turn) printf("X: ");
            else printf("O: ");
            scanf("%d", &c);
        } while (!(c >= 0 && c < 3));

        grid[r][c] = turn ? 'X' : 'O';

        for(int i = 0; i < 13; ++i) printf("-");
        printf("\n");
        for(int i = 0; i < 3; ++i) {
            printf("| %c | %c | %c |\n", grid[i][0], grid[i][1], grid[i][2]);
            for(int i = 0; i < 13; ++i) printf("-");
            printf("\n");
        }

        if(check(grid, turn ? 'X' : 'O', r, c)) {
            printf("Player %c won\n", turn ? 'X' : 'O');
            break;
        }

        turn = !turn;
    }

    return 0;
}