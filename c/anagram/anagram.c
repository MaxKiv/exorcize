#include "anagram.h"

#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#define HASH_TABLE_SIZE 26

// Hashing function for our ghetto hash tables
static size_t hash(char c) {
  // c is capital alpha
  if ((c > 64) && (c < 91)) {
    return c - 'A';
    // c is small alpha
  } else if ((c > 97) && (c < 123)) {
    return c - 'a';
  }
  // c is garbage
  return HASH_TABLE_SIZE;
}

static void to_lowercase_in_place(char *str) {
  if (str == NULL) {
    return;
  }

  for (size_t i = 0; i < strlen(str); i++) {
    str[i] = tolower((unsigned char)str[i]);
  }
}

static void strcnt(const char *str, size_t hash_table[HASH_TABLE_SIZE]) {
  size_t len = strlen(str);
  for (size_t i = 0; i < len; ++i) {
    size_t idx = hash(str[i]);

    // skip faulty chars
    if (idx < HASH_TABLE_SIZE) {
      ++hash_table[idx];
    }
  }
}

static bool
is_subject_anagram_of_candidate(size_t subject_count[HASH_TABLE_SIZE],
                                size_t candidate_count[HASH_TABLE_SIZE]) {
  for (size_t i = 0; i < HASH_TABLE_SIZE; ++i) {
    if (subject_count[i] != candidate_count[i]) {
      return false;
    }
  }
  return true;
}

static void process_candidate(struct candidate *candidate,
                              const char *subject) {
  candidate->is_anagram = NOT_ANAGRAM;

  char candidate_word[MAX_STR_LEN];
  char subject_word[MAX_STR_LEN];
  strcpy(candidate_word, candidate->word);
  strcpy(subject_word, subject);
  to_lowercase_in_place(subject_word);
  to_lowercase_in_place(candidate_word);

  if (strcmp(candidate_word, subject_word) == 0) {
    return;
  }

  size_t subject_count[HASH_TABLE_SIZE] = {0};
  size_t candidate_count[HASH_TABLE_SIZE] = {0};

  strcnt(candidate->word, candidate_count);
  strcnt(subject, subject_count);

  if (is_subject_anagram_of_candidate(subject_count, candidate_count)) {
    candidate->is_anagram = IS_ANAGRAM;
  }
}

void find_anagrams(const char *subject, struct candidates *candidates) {
  for (size_t i = 0; i < candidates->count; ++i) {
    process_candidate(&candidates->candidate[i], subject);
  }
}
