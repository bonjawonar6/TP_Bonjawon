#ifndef PARTICULE_HXX
#define PARTICULE_HXX

#include <array>


/**
 * @brief Classe représentant une particule dans un système physique
 */
class  Particule{
    private:
        /**
         * @brief Identifiant unique de la particule
         */
        int identifiant;
        
        /** @brief Catégorie de la particule */
        int categorie;

        /** @brief Masse de la particule */
        double masse;

        /** @brief Position de la particule */
        std::array<double, 3> position;

        /** @brief Vitesse de la particule */
        std::array<double, 3> vitesse;

        /** @brief Force appliquée à la particule */
        std::array<double, 3> force;

    
    public:
        /**
         * @brief Constructeur de la classe Particule
         * @param id L'identifiant de la particule
         * @param cat La catégorie de la particule
         * @param m La masse de la particule
         * @param p La position initiale de la particule (tableau de 3 doubles)
         * @param v La vitesse initiale de la particule (tableau de 3 doubles)
         */
        Particule(int id,int cat, double m, const std::array<double, 3>& p, const std::array<double, 3>& v);

        /**
         * @brief Récupère l'identifiant de la particule
         * @return L'identifiant de la particule
         */
        int getIdentifiant() const;

        /**
         * @brief Définit l'identifiant de la particule
         * @param id L'identifiant à définir
         */
        void setIdentifiant(int id);

        /**
         * @brief Récupère la catégorie de la particule
         * @return La catégorie de la particule
         */
        int getCategorie() const;
        
        /**
         * @brief Définit la catégorie de la particule
         * @param c La catégorie à définir
         */
        void setCategorie(int c);
        
        /**
         * @brief Récupère la masse de la particule
         * @return La masse de la particule
         */
        double getMasse() const;
        
        /**
         * @brief Définit la masse de la particule
         * @param m La masse à définir
         */
        void setMasse(double m);

        /**
         * @brief Récupère la position de la particule
         * @return La position de la particule
         */
        const std::array<double, 3>& getPosition() const;
        
        /**
         * @brief Définit la position de la particule
         * @param p La position à définir
         */
        void setPosition(const std::array<double, 3>& p);
        
        /**
         * @brief Récupère la vitesse de la particule
         * @return La vitesse de la particule
         */
        const std::array<double, 3>& getVitesse() const;
        
        /**
         * @brief Définit la vitesse de la particule
         * @param v La vitesse à définir
         */
        void setVitesse(const std::array<double, 3>& v);
        
        /**
         * @brief Récupère la force appliquée à la particule
         * @return La force appliquée à la particule
         */
        const std::array<double, 3>& getForce() const;
        
        
        /**
         * @brief Définit la force appliquée à la particules
         * @param f La force à définir
         */
        void setForce(const std::array<double, 3>& f);

        /** @brief Compare deux particules selon leur identifiant
         * (nécessaire pour ranger des particules dans un std::set).
         * @param autre La particule à comparer
         * @return true si l'identifiant de cette particule est strictement inférieur
         *         à celui de autre
         */
        bool operator<(const Particule& autre) const;
        
};

#endif
