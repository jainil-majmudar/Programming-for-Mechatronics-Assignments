#include <stdio.h>
#include <assert.h>
#include <math.h>

int multiples (int x, int y, int N);

int multiples (int x, int y, int N) {
    int sum = 0;
    for (int i = 0; i <= N; i++) {
        if (i % x == 0 || i % y == 0) {
            sum += i;
        }
    }
    return sum;
}

int main () {
    int x,y,N;
    printf("x value: ");
    scanf("%d",&x);
    printf("y value: ");
    scanf("%d",&y);
    printf("N value: ");
    scanf("%d",&N);
    printf("Output: %d\n",multiples(x,y,N));
    return 0;
}
