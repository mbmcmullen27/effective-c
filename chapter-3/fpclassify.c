#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const char *show_classification(double x) {
  switch(fpclassify(x)) {
    case FP_INFINITE:  return "Inf";
    case FP_NAN:       return "NaN";
    case FP_NORMAL:    return "normal";
    case FP_SUBNORMAL: return "subnormal";
    case FP_ZERO:      return "zero";
    default:           return "unknown";
  }
}

int main() {
  double d;
  d = 9.0/0.0;
  puts(show_classification(d));
  d = 9.0 + NAN;
  puts(show_classification(d));
  // add your own
  return EXIT_SUCCESS;
}
