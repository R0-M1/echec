#include "Roi.h"

Roi::Roi(CouleurPiece c, PositionPiece p) {
    type = roi;
    couleur = c;
    position = p;
}

Roi::~Roi() {

}

bool Roi::coupValide(PositionPiece versPos) {
    return false;
}
