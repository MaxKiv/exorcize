#include "collatz_conjecture.h"

static int do_step_n(unsigned int n, unsigned int step_num) {
  if (n == 1) {
    return step_num;
  }

  if ((n & 1) == 0) {
    n /= 2;
  } else {
    n = 3 * n + 1;
  }

  return do_step_n(n, ++step_num);
}

int steps(int start) {
  if (start < 1)
    return ERROR_VALUE;

  return do_step_n(start, 0);
}
