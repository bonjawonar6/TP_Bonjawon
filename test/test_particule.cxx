#include "particule.hxx"
#include <cassert>
#include <iostream>

void test_constructeur(){
    Particule p(1,0,0.5,{0.0, 0.0, 0.0},{1.0, 1.0, 1.0});
    assert(p.getIdentifiant() == 1);
    assert(p.getCategorie() == 0);
    assert(p.getMasse() == 0.5);
    assert(p.getPosition()[1] == 0.0);
    assert(p.getVitesse()[0] == 1.0);
    assert(p.getForce()[2] == 0.0);
}

void test_mutateurs(){
    Particule p(1,0,0.5,{0.0, 0.0, 0.0},{1.0, 1.0, 1.0});
    p.setIdentifiant(2);
    p.setCategorie(1);
    p.setMasse(1.5);
    p.setPosition({1.0, 2.0, 3.0});
    p.setVitesse({4.0, 5.0, 6.0});
    p.setForce({7.0, 8.0, 9.0});

    assert(p.getIdentifiant() == 2);
    assert(p.getCategorie() == 1);
    assert(p.getMasse() == 1.5);
    assert(p.getPosition()[2] == 3.0);
    assert(p.getVitesse()[1] == 5.0);
    assert(p.getForce()[0] == 7.0);
}

int main() {
    test_constructeur();
    test_mutateurs();
    std::cout << "Tous les tests ont réussi !" << std::endl;
    return 0;
}