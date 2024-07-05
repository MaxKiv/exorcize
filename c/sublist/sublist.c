#include "sublist.h"

#include <stdbool.h>

static bool list_eq(int *first, size_t first_len, int *second,
                    size_t second_len) {
  if (first_len != second_len) {
    return false;
  }

  for (size_t i = 0; i < first_len; ++i) {
    if (first[i] != second[i]) {
      return false;
    }
  }
  return true;
}

static bool is_infix_of(int *first, size_t first_len, int *second,
                        size_t second_len) {
  if (first_len == 0) {
    return true;
  }
  if (first_len > second_len) {
    return false;
  }

  for (size_t i = 0; i <= second_len - first_len; ++i) {
    if (list_eq(first, first_len, second + i, first_len)) {
      return true;
    }
  }
  return false;
}

comparison_result_t check_lists(int *first, int *second, size_t first_len,
                                size_t second_len) {
  if (list_eq(first, first_len, second, second_len)) {
    return EQUAL;
  }
  if (is_infix_of(first, first_len, second, second_len)) {
    return SUBLIST;
  }
  if (is_infix_of(second, second_len, first, first_len)) {
    return SUPERLIST;
  }
  return UNEQUAL;
}
