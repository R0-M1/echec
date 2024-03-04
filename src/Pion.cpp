#include "Pion.h"
#include "Echiquier.h"


Pion::Pion(CouleurPiece c, PositionPiece p, Echiquier *e) {
    type = pion;
    couleur = c;
    position = p;
    echiquier = e;
    doubleMouvement = true;
}

Pion::~Pion() {

}

/* Vérifie si la piece peut se déplacer vers la destination
 * Renvoie un bool (Mouvement valide : true, Mouvement non valide : false)
 */
bool Pion::coupValide(PositionPiece versPos) {
    if(echiquier->getPiece(versPos)== nullptr) {
        return true;
    }


    return false;
}
