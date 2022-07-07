#include <stdio.h>
#include <stdlib.h>

int main(void) {
    if (puts("Hello again, world!") == EOF) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}