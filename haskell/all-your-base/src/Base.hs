module Base (Error(..), rebase, toDecimal, toBase, validateInputBase,validateOutputBase, validateDigit, validateDigits) where

import Control.Applicative ((<*>), pure)

data Error a = InvalidInputBase | InvalidOutputBase | InvalidDigit a
    deriving (Show, Eq)

-- Struggling with the order of the Error states...
-- Ideally I would like to check the bases first, then the rebase guards
rebase :: Integral a => a -> a -> [a] -> Either (Error a) [a]
rebase inputBase outputBase inputDigits
  | inputBase < 2 = Left InvalidInputBase -- This is a hack
  | null inputDigits = Right []
  | all (==0) inputDigits = Right []
  | otherwise = (rebaseInternal <$> validateInputBase inputBase)
                      <*> validateOutputBase outputBase
                      <*> validateDigits inputBase inputDigits

rebaseInternal :: Integral a => a -> a -> [a] -> [a]
rebaseInternal inputBase outputBase inputDigits =
  toBase decimalRepresentation outputBase
    where
      decimalRepresentation = toDecimal inputBase inputDigits

validateInputBase :: Integral a => a -> Either (Error a) a
validateInputBase base
  | base < 2 = Left InvalidInputBase
  | otherwise = Right base

validateOutputBase :: Integral a => a -> Either (Error a) a
validateOutputBase base
  | base < 2 = Left InvalidOutputBase
  | otherwise = Right base

validateDigits :: Integral a => a -> [a] -> Either (Error a) [a]
validateDigits base = traverse (validateDigit base)

validateDigit :: Integral a => a -> a -> Either (Error a) a
validateDigit base digit
    | digit < 0 || digit >= base = Left (InvalidDigit digit)
    | otherwise                  = Right digit

toDecimal :: Integral a => a -> [a] -> a
toDecimal base = foldl (\acc x -> acc * base + x) 0

toBase :: Integral a => a -> a -> [a]
toBase 0 _ = [0]
toBase decimal newBase = reverse (convert decimal)
  where
    convert 0 = []
    convert n = let (q, r) = n `divMod` newBase in r : convert q

