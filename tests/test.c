#define ANALIB_IMPLEMENTATION
#include "../analib.h"

int main(void) {
    AL_db_assert(5 == 6);
    AL_db_log("This is something I want to log");
    AL_db_todo("this is yet to be done");
    return 0;
}
