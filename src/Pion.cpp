#include "Pion.h"

Pion::Pion(CouleurPiece c, PositionPiece p) {
    type = pion;
    couleur = c;
    position = p;
    doubleMouvement = true;
}

Pion::~Pion() {

}

/* Vérifie si la piece peut se déplacer vers la destination
 * Renvoie un bool (Mouvement valide : true, Mouvement non valide : false)
 */
bool Pion::coupValide(PositionPiece versPos) {
    return false;
}
