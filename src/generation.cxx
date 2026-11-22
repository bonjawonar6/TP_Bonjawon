#include "generation.hxx"

Particule creerParticuleAleatoire(int id, std::mt19937& gen) {
    std::uniform_real_distribution<double> distribution_masse(0.000001, 1.0);
    std::uniform_real_distribution<double> distribution_position(0.0, 1.0);
    std::uniform_real_distribution<double> distribution_vitesse(-1.0, 1.0);

    double masse = distribution_masse(gen);
    std::array<double, 3> position = {distribution_position(gen), distribution_position(gen), distribution_position(gen)};
    std::array<double, 3> vitesse = {distribution_vitesse(gen), distribution_vitesse(gen), distribution_vitesse(gen)}; 

    return Particule(id, 0, masse, position, vitesse);
}