#include <math.h>
#include <stdio.h>

#define sin(X) _Generic((X), \
    float: sinf, \
    double: sin, \
    long double: sinl \
)(X)

int main(void) {
    float f = sin(1.5708f);
    double d = sin(3.14159);
    printf("%f\n", f);
    printf("%lf\n", d);
}
