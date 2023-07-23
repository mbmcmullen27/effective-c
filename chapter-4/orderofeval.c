#include <stdio.h>
#include <stdlib.h>

int glob; // static storage init to 0

int max(int a, int b) {
  return a > b ? a : b; 
}

int f(void) {
  return glob + 10;
}
int g(void) {
  glob = 42;
  return glob;
}

int main(void) {
  int max_value = max(f(), g());
  printf("max_value = %d.\n", max_value);
}
