#include "Piece.h"


Piece::Piece(bool co):couleur(co){}

bool Piece::coup_valide(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, const Echiquier& echiquier)const {
    return 1;
}

bool Piece::get_couleur()const{
        return couleur;
    }


type_piece Piece::get_id()const{
    return id;
}

