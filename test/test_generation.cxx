#include "generation.hxx"
#include <cassert>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());

    Particule p1 = creerParticuleAleatoire(1, gen);

    // Vérification des propriétés de la particule générée
    assert(p1.getIdentifiant() == 1);
    assert(0 < p1.getMasse() && p1.getMasse() <= 1);
    for (double coord : p1.getPosition()) {
        assert(0 <= coord && coord <= 1);
    }
    for (double coord : p1.getVitesse()) {
        assert(-1 <= coord && coord <= 1);
    }


    for (int i = 2; i < 1000; ++i) {
        Particule p2 = creerParticuleAleatoire(i, gen);
        // Vérification des propriétés de la particule générée
        assert(p2.getIdentifiant() == i);
        assert(0 < p2.getMasse() && p2.getMasse() <= 1);
        for (double coord : p2.getPosition()) {
            assert(0 <= coord && coord <= 1);
        }
        for (double coord : p2.getVitesse()) {
            assert(-1 <= coord && coord <= 1);
        }

        assert(p2.getIdentifiant() != p1.getIdentifiant() && p2.getMasse() != p1.getMasse() && p2.getPosition() != p1.getPosition() && p2.getVitesse() != p1.getVitesse());

        p1 = p2; // Mettre à jour p1 pour la prochaine itération
    }
    
    
}