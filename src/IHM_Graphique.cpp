#include "IHM_Graphique.h"

std::string relativePath = "../assets/images/"; //chemin du dossier images contenant toutes les images

IHM_Graphique::IHM_Graphique(sf::RenderWindow *window) {
    this->window = window;
}

IHM_Graphique::~IHM_Graphique() {

}

void IHM_Graphique::afficheEchiquier() {
    float width = window->getSize().x;
    float height = window->getSize().y;

    sf::Texture damier;

    if (!damier.loadFromFile(relativePath+"echiquier.png")) std::cout << "failed to load echiquier"<<std::endl; //message d'erreur;

    sf::Sprite echiquier;
    echiquier.setTexture(damier);
    echiquier.setOrigin(echiquier.getLocalBounds().width/2,echiquier.getLocalBounds().height/2);
    echiquier.setPosition(width/2,height/2);
    echiquier.setScale(0.8*height/damier.getSize().x,0.8*height/damier.getSize().y);

    sf::Event event;
    while(window->isOpen()) {
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
            if (event.type == sf::Event::Resized) {
                width = window->getSize().x;
                height = window->getSize().y;

                echiquier.setPosition(width / 2, height / 2);
                echiquier.setScale(0.8 * (std::min(width, height)) / damier.getSize().x,
                                   0.8 * (std::min(width, height)) / damier.getSize().y);
                sf::FloatRect view(0, 0, event.size.width, event.size.height);
                window->setView(sf::View(view));
            }
        }
        window->clear();
        window->draw(echiquier);
        window->display();
    }
}
