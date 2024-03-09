#include "IHM_Graphique.h"


std::string relativePath = "../assets/images/"; //chemin du dossier images contenant toutes les images

IHM_Graphique::IHM_Graphique(sf::RenderWindow& window) {
    this->window = &window;
    widthWindow = window.getSize().x;
    heightWindow = window.getSize().y;
    tailleEchiquier = std::min(widthWindow, heightWindow);
    tailleCase = tailleEchiquier / 8;
    sprite = new sf::Sprite[32];
    statique = new bool[32];
}


IHM_Graphique::~IHM_Graphique() {
    delete[] sprite;
    sprite = nullptr;
}

void IHM_Graphique::boucleJeu() {
    chargerEchiquier();
    chargerPieces();


    baseEchiquier = echiquier.getPosition() - sf::Vector2f(tailleEchiquier/2,tailleEchiquier/2);
    sf::Vector2i oldIntPos, newIntPos;
    sf::Vector2f oldPos, newPos;
    int n = -1;
    bool premierClic=false;
    bool bouge = false;
    sf::Vector2i souris;
    while(window->isOpen()) {
        souris = sf::Mouse::getPosition(*window);
        sf::Event event;
        while (window->pollEvent(event)) {
            if(event.type == sf::Event::Closed) window->close();
            if(event.type==sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    for (int i = 0; i < 32; i++) {
                        if (sprite[i].getGlobalBounds().contains(window->mapPixelToCoords(souris))) {
                            bouge = true;
                            n=i;
                            oldIntPos = sf::Vector2i(int((sprite[n].getPosition().x - baseEchiquier.x) * 8 / tailleEchiquier),
                                                     int((sprite[n].getPosition().y - baseEchiquier.y) * 8 / tailleEchiquier));
                            oldPos = sf::Vector2f(oldIntPos.x * tailleCase + tailleCase / 2,
                                                  oldIntPos.y * tailleCase + tailleCase / 2) + baseEchiquier;
                        }
                    }
                }
            }
            if(event.type==sf::Event::MouseButtonReleased) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    if(n!=-1) {
                        bouge = false;
                        newIntPos = sf::Vector2i(int((sprite[n].getPosition().x - baseEchiquier.x) * 8 / tailleEchiquier),
                                                 int((sprite[n].getPosition().y - baseEchiquier.y) * 8 / tailleEchiquier));
                        std::cout<<jeu.coup(7-oldIntPos.y, oldIntPos.x, 7-newIntPos.y, newIntPos.x)<<std::endl;
                        std::cout<<oldIntPos.x<< 7-oldIntPos.y<< newIntPos.x<< 7-newIntPos.y<<std::endl;
                        if(jeu.coup(oldIntPos.x, oldIntPos.y, newIntPos.x, newIntPos.y)) {
                            newPos = sf::Vector2f(newIntPos.x * tailleCase + tailleCase / 2,
                                                  newIntPos.y * tailleCase + tailleCase / 2) + baseEchiquier;
                            sprite[n].setPosition(newPos);
                        } else {
                            sprite[n].setPosition(oldPos);
                        }
                    }
                }
            }
            //dynamic resizing
            if (event.type == sf::Event::Resized) {
                refreshSprite();

                sf::FloatRect view(0, 0, event.size.width, event.size.height);
                window->setView(sf::View(view));
            }
        }
        if (bouge) {
            sprite[n].setPosition(souris.x, souris.y);
        }

        window->clear(sf::Color::Cyan);
        window->draw(echiquier);

        for(int i=0; i<32; i++) {
            if(i!=n) window->draw(sprite[i]);
        }
        if(n!=-1) window->draw(sprite[n]);

        window->display();
    }
}

void IHM_Graphique::chargerEchiquier() {
    if (!damier.loadFromFile(relativePath + "echiquier.png", sf::IntRect(0, 0, 1166, 1166)))
        std::cout << "failed to load echiquier" << std::endl;

    echiquier.setTexture(damier);
    echiquier.setOrigin(echiquier.getLocalBounds().width/2,echiquier.getLocalBounds().height/2);
    echiquier.setPosition(widthWindow/2,heightWindow/2);
    echiquier.scale(widthWindow / damier.getSize().x,heightWindow / damier.getSize().y);
}

//fonction qui charge les textures et place les pieces à la bonne position
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




    configPiece(sprite[0], tourBlancTexture, tailleCase/2,tailleCase/2+tailleCase*7);
    configPiece(sprite[24], tourNoirTexture, tailleCase/2, tailleCase/2);
    configPiece(sprite[1], chevalierBlancTexture, tailleCase/2+tailleCase, tailleCase/2+tailleCase*7);
    configPiece(sprite[25], chevalierNoirTexture, tailleCase/2+tailleCase, tailleCase/2);
    configPiece(sprite[2], fouBlancTexture, tailleCase/2+tailleCase*2, tailleCase/2+tailleCase*7);
    configPiece(sprite[26], fouNoirTexture, tailleCase/2+tailleCase*2, tailleCase/2);
    configPiece(sprite[3], dameBlancTexture, tailleCase/2+tailleCase*3, tailleCase/2+tailleCase*7);
    configPiece(sprite[27], dameNoirTexture, tailleCase/2+tailleCase*3, tailleCase/2);
    configPiece(sprite[4], roiBlancTexture, tailleCase/2+tailleCase*4, tailleCase/2+tailleCase*7);
    configPiece(sprite[28], roiNoirTexture, tailleCase/2+tailleCase*4, tailleCase/2);
    configPiece(sprite[5], fouBlancTexture, tailleCase/2+tailleCase*5, tailleCase/2+tailleCase*7);
    configPiece(sprite[29], fouNoirTexture, tailleCase/2+tailleCase*5, tailleCase/2);
    configPiece(sprite[6], chevalierBlancTexture, tailleCase/2+tailleCase*6, tailleCase/2+tailleCase*7);
    configPiece(sprite[30], chevalierNoirTexture, tailleCase/2+tailleCase*6, tailleCase/2);
    configPiece(sprite[7], tourBlancTexture, tailleCase/2+tailleCase*7, tailleCase/2+tailleCase*7);
    configPiece(sprite[31], tourNoirTexture, tailleCase/2+tailleCase*7, tailleCase/2);

    for(int i=0; i<8; i++) {
        configPiece(sprite[i+8], pionBlancTexture, tailleCase/2+tailleCase*i, tailleCase/2+tailleCase*6);
        configPiece(sprite[i+16], pionNoirTexture, tailleCase/2+tailleCase*i, tailleCase/2+tailleCase*1);
    }
}

void IHM_Graphique::configPiece(sf::Sprite &spr, sf::Texture& texture, float x, float y) const {
    texture.setSmooth(true);
    spr.setTexture(texture);
    spr.setOrigin(spr.getGlobalBounds().width/2,spr.getGlobalBounds().height/2);
    spr.setPosition(x, y);
    spr.setScale(sf::Vector2f(tailleEchiquier / (8 * texture.getSize().x),
                                     tailleEchiquier / (8 * texture.getSize().x)));
}

// fonction permettant de repositionner & redimensionner les sprites apres un resize de la fenetre.
void IHM_Graphique::refreshSprite() {
    sf::Vector2u newWindowSize = sf::Vector2u(window->getSize().x, window->getSize().y);
    float newSize = std::min(newWindowSize.x,newWindowSize.y);
    float oldSize = std::min(widthWindow, heightWindow);
    float scale = newSize / oldSize;
    sf::Vector2f oldEchiquierPos = echiquier.getPosition();

    echiquier.setPosition(newWindowSize.x / 2, newWindowSize.y / 2);
    echiquier.scale(scale, scale);

    tailleEchiquier = newSize;

    for(int i=0; i<32; i++) {
        sprite[i].setPosition((newWindowSize.x/2)-scale*(oldEchiquierPos.x-sprite[i].getPosition().x),(newWindowSize.y/2)-scale*(oldEchiquierPos.y-sprite[i].getPosition().y));

        sprite[i].scale(scale, scale);
    }
    widthWindow = newWindowSize.x;
    heightWindow = newWindowSize.y;
    tailleCase=tailleEchiquier/8;

    baseEchiquier = echiquier.getPosition() - sf::Vector2f(tailleEchiquier/2,tailleEchiquier/2);
}

