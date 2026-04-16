#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define ANALIB_IMPLEMENTATION
#include "../analib.h"

int main(void) {
    // AL_db_assert(8 != 8);
    char s[] = "hello";
    printf("%d", AL_str_len(s));
    // AL_db_log("initializing conversion");
    return 0;
}
