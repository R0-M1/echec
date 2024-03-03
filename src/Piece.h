#ifndef _PIECE_
#define _PIECE_

enum TypePiece {pion, fou, cavalier, tour, dame, roi};
enum CouleurPiece {blanc, noir};

typedef unsigned short int entier;

typedef struct Coordonnees {
    entier xpos;
    entier ypos;
} PositionPiece;

class Piece {
public:
    Piece();
    ~Piece();

    CouleurPiece getCouleur();
    PositionPiece getPosition();
    void setPosition(PositionPiece pos);

protected:
    CouleurPiece couleur;
    TypePiece type;
    PositionPiece position;

};








#endif