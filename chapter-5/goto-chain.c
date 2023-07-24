#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <memory.h>

typedef struct sigrecord {
  int signum;
  char signame[20];
  char sigdesc[100];
} sig_desc_type;


int main(void) {
  int ret_val = 0; // Initially assume a successful return value
 
  FILE *file1 = fopen("a_file", "w");
  if (file1 == NULL) {
    ret_val = -1;
    goto FAIL_FILE1;
  }
 
  FILE *file2 = fopen("another_file", "w");
  if (file2 == NULL) {
    ret_val = -1;
    goto FAIL_FILE2;
  }
 
  size_t size = sizeof(sig_desc_type);
  sig_desc_type *obj = malloc(size);
  if (obj == NULL) {
    ret_val = -1;
    goto FAIL_OBJ;
  }
 
  // Operate on allocated resources
  if (fwrite(obj, size, 1, file2) != 1) {
    fputs("Cannot write sigrec30 to signals.txt file\n", stderr);
    ret_val = EXIT_FAILURE;
  }
 
  // Clean up everything
  free(obj);
FAIL_OBJ:  // Otherwise, close only the resources we opened
  fclose(file2);
FAIL_FILE2:
  fclose(file1);
FAIL_FILE1:
  return ret_val;
}
