#include <stdio.h>

#define MAXHIST 15                                  // max lenght of histogram
#define MAXWORD 11                                  // max lenght of word
#define IN 1                                        // inside a word
#define OUT 0                                       // outside a word

// print horizontal histogram
int main() {
    int c, i, nc, state;
    int len;                                        // max lenght of each bar
    int maxvalue;                                   // max value of wl[]
    int ovrflow;                                    // number of overflow words
    int wl[MAXWORD];                                // word lenght counters

    state = OUT;
    nc = 0;                                         // number of chars in a word
    ovrflow = 0;                                    // number of words >= MAXWORD
    for (i = 0; i < MAXWORD; ++i)
        wl[i] = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (nc > 0)
                if (nc < MAXWORD)
                    ++wl[nc];
                else
                    ++ovrflow;
            nc = 0;
        } else if (state == OUT) {
            state = IN;
            nc = 1;                                 // beginning of a new word
        } else 
            ++nc;                                   // inside a word
    }
    if (nc > 0) {
    if (nc < MAXWORD)
        ++wl[nc];
    else
        ++ovrflow;
    }

    maxvalue = 0;
    for (i = 1; i < MAXWORD; ++i)
        if (wl[i] > maxvalue)
            maxvalue = wl[i];

    for (i = 1; i < MAXWORD; ++i) {
        printf("%5d - %5d : ", i, wl[i]);
        if (wl[i] > 0) {
            if ((len = wl[i] * MAXHIST / maxvalue) <= 0)
                len = 1;
        } else
            len = 0;
        while (len > 0) {
            putchar('*');
            --len;
        }
        putchar('\n');
    }
    if (ovrflow > 0)
        printf("There are %d words >= %d", ovrflow, MAXWORD);
}