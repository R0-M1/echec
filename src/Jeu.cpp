#include "Jeu.h"


Jeu::Jeu(){
    couleur = false;
}

void Jeu::initialisation_Echiquier(){
    echiquier.initialisation_Echiquier();
}

void Jeu::changer_couleur(){
    couleur = !couleur;
}

bool Jeu::EchecEtMat()const{
    return 1;
}

entier Jeu::get_xRoi(bool co)const{
    return echiquier.get_xRoi(co);
}
entier Jeu::get_yRoi(bool co)const{
    return echiquier.get_yRoi(co);
}
bool Jeu::get_couleur_Piece(entier x, entier y)const{

    return echiquier.get_couleur_Piece(x, y);
}
type_piece Jeu::get_id_Piece(entier x, entier y)const{
    return echiquier.get_id_Piece(x, y);
}

bool Jeu::presence_piece(entier x, entier y) const
{

    return  echiquier.presence_piece(x, y);
}

bool Jeu::coup(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup){
            return echiquier.coup(x_actuel, y_actuel, x_coup, y_coup, couleur);
        }