#ifndef _IHMC_
#define _IHMC_

#include "Echiquier.h"
#include "Jeu.h"

#include <string>
#include <iostream>

using namespace std;

class IHM_console
{

public:
    string skin[2][7] = { {"♙", "♗", "♘", "♖", "♕", "♔", " "}, {"♟", "♝", "♞", "♜", "♛", "♚", " "}};
    Jeu jeu;

    void afficher_echiquier() const;
    void boucle_Jeu();
};

#endif