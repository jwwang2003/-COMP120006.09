#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int solve(int current, int depth, int **map, int *mapLength, int *visited) {
    printf("%d %d %d\n", current, visited[current], depth);
    
    if(visited[current] > 2) return depth;
    if(mapLength[current] == 0) return depth;
    
    int temp = -1;
    visited[current]++;
    for(int i = 0; i < mapLength[current]; ++i) {
        
        // printf("%d\n", visited[current]);
        if(temp == -1) {
            temp = solve(map[current][i], depth + 1, map, mapLength, visited);
        } else {
            temp = max(temp, solve(map[current][i], depth + 1, map, mapLength, visited));
        }
    }
    visited[current]--;
    
    return temp;
}

int main(void) {

    int n, m;

    while(scanf("%d %d", &n, &m) > 0) {
        if(n == 0 && m == 0) break;

        int *visited = (int*)malloc(n * sizeof(int));
        memset(visited, 0, n * sizeof(int));

        int **map = (int**)malloc(n * sizeof(int*));
        // (int**)malloc(r * sizeof(int*))
        int *mapLength = (int*)malloc(m * sizeof(int));

        for(int i = 0; i < n; ++i) {
            map[i] = (int*)malloc(26 * sizeof(int));
        }

        for(int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);

            map[b][mapLength[b]++] = a;
        }

        for(int i = 0; i < m; ++i) {
            printf("%d | ", i);
            for(int j = 0; j < mapLength[i]; ++j) {
                printf("%d ", map[i][j]);
            }

            printf("| %d", mapLength[i]);
            printf("\n");
        }
        
        int ans = 0;
        for(int i  = 0; i < n; ++i) {
            printf("\n");
            ans = max(ans, solve(i, 0, map, mapLength, visited));
            memset(visited, 0, n * sizeof(int));
        }
        
        printf("%d\n", ans);

        free(visited);
        free(map);
        free(mapLength);
    }
    

    return 0;
}