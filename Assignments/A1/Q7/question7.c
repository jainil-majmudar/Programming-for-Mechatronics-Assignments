#include <stdio.h>
#include <assert.h>
#include <math.h>

void mileage (void);

void mileage (void) {
    float f, d, totalf, totald;
    char a;
    int counter = 1;

    do {
        printf("Fuel %d: ", counter);
        scanf("%f",&f);
        printf("Distance %d: ", counter);
        scanf("%f",&d);
        printf("More data?: ");
        scanf("%s",&a);
        totalf += f;
        totald += d;
        counter += 1;
    }
    while (a == 'y');

    printf("Output: %f\n", totald/totalf);
}

int main () {
    mileage();
    return 0;
}

