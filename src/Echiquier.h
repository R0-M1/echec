#ifndef _ECHIQUIER_
#define _ECHIQUIER_

#include "Piece.h"
#include "Pion.h"
#include "Roi.h"
#include "Dame.h"
#include "Tour.h"
#include "Fou.h"
#include "Cavalier.h"

class Echiquier
{
private:
    Piece* plateau[8][8]; // plateau[x][y], x correspond aux lignes et y aux colonnes. La case C1 correspond à plateau[0][2]

    
public:

    
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