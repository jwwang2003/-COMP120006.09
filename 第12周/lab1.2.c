#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b) { return a > b ? a : b; }

int solve(int cur, int depth, int **map, int *mapLength, int **road) {
printf("-> %d | %d\n", cur, depth);

    int temp = -1;
    int flag = 0;
    for(int i = 0; i < mapLength[cur]; ++i) {
        if(road[cur][map[cur][i]] == 2) continue;
        else road[cur][map[cur][i]]++;

        flag = 1;
        temp = max(temp, solve(map[cur][i], depth + 1, map, mapLength, road));
        road[cur][map[cur][i]]--;
    }

    if(flag == 0) return depth;

   return temp;
}

int main(void) {
    int n, m;

    // n is the number of nodes
    // m is the number of routes

    while(scanf("%d %d", &n, &m) > 0) {
        if(n == 0 && m == 0) break;

        // keeps track of how many times each node was visited
        int **visited = (int**)malloc((n + 1) * sizeof(int*));
        // memset(visited, 0, n * sizeof(int));

        int **map = (int**)malloc((n + 1) * sizeof(int*));
        int *mapLength = (int*)malloc((n + 1) * sizeof(int));

        for(int i = 0; i < n; ++i) {
            map[i] = (int*)malloc(25 * sizeof(int));
            visited[i] = (int*)malloc((n + 1) * sizeof(int));
            memset(visited[i], 0, (n + 1) * sizeof(int));
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
            for(int i = 0; i < n; ++i) {
                memset(visited[i], 0, (n + 1) * sizeof(int));
            }
        }
        
        printf("%d\n", ans);

        scanf("\n");
    }

    return 0;
}