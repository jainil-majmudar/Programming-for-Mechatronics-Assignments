#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

void reverse(char* str);
int count(char* str);

void reverse(char* str) {
    int i = -1;
    char x[]="\0";
    char *xptr = x;

    while (*str != *xptr) {
        str++;
        i++;
    }
        
    char rvr[i + 1];
    char *rvrptr = rvr;
    
    while (i >= 0) {
        str--;
        *rvrptr = *str;
        rvrptr++;
        i--;
    }
    printf("reverse Output --> %s\n", rvr);
}

int count(char* str) {
    int count = 0;
    char x[]="\0";
    char *xptr = x;

    while (*str != *xptr) {
        if (*str == 'a' || *str == 'e' || *str == 'o' || *str == 'i' || *str == 'u' || *str == 'A' || *str == 'E' || *str == 'O' || *str == 'I' || *str == 'U') {
            count++;
        }
        str++;
    }
    return count;
}

int main () {
    reverse("deS");
    printf("count output --> %d\n",count("deS"));
    reverse("McMaster");
    printf("count output --> %d\n",count("McMaster"));
    reverse("Josi levu n23d");
    printf("count output --> %d\n",count("Josi levu n23d"));
    return 0;
}