#include <stdio.h>
#include <assert.h>
#include <math.h>


int bubblesort(int* x, int size);

int bubblesort(int* x, int size) {
    int i,j,t,count;
    
    for (i=0; i<(size-1); i++) {
        for (j=0; j<(size-i-1); j++) {
            if (x[j]>x[j+1]) {
                t=x[j];
                x[j]=x[j+1];
                x[j+1]=t;
                count++;
            }
        }
    }
    return count;
}

int main () {
    int unsorted[] = {100};
    int size = sizeof(unsorted) / sizeof(int);
    printf("return value --> %d\n", bubblesort(unsorted,size));
    return 0;
}