#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int right_shift_int(int si1, int si2) {
  if ( (si2 < 0) || (si2 >= sizeof(int) * CHAR_BIT) ) {
    abort();
  }
  return si1 >> si2;
}

unsigned int right_shift_uint(unsigned int ui1, unsigned int ui2) {
  if (ui2 >= sizeof(unsigned int) * CHAR_BIT) {
    abort();
  }
  return ui1 >> ui2;
}

int main(void) {
  printf("signed right shift = %d.\n", right_shift_int(INT_MAX, 29));
  printf("unsigned right shift = %u.\n", right_shift_uint(UINT_MAX, 30));
}
