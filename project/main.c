#include "input_data.h"
#include "prog.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return EXIT_FAILURE;
    }
    char *path = argv[1];
    size_t size = strtol(argv[2], NULL, 10);
    if (write_file(path, size) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }

    double *a = read_file(path);
    if (a == NULL) {
        return EXIT_FAILURE;
    }

    res_coef *res = linear_regress(a, size);
    free(a);

    if (res == NULL) {
        return EXIT_FAILURE;
    }
    printf("k = %f  b = %f\n", res->k, res->b);
    free(res);

    return 0;
}

