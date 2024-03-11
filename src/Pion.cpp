#include "Pion.h"
#include <iostream>
using namespace std;


Pion::Pion(bool co):Piece(co){
    id = pion;
}

bool Pion::coup_valide(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, const Echiquier &echiquier) const
{
    int sens;
    if (!couleur)
        sens = 1;
    else
        sens = -1;
    
    if (y_actuel == 1 + ((int)couleur) * 5 && x_coup == x_actuel && (y_coup == 3 + (int)couleur) && !(echiquier.presence_piece(x_coup, y_coup +1+(int)!couleur*(-2))))
        return true;
    if (echiquier.coup_valide_diagonal(x_actuel, y_actuel, x_coup, y_coup) && (y_coup == y_actuel + sens) && echiquier.presence_piece(x_coup, y_coup))
        return true;
    if ((x_coup == x_actuel && y_coup == y_actuel + sens) && (!echiquier.presence_piece(x_coup, y_coup)))
    {
        return true;}

    return false;
}
