#ifndef LUHN_H
#define LUHN_H

#include <stdbool.h>

#define MAX_DIGITS 64
#define SEPARATOR_DIGIT 10

bool luhn(const char *num);

#endif
