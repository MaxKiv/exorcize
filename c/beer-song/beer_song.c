#include "beer_song.h"
#include "string.h"

#include <stddef.h>
#include <stdio.h>

#define MAX_LINE_LENGTH (1024)
#define MAX_LINE_COUNT (299)

static void get_verse(uint8_t n, char current_line[2][MAX_LINE_LENGTH]) {
  if (n == 0) {
    strcpy(current_line[0],
           "No more bottles of beer on the wall, no more bottles of beer.");
    strcpy(
        current_line[1],
        "Go to the store and buy some more, 99 bottles of beer on the wall.");
  } else if (n == 1) {
    strcpy(current_line[0], "1 bottle of beer on the wall, 1 bottle of beer.");
    strcpy(current_line[1], "Take it down and pass it around, no more bottles "
                            "of beer on the wall.");
  } else if (n == 2) {
    strcpy(current_line[0],
           "2 bottles of beer on the wall, 2 bottles of beer.");
    strcpy(current_line[1],
           "Take one down and pass it around, 1 bottle of beer on the wall.");
  } else {
    sprintf(current_line[0],
            "%d bottles of beer on the wall, %d bottles of beer.", n, n);
    sprintf(current_line[1],
            "Take one down and pass it around, %d bottles of beer on the wall.",
            n - 1);
  }
}

void recite(uint8_t start_bottles, uint8_t take_down, char **song) {
  for (size_t i = 0; i < take_down; ++i) {
    size_t current_verse_number = start_bottles - i;
    char current_line[2][MAX_LINE_LENGTH] = {0};

    get_verse(current_verse_number, current_line);

    strcpy(song[i * 3], current_line[0]);
    strcpy(song[i * 3 + 1], current_line[1]);

  }
}
