#include <assert.h>
#include <stdio.h>
#include <limits.h>

void clear_stdin(void) {
    int c;

    do {
        c = getchar();
        static_assert(UCHAR_MAX < UINT_MAX, "FIO34-C violation");
    } while (c != EOF);
}

int main(){}
