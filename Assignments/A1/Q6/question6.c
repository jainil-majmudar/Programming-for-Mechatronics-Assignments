#include <stdio.h>
#include <assert.h>
#include <math.h>

int FactorialWhile (int n);
int FactorialDoWhile (int n);

int FactorialWhile (int n) {
    int i = 1;
    while (n>=1) {
        i = i * n;
        n = n - 1;
    }
    return i;
}

int FactorialDoWhile (int n) {
    int x = 1;
    do {
        if (n==0) {
            break;
        }
        x = x * n;
        n = n - 1;
    }
    while (n>=1);
    return x;
}

int main () {
    int n;
    printf("Input a number: ");
    scanf("%d",&n);
    printf("Output1: %d\n",FactorialWhile(n));
    printf("Output2: %d\n",FactorialDoWhile(n));
    return 0;
}

