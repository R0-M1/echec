
#ifndef _ECHIQUIER_
#define _ECHIQUIER_

#include  "Piece.h"



class Echiquier
{
    
public:
    Piece* plateau[8][8];
    entier xRoi_blanc, xRoi_noir, yRoi_blanc, yRoi_noir;
    //ptet un tab 2D pour les pieces mangées


    
    Echiquier();
    ~Echiquier();
    void initialisation_Echiquier();
    bool est_dans_Echiquier(entier x, entier y)const;
    bool presence_piece(entier x, entier y)const;
    Piece* get_Piece(entier x, entier y)const;
    bool coup_valide_diagonal(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup)const;
    bool coup_valide_horizontal(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup)const;
    bool coup_valide_vertical(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup)const;
    bool sont_ennemi(entier x_p1, entier y_p1, entier x_p2, entier y_p2)const;
        //changer peut etre le type pour indiquer quelle piece a été "mangée"
    bool coup(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, bool couleur);
    bool Roi_en_echec(entier x_roi, entier y_roi) const;
    entier get_xRoi(bool co)const;
    entier get_yRoi(bool co)const;
    bool get_couleur_Piece(entier x, entier y)const;
    type_piece get_id_Piece(entier x, entier y)const;
    


    

};


#endif