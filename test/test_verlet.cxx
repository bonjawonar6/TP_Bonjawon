#include "verlet.hxx"
#include <cassert>
#include <cmath>
#include <iostream>

// Deux particules de masse 1 a distance 1 : chacune subit une force de 1
// dirigee vers l'autre (attraction).
void test_forces(){
    std::vector<Particule> particules;
    particules.push_back(Particule(0, 0, 1.0, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}));
    particules.push_back(Particule(1, 0, 1.0, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}));

    calculerForces(particules);

    assert(std::abs(particules[0].getForce()[0] - 1.0) < 1e-12);
    assert(std::abs(particules[1].getForce()[0] + 1.0) < 1e-12);
    assert(particules[0].getForce()[1] == 0.0);
}

// Une particule seule n'a aucune force : elle doit avancer en ligne droite.
void test_particule_seule(){
    std::vector<Particule> particules;
    particules.push_back(Particule(0, 0, 1.0, {0.0, 0.0, 0.0}, {1.0, 2.0, 0.0}));

    calculerForces(particules);
    for (int i = 0; i < 10; i++) {
        pasVerlet(particules, 0.1);
    }

    // Apres un temps 1, la position doit etre (1, 2, 0)
    assert(std::abs(particules[0].getPosition()[0] - 1.0) < 1e-12);
    assert(std::abs(particules[0].getPosition()[1] - 2.0) < 1e-12);
}

int main() {
    test_forces();
    test_particule_seule();
    std::cout << "test_verlet : OK" << std::endl;
    return 0;
}
