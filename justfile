# download the exercise for the given tracks
dl exercise:
    for track in c rust haskell python; do exercism download --track=$track --exercise={{ exercise }}; done
    cp ./haskell/difference-of-squares/flake* ./haskell/{{ exercise }}/
    cp ./haskell/difference-of-squares/.envrc ./haskell/{{ exercise }}/.envrc
    cp ./python/hello-world/flake* ./python/{{ exercise }}/
    cp ./python/hello-world/.envrc ./python//{{ exercise }}/.envrc
    cp ./python/hello-world/poetry.lock ./python//{{ exercise }}/poetry.lock
    cp ./python/hello-world/pyproject.toml ./python//{{ exercise }}/pyproject.toml

python exercise:
    exercism download --track=python --exercise={{ exercise }}
    cp ./python/hello-world/flake* ./python/{{ exercise }}/
    cp ./python/hello-world/.envrc ./python//{{ exercise }}/.envrc
    cp ./python/hello-world/poetry.lock ./python//{{ exercise }}/poetry.lock
    cp ./python/hello-world/pyproject.toml ./python//{{ exercise }}/pyproject.toml
