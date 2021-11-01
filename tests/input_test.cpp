#include <gtest/gtest.h>

extern "C" {
#include "input_data.h"
}

#define PATH "text.txt"
#define SIZE_CONDITION 100


TEST(TestInputData, RandomArraySize) {
    size_t size_test = SIZE_CONDITION;

    EXPECT_TRUE(write_file(PATH, size_test) == EXIT_SUCCESS);
    double *a = read_file(PATH);
    EXPECT_TRUE(a != nullptr);

    size_t i = 0;
    FILE *f;
    f = fopen(PATH, "r");
    while (fscanf(f, "%lf", &a[i]) > 0) {
        i++;
    }
    fclose(f);
    free(a);
    EXPECT_TRUE(i == size_test);
}



