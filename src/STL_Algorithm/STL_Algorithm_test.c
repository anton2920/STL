#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>

#include "../STL_Headers/STL/STL_Algorithm.h"

#define N (100000)
#define LIM (500000)

void rand_array(int *, int, int);
void demo_basic_sort(int *, __bool);
void demo_adv_sort(int *, __bool);
__bool check_sorted(const int *);

main() {

    /* Initializing variables */
    auto int i;
    auto int *source = malloc(N * sizeof(int));
    __bool is_print = __false;

    srand(time(NULL) / 2);

    if (source == NULL) {
        return -1;
    }

    /* I/O flow */
    rand_array(source, N, LIM);
    if (is_print) {
        printf("Source array: \t\t");
        for (i = 0; i < N; ++i) {
            printf("%d ", *(source + i));
        }
        fflush(stdout);
    }

    /* Main part */
    if (N <= 50000) {
        demo_basic_sort(source, is_print);
    }
    demo_adv_sort(source, is_print);

    /* Final output */
    printf("\n");

    /* Returning value */
    return 0;
}

void rand_array(int *a, int n, int lim) {

    /* Initializing variables */
    auto int i;

    /* Main part */
    for (i = 0; i < n; ++i) {
        *(a + i) = rand() % (2 * lim + 1) - lim;
        /* *(a + i) = lim--; */
    }
}

void demo_basic_sort(int *source, __bool is_print) {

    /* Initializing variables */
    auto int i;
    auto struct timeval stop, start;
    auto double time_in_mill, time_in_mill2;

    auto *a = malloc(N * sizeof(int));

    if (a == NULL) {
        return;
    }

    /* Main part */
    memcpy((void *) a, (const void *) source, N * sizeof(int));
    gettimeofday(&start, NULL);
    STL_bubble_sort((void *) a, N, sizeof(int), STL_inumcmp);
    gettimeofday(&stop, NULL);

    time_in_mill = (start.tv_sec) * 1000 + (double) (start.tv_usec) / 1000;
    time_in_mill2 = (stop.tv_sec) * 1000 + (double) (stop.tv_usec) / 1000;

    printf("\n\n%s\tBubble sort: \t\t", check_sorted(a) ? "OK!" : "FAIL!");
    if (is_print) {
        for (i = 0; i < N; ++i) {
            printf("%d ", *(a + i));
        }
    }
    printf("\nTime: %.2lf ms\n", time_in_mill2 - time_in_mill);
    fflush(stdout);

    memcpy((void *) a, (const void *) source, N * sizeof(int));
    gettimeofday(&start, NULL);
    STL_selection_sort((void *) a, N, sizeof(int), STL_inumcmp);
    gettimeofday(&stop, NULL);

    time_in_mill = (start.tv_sec) * 1000 + (double) (start.tv_usec) / 1000;
    time_in_mill2 = (stop.tv_sec) * 1000 + (double) (stop.tv_usec) / 1000;

    printf("\n%s\tSelection sort: \t", check_sorted(a) ? "OK!" : "FAIL!");
    if (is_print) {
        for (i = 0; i < N; ++i) {
            printf("%d ", *(a + i));
        }
    }
    printf("\nTime: %.2lf ms\n", time_in_mill2 - time_in_mill);
    fflush(stdout);

    memcpy((void *) a, (const void *) source, N * sizeof(int));
    gettimeofday(&start, NULL);
    STL_insertion_sort((void *) a, N, sizeof(int), STL_inumcmp);
    gettimeofday(&stop, NULL);

    time_in_mill = (start.tv_sec) * 1000 + (double) (start.tv_usec) / 1000;
    time_in_mill2 = (stop.tv_sec) * 1000 + (double) (stop.tv_usec) / 1000;

    printf("\n%s\tInsertion sort: \t", check_sorted(a) ? "OK!" : "FAIL!");
    if (is_print) {
        for (i = 0; i < N; ++i) {
            printf("%d ", *(a + i));
        }
    }
    printf("\nTime: %.2lf ms\n", time_in_mill2 - time_in_mill);
    fflush(stdout);

    memcpy((void *) a, (const void *) source, N * sizeof(int));
    gettimeofday(&start, NULL);
    STL_shell_sort((void *) a, N, sizeof(int), STL_inumcmp);
    gettimeofday(&stop, NULL);

    time_in_mill = (start.tv_sec) * 1000 + (double) (start.tv_usec) / 1000;
    time_in_mill2 = (stop.tv_sec) * 1000 + (double) (stop.tv_usec) / 1000;

    printf("\n%s\tShell sort: \t\t", check_sorted(a) ? "OK!" : "FAIL!");
    if (is_print) {
        for (i = 0; i < N; ++i) {
            printf("%d ", *(a + i));
        }
    }
    printf("\nTime: %.2lf ms\n", time_in_mill2 - time_in_mill);
    fflush(stdout);

    free(a);
}

void demo_adv_sort(int *source, __bool is_print) {

    /* Initializing variables */
    auto int i;
    auto struct timeval stop, start;
    auto double time_in_mill, time_in_mill2;

    auto *a = malloc(N * sizeof(int));

    if (a == NULL) {
        return;
    }

    /* Main part */
    memcpy((void *) a, (const void *) source, N * sizeof(int));
    gettimeofday(&start, NULL);
    STL_quick_sort((void *) a, N, sizeof(int), STL_inumcmp);
    gettimeofday(&stop, NULL);

    time_in_mill = (start.tv_sec) * 1000 + (double) (start.tv_usec) / 1000;
    time_in_mill2 = (stop.tv_sec) * 1000 + (double) (stop.tv_usec) / 1000;

    printf("\n%s\tQuick sort: \t\t", check_sorted(a) ? "OK!" : "FAIL!");
    if (is_print) {
        for (i = 0; i < N; ++i) {
            printf("%d ", *(a + i));
        }
    }
    printf("\nTime: %.2lf ms\n", time_in_mill2 - time_in_mill);
    fflush(stdout);

    memcpy((void *) a, (const void *) source, N * sizeof(int));
    gettimeofday(&start, NULL);
    qsort((void *) a, N, sizeof(int), STL_inumcmp);
    gettimeofday(&stop, NULL);

    time_in_mill = (start.tv_sec) * 1000 + (double) (start.tv_usec) / 1000;
    time_in_mill2 = (stop.tv_sec) * 1000 + (double) (stop.tv_usec) / 1000;

    printf("\n%s\tqsort (stdlib): \t\t", check_sorted(a) ? "OK!" : "FAIL!");
    if (is_print) {
        for (i = 0; i < N; ++i) {
            printf("%d ", *(a + i));
        }
    }
    printf("\nTime: %.2lf ms\n", time_in_mill2 - time_in_mill);
    fflush(stdout);

    memcpy((void *) a, (const void *) source, N * sizeof(int));
    gettimeofday(&start, NULL);
    STL_merge_sort((void *) a, N, sizeof(int), STL_inumcmp);
    gettimeofday(&stop, NULL);

    time_in_mill = (start.tv_sec) * 1000 + (double) (start.tv_usec) / 1000;
    time_in_mill2 = (stop.tv_sec) * 1000 + (double) (stop.tv_usec) / 1000;

    printf("\n%s\tMerge sort: \t\t", check_sorted(a) ? "OK!" : "FAIL!");
    if (is_print) {
        for (i = 0; i < N; ++i) {
            printf("%d ", *(a + i));
        }
    }
    printf("\nTime: %.2lf ms\n", time_in_mill2 - time_in_mill);
    fflush(stdout);

    free(a);
}

__bool check_sorted(const int *array) {

    /* Initializing variables */
    auto int i;

    /* VarCheck */
    if (N > 10000000) {
        return __true;
    }

    /* Main part */
    for (i = 1; i < N; ++i) {
        if (array[i] < array[i - 1]) {
            return __false;
        }
    }

    /* Returning value */
    return __true;
}