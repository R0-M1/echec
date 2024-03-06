#ifndef ECHEC_IHM_GRAPHIQUE_H
#define ECHEC_IHM_GRAPHIQUE_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>



class IHM_Graphique {
private:
    sf::RenderWindow *window;
public:
    IHM_Graphique(sf::RenderWindow *window);
    ~IHM_Graphique();
    void afficheEchiquier();
};


#endif
