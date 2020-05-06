#include <stdio.h>

//gcc -fopenmp openmp_test.c
int just_main() {

#pragma omg parallel
    printf("hello omp___c");

    return 0;
}