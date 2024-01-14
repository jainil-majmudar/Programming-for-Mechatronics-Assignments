#include <stdio.h>
#include <assert.h>
#include <math.h>


int insertionsort(int* x, int size);

int insertionsort(int* x, int size) {
    int i,j,t,count;

    for (i=1; i<size; i++) {
        for (j=i; j>0; j--) {
            if (x[j-1] > x[j]) {
                t = x[j - 1];
                x[j - 1] = x[j];
                x[j] = t;
                count += 1;
            } else {
                count += 1;
                break;
            }
        }
    }
    return count;
}

int main () {
    int unsorted[] = {100};
    int size = sizeof(unsorted) / sizeof(int);
    printf("return value --> %d\n", insertionsort(unsorted,size));
    return 0;
}