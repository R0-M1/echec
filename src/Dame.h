#ifndef _DAME_
#define _DAME_

#include "Piece.h"

class Dame : public Piece {
public:
    Dame(CouleurPiece c, PositionPiece p);
    ~Dame();

    bool CoupValide(PositionPiece versPos);
}; 





#endif