#include <stdio.h>
#include <stdlib.h>

void read(int size, int **matrix) {
    for(int i = 0; i < size; ++i) {
        matrix[i] = malloc(size * sizeof(*matrix[i]));
        for(int j = 0; j < size; ++j) {
            if(i == 0 && j == 0) scanf("\n%d", &matrix[i][j]);
            else scanf("%d", &matrix[i][j]);
        }
    }
}

int main(void) {
    int n, m;

    scanf("%d %d", &n, &m);

    int **m1, **m2;

    m1 = malloc(n * sizeof(*m1));
    read(n, m1);

    m2 = malloc(m * sizeof(*m2));
    read(m, m2);

    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < n; ++j) {
    //         printf("%d ", m1[i][j]);
    //     }
    //     printf("\n");
    // }
    // for(int i = 0; i < m; ++i) {
    //     for(int j = 0; j < m; ++j) {
    //         printf("%d ", m2[i][j]);
    //     }
    //     printf("\n");
    // }
    // int **final;
    // final = malloc((n - m + 1) * sizeof(*final));

    for(int i = 0; i < (n - m + 1); ++i) {
        for(int j = 0; j < (n - m + 1); ++j) {
            int sum = 0;
            for(int k = 0; k < m; ++k) {
                for(int p = 0; p < m; ++p) {
                    sum += m1[i + k][j + p] * m2[k][p];
                }
            }
            printf("%d ", sum);
        }
        printf("\n");
    }

    return 0;
}