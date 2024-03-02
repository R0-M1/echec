#ifndef ECHEC_ROI_H
#define ECHEC_ROI_H

#include "Piece.h"

class Roi : public Piece {
public:
    Roi(CouleurPiece c, PositionPiece p);
    ~Roi();

    bool CoupValide(PositionPiece versPos);

};


#endif
