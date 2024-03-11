#include "Jeu.h"


Jeu::Jeu(){
    couleur = false;
}

void Jeu::initialisation(){
    echiquier.initialisation();
}

void Jeu::changerCouleur(){
    couleur = !couleur;
}

bool Jeu::echecEtMat()const{
    return 1;
}

entier Jeu::get_xRoi(bool co)const{
    return echiquier.getXRoi(co);
}
entier Jeu::get_yRoi(bool co)const{
    return echiquier.getYRoi(co);
}
bool Jeu::getCouleurPiece(entier x, entier y)const{

    return echiquier.getCouleurPiece(x, y);
}
TypePiece Jeu::getTypePiece(entier x, entier y)const{
    return echiquier.getTypePiece(x, y);
}

bool Jeu::presencePiece(entier x, entier y) const
{

    return echiquier.presencePiece(x, y);
}

bool Jeu::coup(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup){
            return echiquier.coup(x_actuel, y_actuel, x_coup, y_coup, couleur);
        }