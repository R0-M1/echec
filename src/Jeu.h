#ifndef ECHEC_JEU_H
#define ECHEC_JEU_H

#include "IHM_Graphique.h"
#include "SFML/Graphics.hpp"


class Jeu {
public:
    Jeu();
    Jeu(sf::RenderWindow *window);
    bool echecEtMat(); //verifie apres chaque tour si il y a un echec et mat
    void demarrer();
private:
    IHM_Graphique *affichage;
};


#endif
