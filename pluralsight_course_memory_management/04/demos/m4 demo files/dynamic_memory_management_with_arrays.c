/**
 * Wired Brain Coffee - Espresso Machine Metrics
 *
 * This Wired Brain Coffee C program expects one argument from the command line that constitues the size of an array.
 * From this size, it constructs three, variable-length arrays and stores some calculations for metrics of the espresso machine.
 *
 * Currently, when too large a size is passed into the program, a stack overflow occurs as too much memory is being
 * allocated on the stack for the variable-length arrays.
 *
 * In the program below, the exercise is to convert these three variable-length arrays into dynamically allocated arrays
 * such that memory is allocated on the heap instead of the stack.
 *
 **/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DEFAULT_SIZE 1000

double get_random_number();

void gather_metrics(size_t size, double *metric_arr);

int main(int argc, char* argv[]) {

    int array_size = DEFAULT_SIZE;

    if (argc > 1) {
        array_size = strtol(argv[1], NULL, 10);
    }

    if(strtol(argv[1],NULL,10)>2000)
    {
        printf("Sorry the max allowed size is 2000 only \n");
        printf("Thus now the size = Default size of 1000 only \n");
        array_size=DEFAULT_SIZE;
    }

    double *heat_distribution_metrics = (double*)malloc(array_size * sizeof(double)),
        *grinder_metrics              = (double*)malloc(array_size * sizeof(double)),
        *pour_metrics                 = (double*)malloc(array_size * sizeof(double));

    if (!heat_distribution_metrics)
        heat_distribution_metrics = (double*)malloc(DEFAULT_SIZE * sizeof(double));

    // if there is not enough memory on the stack then each pointer will get memory allocated as per
    // the default size only

    if (!grinder_metrics)
        heat_distribution_metrics = (double*)malloc(DEFAULT_SIZE * sizeof(double));

    if (!pour_metrics)
        heat_distribution_metrics = (double*)malloc(DEFAULT_SIZE * sizeof(double));

    double *metrics_matrix[3] = {
        heat_distribution_metrics,
        grinder_metrics,
        pour_metrics
    };

    for(int i = 0; i < 3; i++) {
        gather_metrics(array_size, metrics_matrix[i]);
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < array_size; j++) {
            printf("Row/Col: %d/%d ===> Value: %f\n", i + 1, j + 1, metrics_matrix[i][j]);
        }
    }

    for(int i = 0; i < 3; i++) {
        free(metrics_matrix[i]);
    }

    return 0;
}

void gather_metrics(size_t size, double *metric_arr ) {
    for (int i = 0; i < size; i++) {
        metric_arr[i] = get_random_number();
    }
}

double get_random_number() {
    return rand() / (RAND_MAX / 2.5);
}

// in this program :
// we created an array of 3 pointers namely : heat_distribution_metrics, grinder_metrics, pour_metrics
// each pointer is pointing to a memory block , the size of each memory block accomdating 1000
// double data type values

// even when we assign a contiguous block of memory using pointers, we can iterate over the blocks using the array notation
// thus the array notation also works for pointers and not only for arrays

// metrics_matrix[i][j] : meaning of this is :
// the ith element of metrics_matrix is going to be a pointer
// thus the ith pointer pointing to jth block