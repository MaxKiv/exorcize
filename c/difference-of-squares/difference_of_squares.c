#include "difference_of_squares.h"

unsigned int square_of_sum(unsigned int number) {
  unsigned int out = 0;
  while (number)
    out += number--;

  return out * out;
}

unsigned int sum_of_squares(unsigned int number) {
  unsigned int out = 0;
  while (number) {
    out += (number * number);
    --number;
  }

  return out;
}

unsigned int difference_of_squares(unsigned int number) {
  return square_of_sum(number) - sum_of_squares(number);
}
