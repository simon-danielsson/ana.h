#include <stdio.h>
#define ANALIB_IMPLEMENTATION
#include "../analib.h"

int sum(int x, int y) { return x + y; }

void test1(void) {
    int x = sum(6, 6);
    ASSERT(x == 12, true);
}
void test2(void) {
    int x = sum(7, 6);
    ASSERT(x == 13, true);
}
void test3(void) {
    int sum_return = sum(1, 6);
    ASSERT(sum_return == 25, false);
}

int main(void) {
    LOG("Initiating tests...");
    test1();
    test2();
    test3();
    LOG("Finished with tests %d, %d and %d.", 1, 2, 3);
    int tests_left = 5;
    IMPL("add %d more tests", tests_left);
    return 0;
}
