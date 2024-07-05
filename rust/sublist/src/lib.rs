#[derive(Debug, PartialEq, Eq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

pub fn sublist<T: PartialEq>(first: &[T], second: &[T]) -> Comparison {
    match (first.is_infix_of(second), second.is_infix_of(first)) {
        (true, true) => Comparison::Equal,
        (false, true) => Comparison::Superlist,
        (true, false) => Comparison::Sublist,
        (false, false) => Comparison::Unequal,
    }
}

pub trait IsInfixOf {
    fn is_infix_of(&self, other: &Self) -> bool;
}

impl<T: PartialEq> IsInfixOf for [T] {
    fn is_infix_of(&self, other: &Self) -> bool {
        if self.is_empty() {
            return true;
        }

        for window in other.windows(self.len()) {
            if self == window {
                return true;
            }
        }
        false
    }
}

