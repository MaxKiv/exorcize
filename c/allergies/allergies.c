#include "allergies.h"

allergen_list_t get_allergens(size_t allergies) {

  allergen_list_t out = {0};

  for (size_t shift = 0; shift < ALLERGEN_COUNT; ++shift) {
    if ((allergies >> shift) & 1) {
      out.allergens[shift] = true;
      ++out.count;
    }
  }

  return out;
}

bool is_allergic_to(allergen_t allergen, size_t allergies) {
  allergen_list_t list = get_allergens(allergies);

  return list.allergens[allergen];
}
