#ifndef ALLERGIES_H
#define ALLERGIES_H

#include <stdbool.h>
#include <stddef.h>

typedef enum {
   ALLERGEN_EGGS = 0,
   ALLERGEN_PEANUTS,
   ALLERGEN_SHELLFISH,
   ALLERGEN_STRAWBERRIES,
   ALLERGEN_TOMATOES,
   ALLERGEN_CHOCOLATE,
   ALLERGEN_POLLEN,
   ALLERGEN_CATS,
   ALLERGEN_COUNT,
} allergen_t;

typedef struct {
   size_t count;
   bool allergens[ALLERGEN_COUNT];
} allergen_list_t;

bool is_allergic_to(allergen_t allergen, size_t allergies);

allergen_list_t get_allergens(size_t allergies);

#endif
