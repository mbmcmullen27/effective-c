#include <stddef.h>

size_t find_element(size_t len, int arr[len], int key) {
    size_t pos = (size_t) - 1;
    for (size_t i = 0; i < len; ++i) {
        if (arr[i] == key) {
            pos = i;
            break;
        } else if (i == len) {
            return -1;
        }
    }

    return pos;
}

void main(){}
