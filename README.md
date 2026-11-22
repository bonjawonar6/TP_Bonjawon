# Simulation de particules

Petite bibliothèque C++ de simulation de particules (cours C++ pour les mathématiques appliquées).

## Compiler et tester

```bash
mkdir -p build && cd build
cmake ..
make
ctest
```

## Programmes de démonstration

Depuis le dossier `build/` :

- `./demo/demo_collection` : crée et affiche une collection de particules aléatoires.
- `./demo/demo_benchmark` : compare les performances de vector, list, deque et set.
- `./demo/demo_systeme_solaire` : simule le Soleil, la Terre, Jupiter et la comète de Halley
  avec Störmer-Verlet et écrit les positions dans `trajectoires.txt`.

Pour tracer les orbites avec gnuplot :

```bash
gnuplot -p -e "set size ratio -1; plot 'trajectoires.txt' u 2:3 w l t 'Soleil', '' u 4:5 w l t 'Terre', '' u 6:7 w l t 'Jupiter', '' u 8:9 w l t 'Halley'"
```

## Documentation

```bash
make doc
```

La documentation est générée dans `build/docu/html/index.html`.

## Analyse

Les réponses aux questions et les résultats sont dans `doc/analyse.txt`.
