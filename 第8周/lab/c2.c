#include <stdio.h>
#include <stdlib.h>

void read(int size, double **matrix) {
    for(int i = 0; i < size; ++i) {
        matrix[i] = malloc(size * sizeof(*matrix[i]));
        for(int j = 0; j < size; ++j) {
            if(i == 0 && j == 0) scanf("\n%lf", &matrix[i][j]);
            else scanf("%lf", &matrix[i][j]);
        }
    }
}

int main(void) {
    int size;
    double **matrixA, **matrixB;

    printf("Enter size:");
    scanf("%d", &size);

    printf("Enter matrix1:");
    matrixA = malloc(size * sizeof(*matrixA));
    read(size, matrixA);

    printf("Enter matrix2:");
    matrixB = malloc(size * sizeof(*matrixB));
    read(size, matrixB);

    double **ans;
    ans = malloc(size * sizeof(*ans));

    for(int i = 0; i < size; ++i) {
        ans[i] = malloc(size * sizeof(*ans[i]));
        for(int j = 0; j < size; ++j) {
            double sum = 0;
            for(int a = 0; a < size; ++a) {
                sum += matrixA[i][a] * matrixB[a][j];
            }
            ans[i][j] = sum;
        }
    }

    printf("The multiplication of the matrices is\n");

    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            printf("%.1lf ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}