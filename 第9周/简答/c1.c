#include<stdio.h>
#include<stdlib.h>

int main(void) {

    int a[] = { 4, 5, 6, 2, 3, 1, 8, -20 };
    int b[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 12, 190, 120, -10 };

    printf("Original:\n");
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    for(int i = 0; i < sizeof(b)/sizeof(b[0]); ++i) {
        printf("%d ", b[i]);
    }
    printf("\n");

    printf("Sorted:\n");
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
        for(int j = i + 1; j < sizeof(a)/sizeof(a[0]); ++j) {
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp; 
            }
        }
    }

    for(int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    for(int i = 0; i < sizeof(b)/sizeof(b[0]); ++i) {
        for(int j = i + 1; j < sizeof(b)/sizeof(b[0]); ++j) {
            if(b[i] > b[j]) {
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp; 
            }
        }
    }

    for(int i = 0; i < sizeof(b)/sizeof(b[0]); ++i) {
        printf("%d ", b[i]);
    }
    printf("\n");

    int sizeA = sizeof(a)/sizeof(a[0]), sizeB = sizeof(b)/sizeof(b[0]);
    int *big;
    int bigSize = sizeA > sizeB ? sizeA : sizeB;
    big = malloc(bigSize * sizeof(*big));
    for(int i = 0; i < bigSize; ++i) big[i] = sizeA > sizeB ? a[i] : b[i];
    int *small;
    int smallSize = sizeA > sizeB ? sizeB : sizeA;
    small = malloc(smallSize * sizeof(*small));
    for(int i = 0; i < smallSize; ++i) small[i] = sizeA < sizeB ? a[i] : b[i];

    int *c = malloc((sizeA + sizeB) * sizeof(*c));
    int i = 0, j = 0;
    while(i < bigSize) {
        if(big[i] == small[j]) {
            c[i + j] = big[i];
            ++i;
            c[i + j] = small[j];
            ++j;
        } else if(big[i] > small[j] && j < smallSize) {
            c[i + j] = small[j];
            ++j;
        } else {
            c[i + j] = big[i];
            ++i;
        }
    }

    printf("Mixed:\n");
    for(int i = 0; i < (sizeof(a)/sizeof(a[0]) + sizeof(b)/sizeof(b[0])); ++i) {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}