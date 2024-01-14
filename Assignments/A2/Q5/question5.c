#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>


int binsearch(int* x, int y, int size);

int binsearch(int* x, int y, int size) {
    int a,m,count;
    int b = size-1;
    bool f = false;

    while (a<=b) {
        m = (a+b)/2;
        count++;
        if (x[a]==y || x[b]==y || x[m]==y) {
            f = true;
            break;
            
        } else if (x[m]<y) {
            a = ((a+b)/2)+1;
        } else if (x[m]>y) {
            b = ((a+b)/2)-1;
        }
    } if (f == false) { //test
        return -1;
    } else {
        return count;
    }
}

int main () {
    int sorted[] = {100};
    int size = sizeof(sorted) / sizeof(int);
    printf("return value --> %d\n", binsearch(sorted,100,size));
    return 0;
}