#include <stdio.h>

#include "pig_latin.h"

static char *res = NULL;
static void check_transate(const char *phrase, const char *expected) {
  res = translate(phrase);
  printf("Result: %s\n", res);
  printf("Expected: %s\n", expected);
  printf("\n");
}

int main_2(void) {
  check_transate("apple", "appleay");
  check_transate("ear", "earay");
  check_transate("igloo", "iglooay");
  check_transate("object", "objectay");
  check_transate("under", "underay");
  check_transate("equal", "equalay");
  check_transate("pig", "igpay");
  check_transate("koala", "oalakay");
  check_transate("xenon", "enonxay");
  check_transate("qat", "atqay");
  check_transate("chair", "airchay");
  check_transate("queen", "eenquay");
  check_transate("square", "aresquay");
  check_transate("therapy", "erapythay");
  check_transate("thrush", "ushthray");
  check_transate("school", "oolschay");
  check_transate("yttria", "yttriaay");
  check_transate("xray", "xrayay");
  check_transate("yellow", "ellowyay");
  check_transate("rhythm", "ythmrhay");
  check_transate("my", "ymay");
  check_transate("quick fast run", "ickquay astfay unray");

  return 0;
}
