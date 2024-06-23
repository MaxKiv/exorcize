#include "acronym.h"

#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static bool is_whitespace(const char c) {
  switch (c) {
  case ' ':
  case '-':
  case '_':
    return true;
  default:
    return false;
  }
}

static bool char_part_of_acronym(const char c) {
  static char last_char = ' ';

  bool out = ((is_whitespace(last_char) && isalpha(c)) ||
              (islower(last_char) && isupper(c)));

  last_char = c;
  return out;
}

char *abbreviate(const char *phrase) {
  if (phrase == NULL || strlen(phrase) == 0) {
    return NULL;
  }

  char *out = calloc(strlen(phrase) + 1, sizeof(char));
  size_t out_idx = 0;

  for (size_t i = 0; phrase[i]; ++i) {
    if (char_part_of_acronym(phrase[i])) {
      out[out_idx++] = toupper(phrase[i]);
    }
  }

  return out;
}
