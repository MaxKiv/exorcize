# download the exercise for the given tracks
dl exercise:
   for track in c rust haskell; do exercism download --track=$track --exercise={{exercise}}; done
   cp ./haskell/difference-of-squares/flake* ./haskell/{{exercise}}/
   cp ./haskell/difference-of-squares/.envrc ./haskell/{{exercise}}/.envrc
