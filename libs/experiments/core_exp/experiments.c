#include "experiments.h"

void check_time(void (*sort_func)(int *, size_t),
                void (*generate_func)(int *, size_t),
                size_t size, char *experiment_name) {
    static size_t run_counter = 1;
    static int inner_buffer[100000];
    generate_func(inner_buffer, size);
    printf("Run #%zu | ", run_counter++);
    printf("Name: %s\n", experiment_name);

    double time;
    TIME_TEST({
        sort_func(inner_buffer, size);
        }, time);

    printf("Status: ");
    if (is_ordered(inner_buffer, size)) {
        printf("OK! Time: %.3f s.\n", time);

        char filename[256];
        sprintf(filename, ".data/%s.csv", experiment_name);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf("File open error %s", filename);
            exit(1);
        }

        fprintf(f, "%zu; %.3f\n", size, time);
        fclose(f);
    }
    else {
        printf("Wrong!\n");
        output_array(inner_buffer, size);

        exit(1);
    }
}

void time_experiment() {
    sort_function sorts[] = {
        {bubble_sort,       "bubble sort"},
        {shaker_sort,       "shaker sort"},
        {selection_sort,    "selection sort"},
        {intersection_sort, "intersection sort"},
        {shell_sort,        "shell sort"},
        {heap_sort,         "heap sort"},
        {comb_sort,         "comb sort"},
        {count_sort,        "count sort"},
        {radix_sort,        "radix sort"},
        {merge_sort,        "merge sort"},
        {qsort_int,         "qsort"},
    };
    const unsigned FUNCS_N = ARRAY_SIZE(sorts);

    generation_function generation[] = {
        {generate_random_array,         "random"},
        {generate_ordered_array,        "ordered"},
        {generate_ordered_back_array,   "ordered back"},
    };
    const unsigned CASES_N = ARRAY_SIZE(generation);

    for (size_t size = 10000; size <= 10000; size += 10000) {
        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("Size: %d\n", size);

        for (size_t i = 0; i < FUNCS_N; ++i) {
            for (size_t j = 0; j < CASES_N; ++j) {
                static char filename[128];
                sprintf(filename, "%s_%s_time", sorts[i].name, generation[j].name);
                check_time(sorts[i].sort, generation[j].generate, size, filename);
            }
        }

        printf("\n");
    }
}