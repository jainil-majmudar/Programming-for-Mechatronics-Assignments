#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdint.h>

float onethird (int n);

float onethird (int n) {
    long long int sum = 0;
    for (int i=1;i<=n;i++) {
        sum += pow(i,2);
    }
    return sum/pow(n,3);
}

int main () {
    int n;
    printf("Input a number: ");
    scanf("%d",&n);
    printf("Output: %f\n",onethird(n));
    return 0;
}

