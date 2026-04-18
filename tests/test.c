#include <stdio.h>
#define ANALIB_IMPLEMENTATION
#include "../analib.h"

int sum(int x, int y) { return x + y; }

void test1(void) {
    int x = sum(6, 6);
    AL_assert(x == 12, true);
}
void test2(void) {
    int x = sum(7, 6);
    AL_assert(x == 13, true);
}
void test3(void) {
    int sum_return = sum(1, 6);
    AL_assert(sum_return == 25, false);
}

int main(void) {
    AL_log("Initiating tests...");
    test1();
    test2();
    test3();
    AL_log("Finished with tests %d, %d and %d.", 1, 2, 3);
    int tests_left_to_add = 3;
    AL_todo("add %d more tests", tests_left_to_add);
    return 0;
}
