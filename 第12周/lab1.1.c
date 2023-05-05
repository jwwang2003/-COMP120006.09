#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DEBUG

int max(int a, int b) {
    return a > b ? a : b;
}

int solve(int cur, int depth, int **map, int *mapLength, int *visited) {
    printf("-> %d | %d\n", cur, depth);
    // base cases
    if(visited[cur] > 2) return depth;
    if(mapLength[cur] == 0) return depth;

    int temp = -1;
    
    for(int i = 0; i < mapLength[cur]; ++i) {
        visited[cur]++;
        if(temp == -1) {
            temp = solve(map[cur][i], depth + 1, map, mapLength, visited);
        } else {
            temp = max(temp, solve(map[cur][i], depth + 1, map, mapLength, visited));
        }
        visited[cur]--;
    }
    

    return temp;
}

int main(void) {
    int n, m;

    // n is the number of nodes
    // m is the number of routes

    while(scanf("%d %d", &n, &m) > 0) {
        if(n == 0 && m == 0) break;

        // keeps track of how many times each node was visited
        int *visited = (int*)malloc(n * sizeof(int));
        memset(visited, 0, n * sizeof(int));

        int **map = (int**)malloc(n * sizeof(int*));
        int *mapLength = (int*)malloc(n * sizeof(int));

        for(int i = 0; i < n; ++i) {
            map[i] = (int*)malloc(25 * sizeof(int));
        }

        for(int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);

            // map[b][mapLength[b]++] = a;
            map[a][mapLength[a]++] = b;
            // because it can go both ways
        }

        #ifdef DEBUG
        printf("\n");
        for(int i = 0; i < m; ++i) {
            printf("%d | ", i);
            for(int j = 0; j < mapLength[i]; ++j) {
                printf("%d ", map[i][j]);
            }

            printf("| %d", mapLength[i]);
            printf("\n");
        }
        #endif

        int ans = 0;
        for(int i  = 0; i < n; ++i) {
            printf("\n");
            ans = max(ans, solve(i, 0, map, mapLength, visited));
            memset(visited, 0, n * sizeof(int));
        }
        
        printf("%d\n", ans);

        scanf("\n");
    }    


    return 0;
}