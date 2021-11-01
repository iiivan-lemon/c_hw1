#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input_data.h"

#define DEVIATION 0.1

static size_t numberSize(FILE *input);

int write_file(const char *path, size_t size) {
    if (size < 1) {
        return EXIT_FAILURE;
    }
    FILE *f;
    f = fopen(path, "w");
    if (!f) {
        return EXIT_FAILURE;
    }
    for (size_t i = 0; i < size; ++i) {
        fprintf(f, "%lf ", i + DEVIATION);
    }
    fclose(f);
    return EXIT_SUCCESS;
}

double *read_file(const char *path) {
    FILE *f;
    f = fopen(path, "r");
    if (!f) {
        return NULL;
    }
    size_t size = numberSize(f);
    if (size < 1) {
        fclose(f);
        return NULL;
    }
    double *a = (double *) malloc(size * sizeof(double));
    if (a == NULL) {
        fclose(f);
        return NULL;
    }

    for (size_t i = 0; i < size; ++i) {
        if (fscanf(f, "%lf", &a[i]) != 1) {
            fclose(f);
            free(a);
            return NULL;
        }
    }
    fclose(f);
    return a;
}

static size_t numberSize(FILE *input) {
    if (!input) {
        return 0;
    }
    size_t counter = 0;
    while (1) {
        double value = 0;
        if (fscanf(input, "%lf", &value) == 1)
            counter++;
        else
            break;
    }
    fseek(input, 0, SEEK_SET);
    return counter;
}
