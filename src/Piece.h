#ifndef _PIECE_
#define _PIECE_
class Echiquier;

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
    TypePiece getType();
    void setPosition(PositionPiece pos);
    virtual bool coupValide(PositionPiece versPos) = 0;

protected:
    CouleurPiece couleur;
    TypePiece type;
    PositionPiece position;
    Echiquier* echiquier;
};








#endif