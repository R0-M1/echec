#ifndef _PIECE_
#define _PIECE_



class Echiquier;

enum type_piece {pion, fou, cavalier, tour, dame, roi, vide};
typedef unsigned short int entier;

class Piece
{
    public:
        bool couleur;
        type_piece id;
        Piece(bool co);

        virtual bool coup_valide(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, const Echiquier& echiquier)const;
        bool get_couleur()const;
        type_piece get_id()const;
        
};








#endif