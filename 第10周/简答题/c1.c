#include<stdio.h>

int findBig(int arr[], int size) {
    if(size == 0) return 0;
    int mostBig = arr[0];
    for(int i = 1; i < size; ++i) {
        if(arr[i] > mostBig) mostBig = arr[i];
    }

    return mostBig;
}

int main(void) {
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    printf("%d\n", findBig(arr, sizeof(arr)/sizeof(arr[0])));

    return 0;
}