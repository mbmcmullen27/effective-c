#include <errno.h>
#include <limits.h>

errno_t do_stuff(signed long value) {
    if ((value < SCHAR_MIN) || (value > SCHAR_MAX)) {
        return ERANGE;
    }

    signed char sc = (signed char)value;
}
