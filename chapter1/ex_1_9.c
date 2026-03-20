#include <stdio.h>

int main() {
    int c, last;

    last = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' || last != ' ')
            putchar(c);
        last = c;
    }
}