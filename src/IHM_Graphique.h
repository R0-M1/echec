#ifndef ECHEC_IHM_GRAPHIQUE_H
#define ECHEC_IHM_GRAPHIQUE_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>
#include "Jeu.h"


class IHM_Graphique {
private:
    Jeu jeu;

    float widthWindow;
    float heightWindow;
    float tailleEchiquier;
    float tailleCase;
    sf::Vector2f baseEchiquier;
    sf::RenderWindow *window;

    sf::Sprite echiquier;
    sf::Sprite* sprite;
    bool* statique;

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
    void configPiece(sf::Sprite &spr, sf::Texture& texture, float x, float y) const;
    void refreshSprite();
public:
    IHM_Graphique(sf::RenderWindow& window);
    ~IHM_Graphique();
    void boucleJeu();


    //afficheEchiquier : setEchiquierVisible
    //initialisePieces : setPieceVisible


};


#endif
