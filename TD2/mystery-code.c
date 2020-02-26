#include <stdio.h>
#include <stdlib.h>
#define NUM_STEPS 8

typedef struct {double r; double i;} complex_t;

int main(int argc, char **argv) {
    int i;
    complex_t *complexArray;
    complex_t oddSum = {.0, .0}, evenSum = {.0, .0};

    complexArray = malloc(NUM_STEPS * sizeof(*complexArray));

    for (i = 0; i != NUM_STEPS; ++i) {
        complexArray[i].r = i + 4;
        complexArray[i].i = 3 * i;
    }

    for (i = 0; i != NUM_STEPS; i += 2) {
        evenSum.r += complexArray[i].r;
        evenSum.i += complexArray[i].i;
    }

<<<<<<< HEAD
    for (i = 0; i != NUM_STEPS; i += 2) {
=======
    for (i = 1; i < NUM_STEPS; i += 2) {
>>>>>>> 42dbe9b9197f8d031199fe5e1c48a6001e87a30a
        oddSum.r += complexArray[i].r;
        oddSum.i += complexArray[i].i;
    }

    printf ("Sums are: (%f, %f) & (%f, %f)\n",
        evenSum.r, evenSum.i, oddSum.r, oddSum.i);

    return 0;
}
