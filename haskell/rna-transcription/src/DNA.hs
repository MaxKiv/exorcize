module DNA (toRNA) where

toRNA :: String -> Either Char String
toRNA [] = Right []
toRNA (x:xs) = case toNucleotide x of
  Left invalidChar -> Left invalidChar
  Right nucleotide -> case toRNA xs of
    Left invalidChar -> Left invalidChar
    Right rna -> Right (fromNucleotide (complementaryNucleotide nucleotide) : rna)

data Nucleotide = A | G | C | T | U deriving (Bounded, Enum, Show, Eq)

toNucleotide :: Char -> Either Char Nucleotide
toNucleotide c
  | c == 'A' = Right A
  | c == 'G' = Right G
  | c == 'C' = Right C
  | c == 'T' = Right T
  | otherwise = Left c

fromNucleotide :: Nucleotide -> Char
fromNucleotide c
  | c == A = 'A'
  | c == G = 'G'
  | c == C = 'C'
  | c == T = 'T'
  | c == U = 'U'
  | otherwise = error "fromNucleotide: invalid nucleotide to convert from"

complementaryNucleotide :: Nucleotide -> Nucleotide
complementaryNucleotide n
  | n == A = U
  | n == G = C
  | n == C = G
  | n == T = A
  | otherwise = error "complementaryNucleotide: invalid nucleotide to complement"
