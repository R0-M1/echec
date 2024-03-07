#include "IHM_Graphique.h"

std::string relativePath = "../assets/images/"; //chemin du dossier images contenant toutes les images

IHM_Graphique::IHM_Graphique(sf::RenderWindow *window) {
    this->window = window;
    widthWindow = window->getSize().x;
    heightWindow = window->getSize().y;
    widthEchiquier = std::min(widthWindow, heightWindow);
    heightEchiquier = std::min(widthWindow, heightWindow);
}

IHM_Graphique::~IHM_Graphique() {

}

void IHM_Graphique::boucleJeu() {
    chargerEchiquier();
    chargerPieces();

    sprite[0]= new sf::Sprite;
    sprite[1]= new sf::Sprite;
    sprite[0]->setTexture(pionBlancTexture);
    sprite[1]->setTexture(pionBlancTexture);

    int n;

    bool premierClic=false;
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

                    for (int i = 0; i < 2; i++) {
                        if (sprite[i]->getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
                            isMove = true;
                            n=i;
                            dx = pos.x - sprite[i]->getPosition().x;
                            dy = pos.y - sprite[i]->getPosition().y;
                        }
                    }
                }
            }
            if(event.type==sf::Event::MouseButtonReleased) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    isMove=false;
                }
            }
            //dynamic resizing
            if (event.type == sf::Event::Resized) {
                widthWindow = window->getSize().x;
                heightWindow = window->getSize().y;

                echiquier.setPosition(widthWindow / 2, heightWindow / 2);
                echiquier.scale(1 * (std::min(widthWindow, heightWindow)) / widthEchiquier,
                                1 * (std::min(widthWindow, heightWindow)) / heightEchiquier);

                widthEchiquier = echiquier.getGlobalBounds().width;
                heightEchiquier = echiquier.getGlobalBounds().height;

                for(int i=0; i<2; i++) {
                    if(sprite!= nullptr) {
                        widthCase = widthEchiquier / 8;
                        heightCase = heightEchiquier / 8;
                        sprite[i]->setScale(widthEchiquier / (8 * sprite[i]->getGlobalBounds().width),
                                            widthEchiquier / (8 * sprite[i]->getGlobalBounds().width));
                    }
                }

                widthCase = widthEchiquier/8;
                heightCase = heightEchiquier/8;

                sf::FloatRect view(0, 0, event.size.width, event.size.height);
                window->setView(sf::View(view));
            }
        }

        if (isMove) {
            sprite[n]->setPosition(pos.x - dx, pos.y - dy);
        }


        window->clear(sf::Color::Cyan);
        window->draw(echiquier);
        window->draw(*sprite[0]);
        window->draw(*sprite[1]);

        window->display();
    }
}

void IHM_Graphique::chargerEchiquier() {
    if (!damier.loadFromFile(relativePath + "echiquier.png")) std::cout << "failed to load echiquier" << std::endl;

    echiquier.setTexture(damier);
    echiquier.setOrigin(echiquier.getLocalBounds().width/2,echiquier.getLocalBounds().height/2);
    echiquier.setPosition(widthWindow/2,heightWindow/2);
    echiquier.scale(widthWindow / damier.getSize().x,heightWindow / damier.getSize().y);
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




    /*
    for(int i=0; i<8; i++) {
        configSprite(pionBlanc[i], pionBlancTexture);
        configSprite(pionNoir[i], pionNoirTexture);
    }
    for(int i=0; i<2; i++) {
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
    */
}

void IHM_Graphique::configSprite(sf::Sprite *spr, const sf::Texture& texture, sf::Vector2i position, sf::Vector2f scale) {
    spr->setTexture(texture);
    spr->setOrigin(spr->getGlobalBounds().width/2,spr->getGlobalBounds().height/2);
    spr->setScale(echiquier.getGlobalBounds().width/(8*texture.getSize().x),
                 echiquier.getGlobalBounds().height/(8*texture.getSize().x));
}

void IHM_Graphique::refreshSprite(sf::Sprite& spr) {
    spr.setPosition(widthWindow/2,heightWindow/2);
    spr.setScale(echiquier.getGlobalBounds().width/(8*pionBlancTexture.getSize().x),
                 echiquier.getGlobalBounds().height/(8*pionBlancTexture.getSize().x));
}

