#include "Echiquier.h"
#include "Pion.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Jeu.h"

using namespace std;

// pour changer entre un mode console et un mode graphique
//#define MODE_GRAPHIQUE true


int main()
{
    string titre = "Jeu d'echec";

    sf::RenderWindow window(sf::VideoMode(800, 800), titre,sf::Style::Default);
    window.setVerticalSyncEnabled(true);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if(event.type==sf::Event::MouseButtonPressed)
            {
                IHM_Graphique ihm(&window);

                ihm.boucleJeu();
            }
        }


        window.clear(sf::Color::Blue);

        window.display();
    }
    return 0;
}
