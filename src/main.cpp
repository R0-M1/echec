#include "Echiquier.h"
#include "Pion.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;


int main()
{
    string titre = "Jeu d'echec";
    string relativePath = "../assets/images/"; //chemin du dossier images contenant toutes les images

    // create the window
    sf::RenderWindow window(sf::VideoMode(1500, 800), titre,sf::Style::Default);

    sf::Texture texture;

    if (!texture.loadFromFile(relativePath+"echiquier.png", sf::IntRect(0, 0, 1166, 1168)))
    {
        cout << "failed to load echiquier"<<endl;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(0.8*window.getSize().y/texture.getSize().x,0.8*window.getSize().y/texture.getSize().y);



    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Blue);

        // draw everything here...
        // window.draw(...);

        window.draw(sprite);


        // end the current frame
        window.display();
    }

    return 0;

}
