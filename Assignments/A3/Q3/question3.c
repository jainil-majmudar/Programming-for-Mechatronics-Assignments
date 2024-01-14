#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>


int shellsort (int *array, int size, int *h_gaps, int (*subsort)(int* array, int size));
int bubblesort(int* x, int size);

int shellsort (int *array, int size, int *h_gaps, int (*subsort)(int* array, int size)) {
    int totalSwaps=0;
    int swaps = 0;
    int numHGap = 0;
    int count = 0;
    while (h_gaps[count] != 1) {
        numHGap++;
        count++;
    }
    numHGap++;
    for (int hGap = 0; hGap<numHGap;hGap++) {
        int gapWidth = (size/(h_gaps[hGap]));
        for (int i=0; i < h_gaps[hGap]; i++) {
            int *arr1 = malloc(gapWidth*sizeof(int));
            bool swapable = true;
            for (int j = 0; j < gapWidth; j++) {
                if ((j*(h_gaps[hGap])+i) >= size) {
                    swapable=false; 
                } else {
                    arr1[j] = array[j*(h_gaps[hGap])+i];   
                }
            }
            if (swapable==false) {
            } else {
                swaps = subsort(arr1,gapWidth);
                totalSwaps += swaps;
                for (int j = 0; j < gapWidth; j++) {      
                    array[j*(h_gaps[hGap])+i] = arr1[j];
                }
            }
            free(arr1);
        }
        if (h_gaps[hGap]==1) {
            swaps=subsort(array,size);
            totalSwaps+=swaps;
            break;
        }     
    }
    return totalSwaps;
}

int bubblesort(int* x, int size) {
    int temp;
    int swaps = 0;
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (x[j] > x[j+1]) {
                temp = x[j];
                x[j] = x[j + 1];
                x[j+1] = temp;
                swaps ++;
            }
        }
    }
    return swaps;
}


int main () {
    int array[] = {135, 529, 81, 54, 46, 605, 47, 793, 278, 323, 306, 430, 973, 286, 712, 962, 461, 81, 57,
325, 711, 995, 833, 222, 284, 293, 153, 224, 126, 643, 425, 400, 420, 309, 831, 6, 496, 347, 185, 583};
    int size = sizeof(array) / sizeof(array[0]);
    int h_gaps[] = {10, 4, 1};
    int array1[] = {44, 79, 8, 53, 93, 21, 70, 79, 82, 49, 25, 2, 62, 26, 29, 54, 89, 57, 74, 39};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    printf("%d\n", shellsort(array, size, h_gaps, bubblesort));
    printf("%d\n", shellsort(array1, size1, h_gaps, bubblesort));
    return 0;
}