#include <stdio.h>

void increment(void) {
  static unsigned int fred = 0;
  fred++;
  printf("%d ", fred);
}
int main(void) {
  for (int i = 0; i < 5; i++) {
    increment();
  }
  return 0;
}
