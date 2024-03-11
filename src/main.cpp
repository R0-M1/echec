#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "SFML/Audio.hpp"
#include "IHM_Graphique.h"
#include "IHM_console.h"

using namespace std;

// pour changer entre un mode console et un mode graphique
//#define MODE_GRAPHIQUE true


int main() {
    bool MODE_GRAPHIQUE = true;
    cout<<"mode graphique ? (1)oui (0)non"<<endl;
    cin>>MODE_GRAPHIQUE;
    if (!MODE_GRAPHIQUE) {
        IHM_console ihm;
        ihm.boucleJeu();
    } else {
        string titre = "Jeu d'echec";

        sf::RenderWindow window(sf::VideoMode(800, 800), titre, sf::Style::Default);
        window.setVerticalSyncEnabled(true);

        IHM_Graphique ihm(window);
        ihm.boucleJeu();

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::MouseButtonPressed) {

                }
            }
            window.clear(sf::Color::Blue);

            window.display();
        }
        return 0;
    }
}
