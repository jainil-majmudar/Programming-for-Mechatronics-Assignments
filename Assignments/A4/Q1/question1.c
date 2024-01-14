#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

float fkgrade(char str[]);

float fkgrade(char str[]) {
    float sentences = 0;
    float syllables = 0;
    float words = 0;
    float result = 0;
    char *ptr = str;
    char *ptr2 = str;
    int size = strlen(str);

    if (*ptr == '\0') {
        words = 0;
    }
    
    while (*ptr != '\0') {
        if (*ptr == '.' || *ptr == '!' || *ptr == '?') {
            sentences += 1;
        }
        ptr++;
    }

    for (int i =0; i < size; i++) {
            if(str[i]=='\'') {
                continue;
            } else if((ispunct(str[i])!=0 || str[i]==' ') && ((int)str[i-1] >= 65 && (int)str[i-1]<=122) || ((int)str[i-1] >= 48 && (int)str[i-1]<=57)) {
                words++;
            }
        }

    while (*ptr2 != '\0') {
        if (*ptr2 == 'a' || *ptr2 == 'e' || *ptr2 == 'i' || *ptr2 == 'o' || *ptr2 == 'u' || *ptr2 == 'A' || *ptr2 == 'E' || *ptr2 == 'I' || *ptr2 == 'O' || *ptr2 == 'U') {
            syllables += 1;
            char *ptrj = ptr2 + 1;
            while (*ptrj == 'a' || *ptrj == 'e' || *ptrj == 'i' || *ptrj == 'o' || *ptrj == 'u' || *ptrj == 'A' || *ptrj == 'E' || *ptrj == 'I' || *ptrj == 'O' || *ptrj == 'U') {
                ptrj++;
            }
            ptr2 = ptrj;
        }
        ptr2++;
    }

    if (sentences != 0 && words != 0) {
        result = (0.39 * (words / sentences)) + (11.8 * (syllables / words)) - (15.59);
    } else {
        result = -1;
    }
    return result;
}

int main() {
    char plato[] = "He who is the real tyrant, whatever men may think, is the real slave, and is obliged to practise the greatest adulation and servility, and to be the flatterer of the vilest of mankind.  He has desires which he is utterly unable to satisfy, and has more wants than any one, and is truly poor, if you know how to inspect the whole soul of him: all his life long he is beset with fear and is full of convulsions and distractions, even as the State which he resembles: and surely the resemblance holds?";

    char aurelius[] = "Nothing pertains to human beings except what defines us as human.  No other things can be demanded of us.  They aren't proper to human nature, nor is it incomplete without them.  It follows that they are not our goal, or what helps us reach it -- the good.  If any of them were proper to us, it would be improper to disdain or resist it.  If the things themselves were good, it could hardly be good to give them up.  But in reality, the more we deny ourselves such things (and things like them) -- or are deprived of them involuntarily, even -- the better we become.";

    char descartes[] = "I suppose, accordingly, that all the things which I see are false (fictitious); I believe that none of those objects which my fallacious memory represents ever existed; I suppose that I possess no senses; I believe that body, figure, extension, motion, and place are merely fictions of my mind.  What is there, then, that can be esteemed true?  Perhaps this only, that there is absolutely nothing certain.";
    
    char empty[] = "";
    
    printf("Plato...\nexpected sentences = 2\nexpected words = 94\n  expected syllables = 135\n");
    float out = fkgrade(plato);
    printf("> Reading Level = %f\n", out);
    printf("Marcus Aurelius...\n  expected sentences = 7\n   expected words = 104\n    expected syllables = 153\n");
    out = fkgrade(aurelius);
    printf("> Reading Level = %f\n", out);
    printf("Rene Descartes...\n  expected sentences = 3\n   expected words = 67\n    expected syllables = 113\n");
    out = fkgrade(descartes);
    printf("> Reading Level = %f\n", out);
    
    out = fkgrade(empty);
    printf("> Reading Level = %f\n", out);
}