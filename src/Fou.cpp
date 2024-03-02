#include "Fou.h"

Fou::Fou(CouleurPiece c, PositionPiece p) {
    type = fou;
    couleur = c;
    position = p;
}

Fou::~Fou() {

}

/* Vérifie si la piece peut se déplacer vers la destination
 * Renvoie un bool (Mouvement valide : true, Mouvement non valide : false)
 */
bool Fou::CoupValide(PositionPiece versPos) {
    return false;
}
