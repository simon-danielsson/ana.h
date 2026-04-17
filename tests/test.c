#include <stdio.h>
// #define AL_DEBUG_OFF
#define ANALIB_IMPLEMENTATION
#include "../analib.h"

int sum(int x, int y) {
    AL_db_log("summing operation");
    return x + y;
}

int main(void) {
    printf("%d\n", AL_cmp_min(5, 6));
    printf("%.2f\n", AL_cmp_min(5.2, 6.8));
    printf("%d\n", AL_cmp_max(5, 6));
    printf("%.2f\n", AL_cmp_max(5.2, 6.8));
    printf("%.2f\n", AL_cmp_max(5.2, 6.8));

    AL_db_assert(5 == 5, true);
    AL_db_assert(2 == 5, false);

    AL_db_log("This is something I want to log");
    AL_db_todo("this is yet to be done");
    return 0;
}
