#include <limits.h>
#include <stdio.h>
#include <stdio.h>

int absolute_value(int a) {
    if (a < 0) {
        return -(unsigned)a;
    }
    return a;
}

int main(void) {
    printf("INT_MAX = %i\n", INT_MAX);
    printf("INT_MIN = %i\n", INT_MIN);
    printf("|INT_MIN| = %u\n", absolute_value(INT_MIN));
    return 0;
}
