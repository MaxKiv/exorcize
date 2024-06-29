module Beer (song, line, sing) where

type SongLine = String

line :: Int -> SongLine
line 0 = "No more bottles of beer on the wall, no more bottles of beer.\n\
         \Go to the store and buy some more, 99 bottles of beer on the wall.\n"
line n = numberToString n ++ " " ++ bottleOrBottles n ++ " of beer on the wall, " ++ numberToString n ++ " " ++ bottleOrBottles n ++ " of beer.\n\
                   \Take " ++ oneOrIt n ++ " down and pass it around, " ++ numberToString (n-1) ++ " " ++ bottleOrBottles (n-1) ++ " of beer on the wall.\n\
                   \\n"

numberToString :: Int -> String
numberToString n
  | n == 0 = "no more"
  | otherwise = show n

bottleOrBottles :: Int -> String
bottleOrBottles n
  | n == 1 = "bottle"
  | otherwise = "bottles"

oneOrIt :: Int -> String
oneOrIt n
  | n == 1 = "it"
  | otherwise = "one"

sing :: Int -> String
sing n = concatMap line $ reverse [0..n]

song :: String
song = sing 99
