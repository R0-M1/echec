#ifndef ECHEC_FOU_H
#define ECHEC_FOU_H

#include "Piece.h"

class Fou : public Piece {
public:
    Fou(CouleurPiece c, PositionPiece p);
    ~Fou();

    bool CoupValide(PositionPiece versPos);
};


#endif
