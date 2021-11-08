#include <gtest/gtest.h>

extern "C" {
#include "prog.h"
#include "input_data.h"
}

#define BAD_SIZE 1
#define PATH "test.txt"
#define SIZE_CONDITION 100000
#define STRESS_ITERATION_NUMBER 3

TEST(TestResults, Bisector) {
    double *a = new double[SIZE_CONDITION];
    for (size_t i = 0; i < SIZE_CONDITION; ++i) {
        a[i] = i;
    }
    res_coef expect_res;
    expect_res.k = 1;
    expect_res.b = 0;
    res_coef *res = linear_regress(a, SIZE_CONDITION);
    EXPECT_TRUE(res->k == expect_res.k);
    EXPECT_TRUE(res->b == expect_res.b);
    free(res);
    delete [] a;
}


TEST(BadValueParallel, BadSize) {
    double *a = new double[BAD_SIZE];
    for (size_t i = 0; i < BAD_SIZE; ++i) {
        a[i] = i;
    }
    res_coef *res = linear_regress(a, BAD_SIZE);
    EXPECT_TRUE(res == nullptr);
    free(res);
    delete [] a;
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
