#include<stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b; 
}

int main(void) {

    int matrix[50][50] = { 0 };

    printf("Enter the number of rows in the matrix:");
    int rows;
    scanf("%d", &rows);
    printf("Enter the number of cols in the matrix:");
    int cols;
    scanf("%d", &cols);

    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if(j == 0) scanf("\n%d", &matrix[i][j]);
            else scanf("%d", &matrix[i][j]);
        }
    }

    int dp[50][50] = {0};
    for(int i = 0; i < cols; ++i) {
        dp[i][0] = matrix[i][0];
    }

    for(int i = 0; i < rows; ++i) {
        dp[0][i] = matrix[0][i];
    }

    // for (int i = 0; i < rows; ++i) {
    //     for (int j = 0; j < cols; ++j) {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    int biggest = 0;
    int y, x;

    for(int i = 1; i < rows; ++i) {
        for(int j = 1; j < cols; ++j) {
            if(matrix[i][j] == 1) {
                dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
            } else dp[i][j] = 0;

            if(biggest < dp[i][j]) {
                biggest = dp[i][j]; 
                y = i;
                x = j;
            }
        }
    }

    // for (int i = 0; i < rows; ++i) {
    //     for (int j = 0; j < cols; ++j) {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("The maximum square submatrix is at (%d,%d) with size %d", y, x, biggest);

    return 0;
}