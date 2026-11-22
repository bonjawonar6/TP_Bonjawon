#ifndef PARTICULE_HXX
#define PARTICULE_HXX

#include <array>

class  Particule{
    private:
        int identifiant;
        int categorie;
        double masse;
        std::array<double, 3> position;
        std::array<double, 3> vitesse;
        std::array<double, 3> force;

    
    public:

        Particule(int id,int cat, double m, const std::array<double, 3>& p, const std::array<double, 3>& v);

        int getIdentifiant() const;
        void setIdentifiant(int id);
        
        
        int getCategorie() const;
        void setCategorie(int c);
        
        double getMasse() const;
        void setMasse(double m);

        const std::array<double, 3>& getPosition() const;
        void setPosition(const std::array<double, 3>& p);
        
        const std::array<double, 3>& getVitesse() const;
        void setVitesse(const std::array<double, 3>& v);
        
        const std::array<double, 3>& getForce() const;
        void setForce(const std::array<double, 3>& f);
        
};

#endif
