module Raindrops (convert) where

convert :: Int -> String
convert n = case foldMap (`raindropSoundOf` n) rainDrops of
    ""    -> show n
    sounds -> sounds
  where
    rainDrops = [(3, "Pling"), (5, "Plang"), (7, "Plong")]
    raindropSoundOf :: (Int, String) -> Int -> String
    raindropSoundOf (factor, sound) n
      | n `mod` factor == 0 = sound
      | otherwise = ""
