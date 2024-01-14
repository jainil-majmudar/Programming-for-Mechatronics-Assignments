#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

void removeDups(int* in, int size);

void removeDups(int* in, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (in[i] == in[j]) {
                in[j] = 0;
            }
        }
    }
    
    int *arr = calloc(size, sizeof(int));
    int pos = 0;
    for (int h = 0; h < size; h++) {
        if (in[h] != 0) {
            *(arr + pos++) = *(in + h);
        }
    }
    
    for (int k = 0; k < size; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
}

int main () {
    int arr[] = {1,2,2,2,3,3,4,2,4,5,6,6};
    int arr1[] = {1,2,2,3,4,8,6,9,7,2,1,4,5,7,8,8,8,7};
    removeDups(arr, sizeof(arr)/sizeof(int));
    removeDups(arr1, sizeof(arr1)/sizeof(int));
    return 0;
}