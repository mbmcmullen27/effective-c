#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  int status = EXIT_SUCCESS;
  FILE *in;

  struct sigrecord {
    int signum;
    char signame[10];
    char sigdesc[100];
  } sigrec;

  if ((in = fopen("signals.txt", "r")) == NULL) {
    fputs("Cannot open signals.txt file\n", stderr);
    return EXIT_FAILURE;
  }

  do {
    int n = fscanf(in, "%d%9s%*[ \t]%99[^\n]",
      &sigrec.signum, sigrec.signame, sigrec.sigdesc
    );
    if (n == 3) {
      printf(
        "Signal\n  number = %d\n  name = %s\n  description = %s\n\n",
        sigrec.signum, sigrec.signame, sigrec.sigdesc
      );
    } else if (n != EOF) {
      fputs("Failed to match signum, signame or sigdesc\n", stderr);
      status = EXIT_FAILURE;
      break;
    } else {
      break;
    }
  } while (1);

  if (fclose(in) == EOF) {
    fputs("Failed to close file \n", stderr);
    status = EXIT_FAILURE;
  }

  return status;
}
