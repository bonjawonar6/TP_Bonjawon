#include "verlet.hxx"
#include <fstream>
#include <iostream>

int main() {
    // Soleil, Terre, Jupiter, Halley (tableau de l'enonce)
    std::vector<Particule> astres;
    astres.push_back(Particule(0, 0, 1.0,     {0.0, 0.0, 0.0},   {0.0, 0.0, 0.0}));
    astres.push_back(Particule(1, 0, 3.0e-6,  {0.0, 1.0, 0.0},   {-1.0, 0.0, 0.0}));
    astres.push_back(Particule(2, 0, 9.55e-4, {0.0, 5.36, 0.0},  {-0.425, 0.0, 0.0}));
    astres.push_back(Particule(3, 0, 1.0e-14, {34.75, 0.0, 0.0}, {0.0, 0.0296, 0.0}));

    double dt = 0.015;
    double tEnd = 468.5;
    double t = 0.0;

    // Fichier de sortie : une ligne par iteration
    // t  x_soleil y_soleil  x_terre y_terre  x_jupiter y_jupiter  x_halley y_halley
    std::ofstream fichier("trajectoires.txt");
    if (!fichier) {
        std::cout << "Erreur : impossible d'ouvrir trajectoires.txt" << std::endl;
        return 1;
    }

    // Initialisation : calcul des forces
    calculerForces(astres);
    double energieDebut = energieTotale(astres);

    while (t < tEnd) {
        t = t + dt;
        pasVerlet(astres, dt);

        // Ecriture des positions avec les accesseurs
        fichier << t;
        for (int i = 0; i < 4; i++) {
            fichier << " " << astres[i].getPosition()[0] << " " << astres[i].getPosition()[1];
        }
        fichier << std::endl;
    }
    fichier.close();

    double energieFin = energieTotale(astres);

    std::cout << "Simulation terminee a t = " << t << std::endl;
    std::cout << "Positions ecrites dans trajectoires.txt" << std::endl;
    std::cout << "Energie au debut : " << energieDebut << std::endl;
    std::cout << "Energie a la fin : " << energieFin << std::endl;
    std::cout << "Ecart relatif    : " << (energieFin - energieDebut) / energieDebut << std::endl;
    return 0;
}
