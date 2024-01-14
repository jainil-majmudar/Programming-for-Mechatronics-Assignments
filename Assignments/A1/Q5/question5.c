#include <stdio.h>
#include <assert.h>
#include <math.h>

int LeapYearCheck (int n);

int LeapYearCheck (int n) {
    if (n % 4 == 0 && n % 100 != 0) {
        return 1;
    }
    else if (n % 4 == 0 && n % 100 == 0 && n % 400 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main () {
    int n;
    printf("Input Year: ");
    scanf("%d",&n);
    if (LeapYearCheck(n) == 1) {
        printf("Output: %d (true)\n",LeapYearCheck(n));
    }
    else {
        printf("Output: %d (false)\n",LeapYearCheck(n));
    }
    return 0;
}
