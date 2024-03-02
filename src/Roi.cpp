#include "Roi.h"

Roi::Roi(CouleurPiece c, PositionPiece p) {
    type = roi;
    couleur = c;
    position = p;
}

Roi::~Roi() {

}

bool Roi::CoupValide(PositionPiece versPos) {
    return false;
}
