#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>


int insertionsort(int* x, int size, int (*compare)(int a, int b));
int ascending (int a, int b);
int descending (int a, int b);
void swap (int* num1, int* num2);

int insertionsort(int* x, int size, int (*compare)(int a, int b)) {
    int i, j;
    int count = 0;
    for (i = 1; i < size; i++) {
        for (j = i; j > 0; j--) {
            if ((*compare)(*(x + (j - 1)), *(x + j)) == 1) {
                swap(x + (j - 1), (x + j));
                count += 1;
            } else {
                count += 1;
                break;
            }
        }
    }
    
    for (int k = 0; k < size; k++) {
        printf("%d ", x[k]);
    }
    printf("\nreturn value --> ");
    return count;
}

int ascending (int a, int b) {
    return b < a;
}

int descending (int a, int b) {
    return b > a;
}

void swap (int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main () {
    int arr[] = {548, 845, 731, 258, 809, 522, 73, 385, 906, 891, 988, 289, 808, 128};
    int arr1[] = {100};
    printf("%d\n", insertionsort(arr, sizeof(arr) / sizeof(arr[0]), ascending));
    printf("%d\n", insertionsort(arr1, sizeof(arr1) / sizeof(arr1[0]), ascending));
    return 0;
}
