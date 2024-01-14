#include <stdio.h>
#include <assert.h>
#include <math.h>

int minutes (int m, int h, int d);

int minutes (int m, int h, int d) {
    return (1440*d + 60*h + m);
}

int main () {
    int m,h,d;
    printf("Minutes:");
    scanf("%d",&m);
    printf("Hours:");
    scanf("%d",&h);
    printf("Days:");
    scanf("%d",&d);
    printf("Output in minutes: %d\n",minutes(m,h,d));
    return 0;
}

