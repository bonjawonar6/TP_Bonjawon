#include "generation.hxx"
#include <algorithm>
#include <chrono>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <set>
#include <type_traits>
#include <vector>

/// @brief Mesure le temps d'insertion de particules dans une collection.
/// @param collection  La collection à remplir (vide au départ)
/// @param particules  Les particules à insérer (générées à l'avance)
/// @return Le temps écoulé en secondes
template <typename Collection>
double mesurerInsertion(Collection& collection, const std::vector<Particule>& particules) {
    auto start = std::chrono::steady_clock::now();

    for (const Particule& particule : particules) {
        collection.insert(collection.end(), particule);
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    return elapsed_seconds.count();
}

/// @brief Mesure le temps d'un parcours en lecture (somme des masses).
/// @param collection La collection à parcourir
/// @param somme      Reçoit la somme des masses : le résultat est utilisé,
///                   donc le compilateur ne peut pas supprimer la boucle
/// @return Le temps écoulé en secondes
template <typename Collection>
double mesurerParcours(const Collection& collection, double& somme) {
    auto start = std::chrono::steady_clock::now();

    somme = 0.0;
    for (const Particule& particule : collection) {
        somme += particule.getMasse();
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    return elapsed_seconds.count();
}

/// @brief Mesure le temps d'un parcours avec modification (déplacement de
///        chaque particule, comme le fera Störmer-Verlet).
/// @param collection La collection à parcourir et modifier
/// @return Le temps écoulé en secondes
/// @note Ne compile pas avec un std::set : ses éléments sont constants,
///       car les modifier pourrait casser l'ordre de tri.
template <typename Collection>
double mesurerModification(Collection& collection) {
    auto start = std::chrono::steady_clock::now();

    for (Particule& particule : collection) {
        std::array<double, 3> position = particule.getPosition();
        position[0] += 0.001;
        particule.setPosition(position);
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    return elapsed_seconds.count();
}

/// @brief Nombre de répétitions de chaque mesure : on garde le meilleur temps,
///        pour limiter l'effet des perturbations du système.
const int NB_REPETITIONS = 10;

/// @brief Les 3 temps mesurés pour une collection.
struct Temps {
    double insertion = 1e9;
    double parcours = 1e9;
    double modification = 1e9;
};

/// @brief Lance toutes les mesures sur un type de collection.
/// @param particules Les particules à utiliser
/// @return Les meilleurs temps sur NB_REPETITIONS essais
template <typename Collection>
Temps mesurerCollection(const std::vector<Particule>& particules) {
    Temps meilleur;
    double somme = 0.0;

    for (int r = 0; r < NB_REPETITIONS; ++r) {
        Collection collection;
        meilleur.insertion = std::min(meilleur.insertion, mesurerInsertion(collection, particules));
        meilleur.parcours = std::min(meilleur.parcours, mesurerParcours(collection, somme));
        // Le set est exclu a la compilation : mesurerModification ne compile pas avec lui
        if constexpr (!std::is_same_v<Collection, std::set<Particule>>) {
            meilleur.modification = std::min(meilleur.modification, mesurerModification(collection));
        }
    }
    if (somme < 0) {  // n'arrive jamais : empêche juste d'optimiser le parcours
        std::cout << somme << std::endl;
    }
    return meilleur;
}

/// @brief Affiche une ligne du tableau (temps en microsecondes).
void afficherLigne(int n, const std::string& nom, const Temps& t, bool modifiable) {
    std::cout << std::setw(8) << n << std::setw(8) << nom
              << std::setw(14) << t.insertion * 1e6
              << std::setw(14) << t.parcours * 1e6;
    if (modifiable) {
        std::cout << std::setw(14) << t.modification * 1e6;
    } else {
        std::cout << std::setw(14) << "impossible";
    }
    std::cout << std::endl;
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::cout << "Temps en microsecondes (meilleur de " << NB_REPETITIONS << " essais)" << std::endl;
    std::cout << std::setw(8) << "N" << std::setw(8) << "coll."
              << std::setw(14) << "insertion" << std::setw(14) << "parcours"
              << std::setw(14) << "modif." << std::endl;

    for (int n = 64; n <= 65536; n *= 2) {
        // Generation des particules HORS chrono
        std::vector<Particule> particules;
        for (int i = 0; i < n; ++i) {
            particules.push_back(creerParticuleAleatoire(i, gen));
        }

        afficherLigne(n, "vector", mesurerCollection<std::vector<Particule>>(particules), true);
        afficherLigne(n, "list", mesurerCollection<std::list<Particule>>(particules), true);
        afficherLigne(n, "deque", mesurerCollection<std::deque<Particule>>(particules), true);
        afficherLigne(n, "set", mesurerCollection<std::set<Particule>>(particules), false);
        std::cout << std::endl;
    }
    return 0;
}
