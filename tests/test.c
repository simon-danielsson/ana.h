#include <stdio.h>
#define ANALIB_IMPLEMENTATION
#include "../analib.h"

int sum(int x, int y) {
    AL_db_log("summing operation");
    return x + y;
}

int main(void) {

    // int z = sum(5, 4);

    printf("%d\n", AL_cmp_min(5, 6));
    printf("%.2f\n", AL_cmp_min(5.2, 6.8));
    printf("%d\n", AL_cmp_max(5, 6));
    printf("%.2f\n", AL_cmp_max(5.2, 6.8));
    printf("%.2f\n", AL_cmp_max(5.2, 6.8));
    AL__intern_db_genmsg("WARNING", "this is a warning", __FILE_NAME__, __LINE__,
            __func__);
    // AL_db_log("This is something I want to log");
    // AL_db_todo("this is yet to be done");
    return 0;
}
