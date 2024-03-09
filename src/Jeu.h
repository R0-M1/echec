#ifndef ECHEC_JEU_H
#define ECHEC_JEU_H

#include "Echiquier.h"

class Jeu {
    public:
         //verifie apres chaque tour si il y a un echec et mat
        Echiquier echiquier;
        bool couleur;

        Jeu();
        void initialisation_Echiquier();
        bool EchecEtMat()const;
        void changer_couleur();
        void jouer_coup();
        entier get_xRoi(bool co)const;
        entier get_yRoi(bool co)const;
        bool get_couleur_Piece(entier x, entier y)const;
        type_piece get_id_Piece(entier x, entier y)const;
        bool presence_piece(entier x, entier y) const;
        bool coup(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup);

};


#endif
