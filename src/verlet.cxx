#include "verlet.hxx"
#include <cmath>

void calculerForces(std::vector<Particule>& particules) {
    int n = particules.size();

    for (int i = 0; i < n; i++) {
        std::array<double, 3> force = {0.0, 0.0, 0.0};
        const std::array<double, 3>& xi = particules[i].getPosition();
        double mi = particules[i].getMasse();

        for (int j = 0; j < n; j++) {
            if (j == i) {
                continue;
            }
            const std::array<double, 3>& xj = particules[j].getPosition();
            double mj = particules[j].getMasse();

            // r_ij : vecteur qui va de la particule i vers la particule j
            double rx = xj[0] - xi[0];
            double ry = xj[1] - xi[1];
            double rz = xj[2] - xi[2];
            double r = std::sqrt(rx * rx + ry * ry + rz * rz);

            // F_ij = mi * mj / r^3 * r_ij
            double coef = mi * mj / (r * r * r);
            force[0] += coef * rx;
            force[1] += coef * ry;
            force[2] += coef * rz;
        }

        particules[i].setForce(force);
    }
}

void pasVerlet(std::vector<Particule>& particules, double dt) {
    int n = particules.size();

    // On garde les anciennes forces (F_old)
    std::vector<std::array<double, 3>> forcesOld(n);

    // Mise à jour des positions
    for (int i = 0; i < n; i++) {
        std::array<double, 3> x = particules[i].getPosition();
        const std::array<double, 3>& v = particules[i].getVitesse();
        const std::array<double, 3>& f = particules[i].getForce();
        double m = particules[i].getMasse();

        for (int k = 0; k < 3; k++) {
            x[k] = x[k] + dt * (v[k] + 0.5 / m * f[k] * dt);
        }
        particules[i].setPosition(x);
        forcesOld[i] = f;
    }

    // Nouvelles forces avec les nouvelles positions
    calculerForces(particules);

    // Mise à jour des vitesses
    for (int i = 0; i < n; i++) {
        std::array<double, 3> v = particules[i].getVitesse();
        const std::array<double, 3>& f = particules[i].getForce();
        double m = particules[i].getMasse();

        for (int k = 0; k < 3; k++) {
            v[k] = v[k] + dt * 0.5 / m * (f[k] + forcesOld[i][k]);
        }
        particules[i].setVitesse(v);
    }
}

double energieTotale(const std::vector<Particule>& particules) {
    int n = particules.size();
    double energie = 0.0;

    for (int i = 0; i < n; i++) {
        // Energie cinetique : 1/2 m v^2
        const std::array<double, 3>& v = particules[i].getVitesse();
        double v2 = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
        energie += 0.5 * particules[i].getMasse() * v2;

        // Energie potentielle : -mi * mj / r (chaque paire comptee une fois)
        for (int j = i + 1; j < n; j++) {
            const std::array<double, 3>& xi = particules[i].getPosition();
            const std::array<double, 3>& xj = particules[j].getPosition();
            double rx = xj[0] - xi[0];
            double ry = xj[1] - xi[1];
            double rz = xj[2] - xi[2];
            double r = std::sqrt(rx * rx + ry * ry + rz * rz);
            energie -= particules[i].getMasse() * particules[j].getMasse() / r;
        }
    }
    return energie;
}
