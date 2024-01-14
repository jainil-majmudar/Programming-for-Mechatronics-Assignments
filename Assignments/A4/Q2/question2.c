#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DMY_MonthDY(char *buffer, const char *str);
void MonthDY_DMY(char *buffer, const char *str);

void DMY_MonthDY(char *buffer, const char *str) {
    int month, day, year = 0;
    sscanf(str, "%d/%d/%d", &day, &month, &year);
    char newstr[10];
    if (*(str + 3) == '0' && *(str + 4) == '1') {
        strcpy(newstr, "January  ");
    }
    if (*(str + 3) == '0' && *(str + 4) == '2') {
        strcpy(newstr, "February ");
    }
    if (*(str + 3) == '0' && *(str + 4) == '3') {
        strcpy(newstr, "March    ");
    }
    if (*(str + 3) == '0' && *(str + 4) == '4') {
        strcpy(newstr, "April    ");
    }
    if (*(str + 3) == '0' && *(str + 4) == '5') {
        strcpy(newstr, "May      ");
    }
    if (*(str + 3) == '0' && *(str + 4) == '6') {
        strcpy(newstr, "June     ");
    }
    if (*(str + 3) == '0' && *(str + 4) == '7') {
        strcpy(newstr, "July     ");
    }
    if (*(str + 3) == '0' && *(str + 4) == '8') {
        strcpy(newstr, "August   ");
    }
    if (*(str + 3) == '0' && *(str + 4) == '9') {
        strcpy(newstr, "September");
    }
    if (*(str + 3) == '1' && *(str + 4) == '0') {
        strcpy(newstr, "October  ");
    }
    if (*(str + 3) == '1' && *(str + 4) == '1') {
        strcpy(newstr, "November ");
    }
    if (*(str + 3) == '1' && *(str + 4) == '2') {
        strcpy(newstr, "December ");
    }
    sprintf(buffer, "%s %2d, %4d", newstr, day, year);
}

void MonthDY_DMY(char *buffer, const char *str) {
    int month, day, year = 0;
    char newstr[10];
    sscanf(str, "%s %d, %d", newstr, &day, &year);

    if (strcmp(newstr, "January") == 0) {
        month = 1;
    }
    if (strcmp(newstr, "February") == 0) {
        month = 2;
    }
    if (strcmp(newstr, "March") == 0) {
        month = 3;
    }
    if (strcmp(newstr, "April") == 0) {
        month = 4;
    }
    if (strcmp(newstr, "May") == 0) {
        month = 5;
    }
    if (strcmp(newstr, "June") == 0) {
        month = 6;
    }
    if (strcmp(newstr, "July") == 0) {
        month = 7;
    }
    if (strcmp(newstr, "August") == 0) {
        month = 8;
    }
    if (strcmp(newstr, "September") == 0) {
        month = 9;
    }
    if (strcmp(newstr, "October") == 0) {
        month = 10;
    }
    if (strcmp(newstr, "November") == 0) {
        month = 11;
    }
    if (strcmp(newstr, "December") == 0) {
        month = 12;
    }
    sprintf(buffer, "%.2d/%.2d/%.4d", day, month, year);
}

int main(){
char format1[12][11] = { "01/01/1970"
                       , "10/02/1763"
                       , "15/03/0044"
                       , "18/04/1982"
                       , "05/05/1789"
                       , "06/06/1944"
                       , "01/07/1867"
                       , "03/08/1492"
                       , "02/09/1945"
                       , "24/10/1917"
                       , "11/11/1918"
                       , "08/12/1980"
                       };
char format2[12][19] = { "January    1, 1970" // First Day of History (according to computers)
                       , "February  10, 1763" // France cedes Canada to England
                       , "March     15,   44" // Assassination of Julius Caesar
                       , "April     18, 1982" // Canada Achieves Sovereignty 
                       , "May        5, 1789" // French Revolution
                       , "June       6, 1944" // D-Day Landings of WWII
                       , "July       1, 1867" // Confederation of Canada
                       , "August     3, 1492" // Christopher Columbus Sets Sail for the Americas
                       , "September  2, 1945" // WWII Surrender of Japan
                       , "October   24, 1917" // October Revolution (Julian Calendar)
                       , "November  11, 1918" // WWI Armistice
                       , "December   8, 1980" // Murder of John Lennon
                       };
    
    char buffer1[12][11];
    char buffer2[12][19];
    
    printf ("-- DD\\MM\\YY to Month DD, YYYY\n");
    for (int i = 0; i < 12; i++) {
        printf("%s\n", format1[i]);
        DMY_MonthDY(buffer2[i], format1[i]);
        printf("-> \"%s\"\n", buffer2[i]);
    }
    
    
    printf ("\n\n-- Month DD, YYYY to DD\\MM\\YY\n");
    for (int i = 0; i < 12; i++) {
        printf("%s\n", format2[i]);
        MonthDY_DMY(buffer1[i], format2[i]);
        printf("-> \"%s\"\n", buffer1[i]);
    }
}