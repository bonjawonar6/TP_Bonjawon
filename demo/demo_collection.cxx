#include "generation.hxx"
#include <iostream>
#include <vector>
#include <list>
#include <chrono>


int main(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<Particule> particules_vector;
    
    auto start =std::chrono::steady_clock::now();
    for(int i=0; i<1000; ++i){
        particules_vector.push_back(creerParticuleAleatoire(i, gen));
    }

    for(const Particule& particule : particules_vector){
        std::cout << "Particule ID: " << particule.getIdentifiant() 
                  << ", Masse: " << particule.getMasse() 
                  << ", Position: (" << particule.getPosition()[0] << ", " 
                  << particule.getPosition()[1] << ", " 
                  << particule.getPosition()[2] << ")"
                  << ", Vitesse: (" << particule.getVitesse()[0] << ", " 
                  << particule.getVitesse()[1] << ", " 
                  << particule.getVitesse()[2] << ")"
                  << std::endl;
    }

    std::cout << "La taille du vecteur de particules est : " << particules_vector.size() << std::endl;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Temps écoulé pour le vecteur : " << elapsed_seconds.count() << " secondes" << std::endl;
    return 0;
}
