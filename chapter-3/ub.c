#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    uint16_t a = 0xffffu;
    uint16_t b = 0xffffu;
    printf("a*b=%d\n", a*b);
    if (a * b < 0) printf("%d is negative\n", a * b);
    else printf("%d is not negative\n", a * b);
}
