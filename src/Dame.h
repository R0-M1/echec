#ifndef _DAME_
#define _DAME_


#include "Echiquier.h"
#include "Piece.h"


class Dame: public Piece
{
    public:
    bool coup_valide(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, Echiquier echiquier)const;
    

    
}; 





#endif