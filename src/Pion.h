#ifndef ECHEC_PION_H
#define ECHEC_PION_H

#include "Piece.h"

class Pion : public Piece {
public:
    Pion(CouleurPiece c, PositionPiece p, Echiquier *e);
    ~Pion();

    bool coupValide(PositionPiece versPos);

private:
    bool doubleMouvement;
};



#endif
