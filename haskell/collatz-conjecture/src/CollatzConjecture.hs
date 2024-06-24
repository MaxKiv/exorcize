module CollatzConjecture (collatz, collatzSequence) where

collatzSequence :: Integer -> [Integer]
collatzSequence x
  | x == 0    = error "collatz sequence input must be positive"
  | x == 1    = [1]
  | even x    = x : collatzSequence (x `div` 2)
  | otherwise = x : collatzSequence (3*x + 1)

collatz :: Integer -> Maybe Integer
collatz n
  | n < 1     = Nothing
  | otherwise = Just $ toInteger $ (length $ collatzSequence n) -1
