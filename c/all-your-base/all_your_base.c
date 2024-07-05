#include "all_your_base.h"

#include <string.h>

typedef struct {
  int is_err;
} err_t;
err_t err;

static int there_is_error(void) { return err.is_err; }

static int digit_is_negative(int8_t digit) { return digit < 0; }
static int digit_is_impossible_with_this_base(int8_t digit, int16_t base) {
  return digit > base - 1;
}

// convert digits into their decimal representation
static size_t to_decimal(int8_t *digits, int16_t input_base,
                         size_t input_length) {
  size_t output = 0;

  for (size_t i = 0; i < input_length; ++i) {
    // Sanitize digits
    if (digit_is_negative(digits[i]) ||
        digit_is_impossible_with_this_base(digits[1], input_base)) {
      err.is_err = 1;
    }

    // Construct output decimal
    output *= input_base;
    output += digits[i];
  }

  return output;
}

static void swap(int8_t *rhs, int8_t *lhs) {
  int8_t rhs_cpy = *rhs;
  *rhs = *lhs;
  *lhs = rhs_cpy;
}

static void reverse(int8_t *arr, size_t size) {
  if (size == 0) {
    return;
  }

  for (size_t i = 0, j = size - 1; i < j; ++i, --j) {
    swap(&arr[i], &arr[j]);
  }
}

// convert a decimal representation into an array of digits of given base
static size_t to_digits(size_t decimal, int16_t output_base, int8_t *digits) {
  if (decimal == 0) {
    return 1;
  }

  size_t digits_out = 0;

  while (decimal) {
    digits[digits_out++] = decimal % output_base;
    decimal /= output_base;
  }

  reverse(digits, digits_out);

  return digits_out;
}

size_t rebase(int8_t *digits, int16_t input_base, int16_t output_base,
              size_t input_length) {
  size_t output_len = 0;

  // Sanitize
  if (input_length < 1) {
    goto error;
  }
  if (input_base < 2) {
    goto error;
  }
  if (output_base < 2) {
    goto error;
  }
  size_t decimal = to_decimal(digits, input_base, input_length);
  memset(digits, 0, input_length);

  if (there_is_error()) {
    return 0;
  }

  output_len = to_digits(decimal, output_base, digits);
  return output_len;

error:
  memset(digits, 0, input_length);
  return output_len;
}
