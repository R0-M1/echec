#ifndef ECHEC_CAVALIER_H
#define ECHEC_CAVALIER_H

#include "Piece.h"

class Cavalier : public Piece {
public:
    Cavalier(CouleurPiece c, PositionPiece p);
    ~Cavalier();

    bool coupValide(PositionPiece versPos);
};


#endif
