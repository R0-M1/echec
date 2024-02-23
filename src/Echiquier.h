#ifndef _ECHIQUIER_
#define _ECHIQUIER_

#include  "Piece.h"


class Echiquier
{
    
public:
    Piece* plateau[8][8];
    
    Echiquier();
    ~Echiquier();
    void initialisation();
    bool est_dans_Echiquier(entier x, entier y)const;
    bool presence_piece(entier x, entier y)const;
    bool coup_valide_diagonal(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup)const;
    bool coup_valide_horizontal(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup)const;
    bool coup_valide_vertical(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup)const;
    //changer peut etre le type pour indiquer quelle piece a été "mangée"
    //void coup(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup);


    

};












#endif