#ifndef ECHEC_IHM_GRAPHIQUE_H
#define ECHEC_IHM_GRAPHIQUE_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>



class IHM_Graphique {
private:
    float width;
    float height;
    sf::RenderWindow *window;

    sf::Sprite echiquier;
    sf::Sprite pionBlanc[8];
    sf::Sprite pionNoir[8];
    sf::Sprite tourBlanc[2];
    sf::Sprite tourNoir[2];
    sf::Sprite chevalierBlanc[2];
    sf::Sprite chevalierNoir[2];
    sf::Sprite fouBlanc[2];
    sf::Sprite fouNoir[2];
    sf::Sprite roiBlanc;
    sf::Sprite roiNoir;
    sf::Sprite dameBlanc;
    sf::Sprite dameNoir;

    sf::Texture damier;
    sf::Texture tourBlancTexture;
    sf::Texture chevalierBlancTexture;
    sf::Texture fouBlancTexture;
    sf::Texture roiBlancTexture;
    sf::Texture dameBlancTexture;
    sf::Texture pionBlancTexture;
    sf::Texture tourNoirTexture;
    sf::Texture chevalierNoirTexture;
    sf::Texture fouNoirTexture;
    sf::Texture roiNoirTexture;
    sf::Texture dameNoirTexture;
    sf::Texture pionNoirTexture;

    void chargerEchiquier();
    void chargerPieces();
    void configSprite(sf::Sprite& spr, sf::Texture tex);
    void refreshSprite(sf::Sprite& spr);
public:
    IHM_Graphique(sf::RenderWindow *window);
    ~IHM_Graphique();
    void boucleJeu();
};


#endif