#ifndef VERLET_HXX
#define VERLET_HXX

#include <vector>
#include "particule.hxx"

/**
 * @brief Calcule la force gravitationnelle totale sur chaque particule
 *        (formules (1) et (2) de l'énoncé) et la stocke dans la particule.
 * @param particules Les particules du système
 */
void calculerForces(std::vector<Particule>& particules);

/**
 * @brief Fait avancer le système d'un pas de temps avec l'algorithme de
 *        Störmer-Verlet (une itération de la boucle while).
 * @param particules Les particules du système (les forces doivent déjà être calculées)
 * @param dt Le pas de temps
 */
void pasVerlet(std::vector<Particule>& particules, double dt);

/**
 * @brief Calcule l'énergie totale du système (cinétique + potentielle).
 *        Elle doit rester à peu près constante pendant la simulation.
 * @param particules Les particules du système
 * @return L'énergie totale
 */
double energieTotale(const std::vector<Particule>& particules);

#endif
