#include "Jeu.h"

Jeu::Jeu() {

}

Jeu::Jeu(sf::RenderWindow *window) {
    IHM_Graphique *affichage = new IHM_Graphique(window);
}

void Jeu::demarrer() {
    affichage->afficheEchiquier();


}


