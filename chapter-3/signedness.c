#include <limits.h>
#include <stdio.h>

int main(void) {
    unsigned int ui = UINT_MAX;
    signed char c = -1;
    if (c == ui) {
        printf("%i equals %u\n", c, ui);
    }
}
