#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int simpleParse(const char *exp);

int simpleParse(const char *exp) {
    //copying equation to manipulate
    int equation_size = strlen(exp)+1;
    char *equation = malloc(equation_size*sizeof(char));
    strcpy(equation,exp);
    char *token = strtok(equation," ");

    //Initializing Arrays
    long int *numbers = calloc(8,sizeof(long int));
    long int *numbers_start = numbers;

    char *operators = calloc(7,sizeof(char));
    int operators_size = 0;
    char *operators_start = operators;

    //Setting arrays to store values
    while (token != NULL) {

        if(isdigit(*token)) {
            *numbers = strtol(token,'\0',10);
            numbers++;
        }
        else {
            *operators = *token;
            operators_size++;
            operators++;
        }
        token = strtok(NULL, " ");
    }
    numbers = numbers_start;
    operators = operators_start;

    //Checking for *, /, and %
    for (int i=0; i<operators_size; i++) {

        if (operators[i] == '*') {
            numbers[i+1]=numbers[i]*numbers[i+1];
            numbers[i] = 9999;
        }
        else if (operators[i] == '/') {
            numbers[i+1]=numbers[i]/numbers[i+1];
            numbers[i] = 9999;
        }
        else if (operators[i] == '%') {
            numbers[i+1]=numbers[i]%numbers[i+1];
            numbers[i] = 9999;
        }
    }

    //Checking for + and -
    for (int j=0; j<operators_size;j++) {
        int k = 0;
        if (operators[j]=='+') {
            while (numbers[j+k+1]==9999) {
                k++;
            }
            numbers[j+k+1]=numbers[j]+numbers[j+k+1];
            numbers[j] = 9999;
        }
        else if (operators[j]=='-') {
            while (numbers[j+k+1]==9999) {
                k++;
            }
            numbers[j+k+1]=numbers[j]-numbers[j+k+1];
            numbers[j] = 9999;
        }
    }

    float final_value = numbers[operators_size];
    free(numbers);
    free(operators);
    free(equation);
    return final_value;
}

int main() {
    char exp1[] = "1 + 1";
    char exp2[] = "3 + 7 - 4 * 1";
    char exp3[] = "9 * 13 / 2 + 18 * 110 - 812 % 97 + 3";
    
    printf("%s = %d\n", exp1, simpleParse(exp1));
    printf("%s = %d\n", exp2, simpleParse(exp2));
    printf("%s = %d\n", exp3, simpleParse(exp3));
}