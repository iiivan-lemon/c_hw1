#include <gtest/gtest.h>


extern "C" {
#include "prog.h"
#include "input_data.h"
}

#define ITERATION_NUMBER 10
#define PATH "text.txt"
#define SIZE_CONDITION 100000
#define STRESS_ITERATION_NUMBER 3


TEST(TestConsistent1, Bisector) {
    auto *a = (double *) malloc(SIZE_CONDITION * sizeof(double));
    for (size_t i = 0; i < SIZE_CONDITION; ++i) {
        a[i] = i;
    }
    res_coef *expect_res = (res_coef *) malloc(sizeof(res_coef));
    expect_res->k = 1;
    expect_res->b = 0;
    res_coef *res = linear_regress(a, SIZE_CONDITION);
    EXPECT_EQ(res->k, expect_res->k);
    EXPECT_EQ(res->b, expect_res->b);
    free(res);
    free(expect_res);
    free(a);
}

TEST(TestConsistent2, RandomElems) {
    EXPECT_TRUE(write_file(PATH, SIZE_CONDITION) == EXIT_SUCCESS);
    double *a = read_file(PATH);
    EXPECT_TRUE(a != nullptr);
    FILE *f = fopen("../data/consistent_res.txt", "w+");
    EXPECT_FALSE(f == nullptr);

    for (int i = 0; i < STRESS_ITERATION_NUMBER; ++i) {
        res_coef *res = linear_regress(a, rand() % SIZE_CONDITION);
        fprintf(f, "%f %f ", res->k, res->b);
        free(res);
    }

    fclose(f);

    free(a);
}

TEST(time, time) {
    double general_time = 0;
    double average_time;

    struct timespec start, finish;

    size_t times = ITERATION_NUMBER;
    double *a = read_file(PATH);
    for (size_t i = 0; i < times; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &start);

        res_coef *res = linear_regress(a, SIZE_CONDITION);

        clock_gettime(CLOCK_MONOTONIC, &finish);
        double elapsed = (finish.tv_sec - start.tv_sec);
        elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
        general_time += elapsed;

        free(res);
    }


    average_time = general_time / times;
    FILE *f = fopen("../data/consistent_time.txt", "w+");
    fprintf(f, "%lf", average_time);
    fclose(f);
    free(a);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
