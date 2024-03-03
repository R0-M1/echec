#include "Dame.h"

Dame::Dame(CouleurPiece c, PositionPiece p) {
    type = dame;
    couleur = c;
    position = p;
}

Dame::~Dame() {

}

/* Vérifie si la piece peut se déplacer vers la destination
 * Renvoie un bool (Mouvement valide : true, Mouvement non valide : false)
 */
bool Dame::coupValide(PositionPiece versPos) {
    return false;
}
