#include <stdio.h>
#define ANALIB_IMPLEMENTATION
#include "../analib.h"

int main(void) {
    printf("%d\n", AL_cmp_min(5, 6));
    printf("%.2f\n", AL_cmp_min(5.2, 6.8));
    printf("%d\n", AL_cmp_max(5, 6));
    printf("%.2f\n", AL_cmp_max(5.2, 6.8));
    // AL_db_assert(5 == 6);
    // AL_db_log("This is something I want to log");
    // AL_db_todo("this is yet to be done");
    return 0;
}
