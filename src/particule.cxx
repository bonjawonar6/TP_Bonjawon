#include "particule.hxx"

Particule::Particule(int id,int cat, double m, const std::array<double, 3>& p, const std::array<double, 3>& v)
: identifiant(id), categorie(cat), masse(m), position(p), vitesse(v), force({0.0, 0.0, 0.0}) {}

int Particule::getIdentifiant() const {
    return identifiant;
}

void Particule::setIdentifiant(int id) {
    identifiant = id;
}

int Particule::getCategorie() const {
    return categorie;
}

void Particule::setCategorie(int c) {
    categorie = c;
}

double Particule::getMasse() const {
    return masse;
}

void Particule::setMasse(double m) {
    masse = m;
}

const std::array<double, 3>& Particule::getPosition() const {
    return position;
}

void Particule::setPosition(const std::array<double, 3>& p) {
    position = p;
}

const std::array<double, 3>& Particule::getVitesse() const {
    return vitesse;
}


void Particule::setVitesse(const std::array<double, 3>& v) {
    vitesse = v;
}

const std::array<double, 3>& Particule::getForce() const {
    return force;
}

void Particule::setForce(const std::array<double, 3>& f) {
    force = f;
}


bool Particule::operator<(const Particule& autre) const {
    return identifiant < autre.identifiant;
}