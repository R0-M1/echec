#ifndef ECHEC_TOUR_H
#define ECHEC_TOUR_H

#include "Piece.h"

class Tour : public Piece {
public:
    Tour(CouleurPiece c, PositionPiece p);
    ~Tour();

    bool coupValide(PositionPiece versPos);
};


#endif
