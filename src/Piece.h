#ifndef _PIECE_
#define _PIECE_

enum TypePiece {pion, fou, cavalier, tour, dame, roi};
enum CouleurPiece {blanc, noir};

typedef unsigned short int entier;

typedef struct Coordonnees {
    int xpos;
    int ypos;
} PositionPiece;

class Piece
{
public:
    Piece();
    ~Piece();

protected:
    CouleurPiece couleur;
    TypePiece type;
    PositionPiece position;

};








#endif