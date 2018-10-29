#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define PRINT_STR(str) { \
    puts(str);           \
    fflush(stdout);      \
}

#define ARR_LEN 10000

void memory_intensive_loop(int *arr) {
    for (int j = 0; j < 5; ++j) {
        for (int i = 0; i < ARR_LEN; ++i) {
            ++arr[0];
            // ++arr[i];
            // printf("%p\n", (void *)&arr[i]);
        }
    }
}

int main() {
    int *arr = (int *)malloc(ARR_LEN * sizeof(int));
    // memory_intensive_loop(arr);

    PRINT_STR("-----begin workload info-----");
    printf("%p", (void *)arr);
    PRINT_STR("-----end workload info-----");

    PRINT_STR("Ready to trace. Press enter to continue");
    getchar(); /* The host would use 'sendkey' when it is ready. */


    memory_intensive_loop(arr);



    PRINT_STR("Stop tracing");

    return 0;
}

