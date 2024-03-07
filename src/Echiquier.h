#ifndef _ECHIQUIER_
#define _ECHIQUIER_


#include "Piece.h"
#include "Pion.h"
#include "Roi.h"
#include "Dame.h"
#include "Tour.h"
#include "Fou.h"
#include "Cavalier.h"

class Echiquier {
private:
    Piece* plateau[8][8]; // plateau[x][y], x correspond aux lignes et y aux colonnes. La case C1 correspond à plateau[0][2]
    //peut etre rajouté un bool "aBougé"

public:
    Echiquier();
    ~Echiquier();
    void initialisation();
    Piece* getPiece(PositionPiece pos);
    bool caseVide(PositionPiece pos);
    bool estDansEchiquier(PositionPiece pos) const;

    //appelle les fonctions coupValide en fonction du type de Piece
    bool deplacerPiece(PositionPiece depuisPos, PositionPiece versPos);
};


#endif