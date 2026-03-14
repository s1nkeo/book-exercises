#include <stdio.h>

int main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Fahrenheit\tCelsius\n");

    celsius = lower;
    while (celsius <= upper) {
        fahr = celsius * (9.0/5.0) + 32.0;
        printf("%3.0f\t\t%6.0f\n", fahr, celsius);
        celsius = celsius +  step;
    }
}