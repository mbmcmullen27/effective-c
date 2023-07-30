#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char c[10];
  int i;
  double d;
} widget;

int main(void) {
  widget *p = malloc(sizeof(widget)); 
  if (p == NULL) { 
    return EXIT_FAILURE;
  }
  strcpy(p->c, "01234567");
  p->i = 435;
  p->d = 56.9;

  puts(p->c);
  printf("p->i = %d.\n", p->i);
  return EXIT_SUCCESS;
}
