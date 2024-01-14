#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

double mean(int* x, int size);
double median(int* x, int size);
int mode(int* x, int size);

double mean(int* x, int size) {
    double total;

    for (int i=0; i<size; i++) {
        total += x[i];
    }
    return (total/(size));
}

double median(int* x, int size) {
    int i,j,t;
    int half = floor(size/2);

    for (i=0; i<(size-1); i++)  {
        for (j=0; j<(size-i-1); j++) {
            if (x[j]>x[j+1]) {
                t=x[j];
                x[j]=x[j+1];
                x[j+1]=t;
            }
        }
    }
    if (size%2!=0) {
        return x[half];
    } else {
        return ((x[half]+x[half-1])/2.0);
    }
}

int mode(int* x, int size) {
    int max, i, j, count;
    int mode = x[0];
    
    for (i = 0; i < size; i++) {
        count = 0;
        
        for (j = i; j < size; j++) {
            if (x[j] == x[i]) {
                count++;
            }
        } 
        if (count > max) {
            max = count;
            mode = x[i];
        }
    }
    return mode;
}

int main () {
    int array1[] = {5,4,3,2,1,4,6,9,0,12,54,23,5};
    int array2[] = {5,4,3,2,1,4,6,9,0,12,54,23,5};
    int array3[] = {5,4,3,2,1,4,6,9,0,12,54,23,5};
    int size1 = sizeof(array1) / sizeof(int);
    int size2 = sizeof(array2) / sizeof(int);
    int size3 = sizeof(array3) / sizeof(int);
    printf("Mean: %f\n", mean(array1,size1));
    printf("Median: %f\n", median(array2,size2));
    printf("Mode: %d\n", mode(array3,size3));
    return 0;
}
