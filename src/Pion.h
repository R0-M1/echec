#ifndef ECHEC_PION_H
#define ECHEC_PION_H

#include "Piece.h"

class Pion :public Piece {
public:
    Pion(CouleurPiece c, PositionPiece p);
    ~Pion();
    bool MouvementValide(PositionPiece versPos);

private:
    bool doubleSaut;
};



#endif
