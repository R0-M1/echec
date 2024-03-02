#include "Cavalier.h"

Cavalier::Cavalier(CouleurPiece c, PositionPiece p) {
    type = cavalier;
    couleur = c;
    position = p;
}

Cavalier::~Cavalier() {

}

/* Vérifie si la piece peut se déplacer vers la destination
 * Renvoie un bool (Mouvement valide : true, Mouvement non valide : false)
 */
bool Cavalier::CoupValide(PositionPiece versPos) {
    return false;
}
