#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <malloc.h>
#include "safe_mem_lib.h"
#include "safe_str_lib.h" 
#include "safe_lib.h" 

errno_t print_error(errno_t errnum) {
  rsize_t size = strerrorlen_s(errnum);
  char* msg = malloc(size);
  if ((msg != NULL) && (strerror_s(msg, size, errnum) != 0)) {
    fputs(msg, stderr);
    return 0;
  }
  else {
    fputs("unknown error", stderr);
    return ENOMEM;
  }
}

int main(void) {
  print_error(ENOMEM); 
  exit(1);
}
