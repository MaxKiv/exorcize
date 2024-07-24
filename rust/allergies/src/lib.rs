pub struct Allergies {
    allergens: u32,
}

#[derive(Debug, PartialEq, Eq, Clone, Copy)]
#[repr(C)]
pub enum Allergen {
    Eggs = 0,
    Peanuts,
    Shellfish,
    Strawberries,
    Tomatoes,
    Chocolate,
    Pollen,
    Cats,
}
const ALLERGEN_COUNT: u32 = 8;

impl Allergies {
    pub fn new(score: u32) -> Self {
        Allergies { allergens: score }
    }

    pub fn is_allergic_to(&self, allergen: &Allergen) -> bool {
        let allergie_score = *allergen as u32;
        (1 << allergie_score) & self.allergens != 0
    }

    pub fn allergies(&self) -> Vec<Allergen> {
        (0..=ALLERGEN_COUNT)
            .filter(|a| (1 << a) & self.allergens != 0)
            .map(|a| unsafe { std::mem::transmute(a) })
            .collect()
    }
}
