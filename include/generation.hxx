#ifndef GENERATION_HXX
#define GENERATION_HXX

#include <random>
#include "particule.hxx"

/**
 * @brief Crée une particule avec une masse, une position et une vitesse aléatoires
 * @param id Un identifiant à donner à la particule
 * @param gen Un générateur de nombres aléatoires
 * @return Une particule avec des propriétés aléatoires
 */
Particule creerParticuleAleatoire( int id,std::mt19937& gen);

#endif