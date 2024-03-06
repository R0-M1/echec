#include "Echiquier.h"
#include "Pion.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;

// pour changer entre un mode console et un mode graphique
//#define MODE_GRAPHIQUE true


int main()
{

    string titre = "Jeu d'echec";
    string relativePath = "../assets/images/"; //chemin du dossier images contenant toutes les images

    sf::RenderWindow window(sf::VideoMode(1500, 800), titre,sf::Style::Default);


    sf::Texture texture;

    if (!texture.loadFromFile(relativePath+"echiquier.png", sf::IntRect(0, 0, 1166, 1168)))
    {
        cout << "failed to load echiquier"<<endl;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(0.8*window.getSize().y/texture.getSize().x,0.8*window.getSize().y/texture.getSize().y);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }


        window.clear(sf::Color::Blue);

        //draw here
        window.draw(sprite);

        window.display();
    }

    return 0;

}
