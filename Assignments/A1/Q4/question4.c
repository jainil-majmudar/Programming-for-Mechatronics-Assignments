#include <stdio.h>
#include <assert.h>
#include <math.h>

float compoundInterest (float p, int a, float n);

float compoundInterest (float p, int a, float n) {
    return a*pow((1+p),n);
}

int main () {
    float p;
    int a,n;
    printf("Interest rate (p): ");
    scanf("%f",&p);
    printf("Initial amount (a): ");
    scanf("%d",&a);
    printf("Years (n): ");
    scanf("%d",&n);
    printf("Output: %.2f\n",compoundInterest(p,a,n));
    return 0;
}
