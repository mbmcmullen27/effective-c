#include "isprime.h"
#include <stdlib.h>

static long long power(long long x, unsigned long long y, long long p) {
  long long result = 1;
  x %= p;

  while (y) {
    if (y & 1)
      result = (result * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return result;
}

static bool miller_rabin_test(long long d, long long n) {
  long long a = 2 + rand() % (n - 4);
  long long x = power(a, d, n);

  if (x == 1 || x == n - 1)
    return true;

  while (d != n - 1) {
    x = (x * x) % n;
    d *= 2;

    if (x == 1)
      return false;
    if (x == n - 1)
      return true;
  }
  return false;
}

bool is_prime(long long n, unsigned k) {
  if (n <= 1 || n == 4)
    return false;
  if (n <= 3)
    return true;

  long long d = n - 1;
  while (d % 2 == 0)
    d /= 2;

  for (; k != 0; --k) {
    if (!miller_rabin_test(d, n))
      return false;
  }
  return true;
}
