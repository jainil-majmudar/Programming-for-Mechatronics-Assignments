#include <stdio.h>
#include <assert.h>
#include <math.h>

int juggler(int n);

int juggler(int n) {
    if (n != 1) {
        if (n%2 == 0) {
            n = floor(pow(n, 0.5));
            return (juggler(n) + 1);
        } else {
            n = floor(pow(n, 1.5));
            return (juggler(n) + 1);
        }
    }
    return 0;
}

int main () {
    printf("output --> %d\n", juggler(20));
    return 0;
}