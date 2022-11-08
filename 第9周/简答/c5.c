#include<stdio.h>
#include<stdlib.h>

int main(void) {
    int n;
    printf("Enter number n: ");
    scanf("%d", &n);
    
    printf("Enter %d rows of letters separated by spaces: \n", n);
    

    char **grid;
    grid = malloc(n * sizeof(*grid));
    for(int i = 0; i < n; ++i) {
        scanf("\n");

        grid[i] =  malloc(n * sizeof(*grid[i]));
       
        for(int j = 0; j < n; ++j) {
            if(j == n - 1) scanf("%c", &grid[i][j]);
            else scanf("%c ", &grid[i][j]);
            
            if(grid[i][j] > 'A' + n - 1 || grid[i][j] < 'A') {
                printf("Wrong input:the letters must be from %c to %c\n", 'A', 'A' + n - 1);
                return 0;
            }
        }
    }

    int flag = 1;
    for(int i = 0; i < n && flag; ++i) {
        int *t1 = malloc(n * sizeof(*t1)), *t2 = malloc(n * sizeof(*t2));
        for(int x = 0; x < n; ++x) {
            t1[x] = 0;
            t2[x] = 0;
        }

        for(int x = 0; x < n; ++x) {
            if(t1[grid[i][x] - 'A'] == 1 || t2[grid[x][i] - 'A'] == 1) {
                flag = 0;
                break;
            } else {
                t1[grid[i][x] - 'A'] = 1;
                t2[grid[x][i] - 'A'] = 1;
            }
        
        }
    }

    if(flag == 1) printf("The input array is a Latin square\n");
    else printf("The input array is NOT a Latin square\n");

    
    return 0;
}