#include<stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int findPivot(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if(!(low < high)) return;

    int pivot = findPivot(array, low, high);

    quickSort(array, low, pivot - 1);
    quickSort(array, pivot + 1, high);
}


int main(void) {
    int nums[] = { 4, 2, 1, 5, 6, 7, 3, 9, 11, 10 };
    int len = sizeof(nums)/sizeof(nums[0]);

    quickSort(nums, 0, len - 1);

    for(int i = 0; i < len; ++i) printf("%d ", nums[i]);
    printf("\n");

    return 0;
}