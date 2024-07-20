#include "luhn.h"

#include <stddef.h>
#include <string.h>

bool luhn(const char *num) {
  size_t input_len = strlen(num);
  size_t digit_count = 0;
  size_t running_sum = 0;
  bool is_second_digit = false;

  for (int i = input_len - 1; i >= 0; --i) {
    int current_digit = num[i] - '0';
    if (current_digit >= 0 && current_digit <= 9) {
      ++digit_count;
      if (is_second_digit) {
        current_digit *= 2;
      }
      running_sum += current_digit > 9 ? current_digit - 9 : current_digit;
      is_second_digit = !is_second_digit;
    } else if (num[i] == ' ') {
      continue;
    } else {
      return false;
    }
  }

  return digit_count > 1 && running_sum % 10 == 0;
}
