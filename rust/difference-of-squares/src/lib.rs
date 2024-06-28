pub fn square_of_sum(n: u32) -> u32 {
    u32::pow((1..=n).sum(), 2)
}

pub fn sum_of_squares(n: u32) -> u32 {
    (1..=n).map(|x| u32::pow(x, 2)).sum()
}

pub fn difference(n: u32) -> u32 {
    square_of_sum(n) - sum_of_squares(n)
}

// module Squares (difference, squareOfSum, sumOfSquares) where
//
// difference :: Integral a => a -> a
// difference n = squareOfSum n - sumOfSquares n
//
// squareOfSum :: Integral a => a -> a
// squareOfSum n = (^2) $ sum [0 .. n]
//
// sumOfSquares :: Integral a => a -> a
// sumOfSquares n = sum $ map (^2) [0 .. n]
