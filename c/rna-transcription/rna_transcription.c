#include <stdlib.h>
#include <string.h>

#include "rna_transcription.h"

static char complementary_nucleotide(char nucleotide) {
  switch (nucleotide) {
    case 'A':
      return 'U';
    case 'C':
      return 'G';
    case 'G':
      return 'C';
    case 'T':
      return 'A';
  }
  return '\0';
}

char *to_rna(const char *dna) {
  char *rna = calloc(strlen(dna) + 1, sizeof(char));
  char *out = rna;

  if(strlen(dna) == 0) return rna;

  while((*rna++ = complementary_nucleotide(*dna++)))
    ;

  return out;
}
