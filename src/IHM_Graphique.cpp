#include "IHM_Graphique.h"

std::string relativePath = "../assets/images/"; //chemin du dossier images contenant toutes les images

IHM_Graphique::IHM_Graphique(sf::RenderWindow *window) {
    this->window = window;
    width = window->getSize().x;
    height = window->getSize().y;
}

IHM_Graphique::~IHM_Graphique() {

}

void IHM_Graphique::boucleJeu() {
    chargerEchiquier();
    chargerPieces();

    bool isMove = false;
    float dx=0, dy=0;
    sf::Vector2i pos;
    while(window->isOpen()) {
        sf::Vector2i pos = sf::Mouse::getPosition(*window);
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
            if(event.type==sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    for (int i = 0; i <= 8; i++) {
                        if (pionBlanc->getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
                            isMove = true;
                            dx = pos.x - pionBlanc[i].getPosition().x;
                            dy = pos.y - pionBlanc[i].getPosition().y;
                        }
                    }
                }
            }
            if(event.type==sf::Event::MouseButtonReleased) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    isMove=false;
                }
            }
            if (event.type == sf::Event::Resized) { //dynamic resizing
                width = window->getSize().x;
                height = window->getSize().y;

                echiquier.setPosition(width / 2, height / 2);
                echiquier.setScale(1 * (std::min(width, height)) / damier.getSize().x,
                                   1 * (std::min(width, height)) / damier.getSize().y);

                for(int i=0; i<=8; i++) {
                    pionBlanc[i].setPosition(width / 2, height / 2);
                    pionBlanc[i].setScale(echiquier.getGlobalBounds().width / (8*pionBlancTexture.getSize().x),
                                          echiquier.getGlobalBounds().height / (8*pionBlancTexture.getSize().x));
                }

                sf::FloatRect view(0, 0, event.size.width, event.size.height);
                window->setView(sf::View(view));
            }
        }
        for(int i=0; i<=8; i++) {
            if (isMove) {
                pionBlanc[i].setPosition(pos.x - dx, pos.y - dy);
            }
        }

        window->clear(sf::Color::Cyan);
        window->draw(echiquier);
        for(int i=0; i<7;i++) {
            pionBlanc[i].setTexture(pionBlancTexture);
            window->draw(pionBlanc[i]);
            //window->draw(pionNoir[i]);
        }
        window->display();
    }
}

void IHM_Graphique::chargerEchiquier() {
    if (!damier.loadFromFile(relativePath + "echiquier.png")) std::cout << "failed to load echiquier" << std::endl;

    echiquier.setTexture(damier);
    echiquier.setOrigin(echiquier.getLocalBounds().width/2,echiquier.getLocalBounds().height/2);
    echiquier.setPosition(width/2,height/2);
    echiquier.setScale(1 * height / damier.getSize().x,
                       1 * height / damier.getSize().y);
}

void IHM_Graphique::chargerPieces() {
    if (!pionBlancTexture.loadFromFile(relativePath + "pionBlanc.png"))
        std::cout << "failed to load pionBlanc" << std::endl;
    if (!pionNoirTexture.loadFromFile(relativePath + "pionNoir.png"))
        std::cout << "failed to load pionNoir" << std::endl;
    if (!tourBlancTexture.loadFromFile(relativePath + "tourBlanc.png"))
        std::cout << "failed to load tourBlanc" << std::endl;
    if (!tourNoirTexture.loadFromFile(relativePath + "tourNoir.png"))
        std::cout << "failed to load tourNoir" << std::endl;
    if (!chevalierBlancTexture.loadFromFile(relativePath + "chevalierBlanc.png"))
        std::cout << "failed to load chevalierBlanc" << std::endl;
    if (!chevalierNoirTexture.loadFromFile(relativePath + "chevalierNoir.png"))
        std::cout << "failed to load chevalierNoir" << std::endl;
    if (!fouBlancTexture.loadFromFile(relativePath + "fouBlanc.png"))
        std::cout << "failed to load fouBlanc" << std::endl;
    if (!fouNoirTexture.loadFromFile(relativePath + "fouNoir.png"))
        std::cout << "failed to load fouNoir" << std::endl;
    if (!dameBlancTexture.loadFromFile(relativePath + "dameBlanc.png"))
        std::cout << "failed to load dameBlanc" << std::endl;
    if (!dameNoirTexture.loadFromFile(relativePath + "dameNoir.png"))
        std::cout << "failed to load dameNoir" << std::endl;
    if (!roiBlancTexture.loadFromFile(relativePath + "roiBlanc.png"))
        std::cout << "failed to load roiBlanc" << std::endl;
    if (!roiNoirTexture.loadFromFile(relativePath + "roiNoir.png"))
        std::cout << "failed to load roiNoir" << std::endl;

    for(int i=0; i<=8; i++) {
        //configSprite(pionBlanc[i], pionBlancTexture);
        configSprite(pionNoir[i], pionNoirTexture);
    }
    for(int i=0; i<=1; i++) {
        configSprite(tourBlanc[i], tourBlancTexture);
        configSprite(tourNoir[i], tourNoirTexture);
        configSprite(chevalierBlanc[i], chevalierBlancTexture);
        configSprite(chevalierNoir[i], chevalierNoirTexture);
        configSprite(fouBlanc[i], fouBlancTexture);
        configSprite(fouNoir[i], fouNoirTexture);
    }
    configSprite(dameBlanc, dameBlancTexture);
    configSprite(dameNoir, dameNoirTexture);
    configSprite(roiBlanc, roiBlancTexture);
    configSprite(roiNoir, roiNoirTexture);
}

void IHM_Graphique::configSprite(sf::Sprite& spr, sf::Texture tex) {
    spr.setTexture(tex);
    spr.setOrigin(spr.getGlobalBounds().width/2,spr.getGlobalBounds().height/2);
    spr.setScale(echiquier.getGlobalBounds().width/(8*tex.getSize().x),
                 echiquier.getGlobalBounds().height/(8*tex.getSize().x));
}

void IHM_Graphique::refreshSprite(sf::Sprite& spr) {
    spr.setPosition(width/2,height/2);
    spr.setScale(echiquier.getGlobalBounds().width/(8*pionBlancTexture.getSize().x),
                 echiquier.getGlobalBounds().height/(8*pionBlancTexture.getSize().x));
}

