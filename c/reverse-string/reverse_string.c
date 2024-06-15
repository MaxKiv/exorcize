#include "reverse_string.h"

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char *reverse(const char *value) {
  size_t len = strlen(value);
  char* out = calloc(strlen(value), sizeof(char));

  for (size_t y = 0; len--; out[y++] = value[len]) ;
  return out;
}
