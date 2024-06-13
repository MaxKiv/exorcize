#include "pig_latin.h"

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_BUFFER_SIZE 1000
#define OUTPUT_BUFFER_SIZE 1000
#define MAX_WORD_SIZE 100

const char *whitespace_delims = " ";
const char *vowels = "aoeiu";

char input[INPUT_BUFFER_SIZE] = { 0 };

static size_t find_vowel_idx(char* word) {
  if(strlen(word) < 1) {
    return 0;
  }
  for(size_t i = 0; i < strlen(vowels); ++i) {
    if(word[0] == vowels[i]) {
      return 0;
    }
  }
  if (strncmp(word, "yt", 2) == 0) {
    return 0;
  } else if (strncmp(word, "xr", 2) == 0) {
    return 0;
  }

  if (strncmp(word, "qu", 2) == 0) {
    return 2;
  }

  if(word[1] == 'y') {
    return 1;
  }

  return 1 + find_vowel_idx(word + sizeof(char));
}

// In place pig-latinification
static void translate_word(char* word, char translated_word[MAX_WORD_SIZE]) {
  // Split word on found vowel index and format into translated_word
  size_t consonant_len = find_vowel_idx(word);

  size_t rest_len = strlen(word+consonant_len);
  strncpy(translated_word, word+consonant_len, rest_len);
  strncpy(translated_word+rest_len, word, consonant_len);
  strcpy(translated_word+consonant_len+rest_len, "ay");
}

char *translate(const char *phrase) {
  // Prepare the output buffer
  char* output;
  size_t output_write_idx = 0;
  output = calloc(OUTPUT_BUFFER_SIZE, sizeof(char));

  // Copy the input so we can massage it
  strcpy(input, phrase);

  // split input phrase in words
  char *token;
  char translated_word[MAX_WORD_SIZE];
  token = strtok(input, whitespace_delims);
  do {
    // translate each word
    translate_word(token, translated_word);

    // add translated_word to output buffer
    size_t translated_word_len = strlen(translated_word);
    strcpy(&output[output_write_idx], translated_word);
    output_write_idx += translated_word_len;

    // add the space back we lost with strtok
    output[output_write_idx++] = ' ';

  } while ((token = strtok(NULL, whitespace_delims)));

  // clear last space
  output[strlen(output)-1] = '\0';

  // This should now be filled with goodness
  return output;
}

