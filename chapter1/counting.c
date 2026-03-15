#include <stdio.h>
/* count lines in input */
int main() {
    int c, nl, space, tab;

    nl = 0;
    space = 0;
    tab = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t')
            ++tab; 
        if (c == ' ')
            ++space;
        if (c == '\n')
            ++nl;
    }
    printf("%d %d %d\n", nl, space, tab);
}