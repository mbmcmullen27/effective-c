#include "PrimalityUtilities/isprime.h"
#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Print command line help text. */
static void print_help(void) {
  puts("primetest num1 [num2 num3 ... numN]");
  puts("");
  puts("Tests positive integers for primality. Supports testing numbers in the "
       "range [1-9223372036854775807].");
}

/* Attempts to convert the given textual argument into an integer value.
Returns true on success, or false on failure. */
static bool convert_arg(const char *arg, long long *val) {
  assert(val && "expected val to be nonnull");
  char *end;

  // strtoll returns an in-band error indicator, so set errno before the call.
  errno = 0;
  *val = strtoll(arg, &end, 10);

  // Check for failures where the call returns a sentinel value and sets errno.
  if ((*val == LLONG_MIN || *val == LLONG_MAX) && errno)
    return false;
  if (*val == 0 && errno)
    return false;
  if (end == arg)
    return false;

  // If we got here, we were able to convert the argument. However, we only
  // want to allow positive integer values, so we can reject values <= 0 here.
  if (*val <= 0)
    return false;

  return true;
}

/* Walk over the command line arguments, converting text representing a number
to be tested into an integral value. Return an array of numbers to process to
the caller, or print the help text on error. The results from this call should
be passed to free(). The number of arguments converted is written into the
num_args parameter. */
static long long *convert_command_line_args(int argc, const char *argv[],
                                            size_t *num_args) {
  assert(num_args && "expected num_args to be nonnull");
  *num_args = 0;

  if (argc <= 1) {
    /* No command line arguments given (the first argument is the name of the
    program being executed). */
    print_help();
    return NULL;
  }

  /* We know the maximum number of arguments the user could have passed, so
  allocate an array large enough to hold all of the elements. Subtract one for
  the program name itself. If the allocation fails, treat it as a failed
  conversion (it is okay to call free(NULL)). */
  long long *args = (long long *)malloc(sizeof(long long) * (argc - 1));
  bool failed_conversion = args == NULL;
  for (int i = 1; i < argc && !failed_conversion; ++i) {
    /* Attempt to convert the argument into an integer. If we couldn't convert
    it, set failed_conversion to true. */
    long long one_arg;
    failed_conversion |= !convert_arg(argv[i], &one_arg);
    args[i - 1] = one_arg;
  }

  if (failed_conversion) {
    // Free the array, print the help, and bail out.
    free(args);
    print_help();
    return NULL;
  }

  *num_args = argc - 1;
  return args;
}

int main(int argc, const char *argv[]) {
  size_t num_args;
  long long *vals = convert_command_line_args(argc, argv, &num_args);

  assert((vals || !num_args) && "either should have values or no arguments");
  if (!vals)
    return EXIT_FAILURE;

  for (size_t i = 0; i < num_args; ++i) {
    printf("%lld is %s", vals[i],
           is_prime(vals[i], 100) ? "probably prime" : "not prime");
  }

  free(vals);
  return EXIT_SUCCESS;
}
