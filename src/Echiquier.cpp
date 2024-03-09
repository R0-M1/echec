
#include "Echiquier.h"
#include "Pion.h"
#include "Tour.h"
#include "Fou.h"
#include "Cavalier.h"
#include "Dame.h"
#include "Roi.h"
#include <iostream>
using namespace std;

Echiquier::Echiquier()
{

    for (entier i = 0; i < 8; i++)
        for (entier j = 0; j < 8; j++)
            plateau[i][j] = nullptr;
}

Echiquier::~Echiquier()
{

    for (entier i = 0; i < 8; i++)
        for (entier j = 0; j < 8; j++)
            if (presence_piece(i, j))
                delete plateau[i][j];
}

void Echiquier::initialisation_Echiquier() //a corriger (new utilisé plusieurs fois sur la meme piece)
{
    entier i, j;
    for (i = 0; i < 8; i++)
    {
        plateau[i][1] = new Pion(0);
        plateau[i][6] = new Pion(1);
    }

    for (i = 0; i < 8; i += 7)
        for (j = 0; j < 8; j += 7)
            plateau[i][j] = new Tour(j);

    for (i = 1; i < 8; i += 5)
        for (j = 0; j < 8; j += 7)
            plateau[i][j] = new Cavalier(j);

    for (i = 2; i < 6; i += 3)
        for (j = 0; j < 8; j += 7)
            plateau[i][j] = new Fou(j);

    for (j = 0; j < 8; j += 7)
    {
        plateau[3][j] = new Dame(j);
        plateau[4][j] = new Roi(j);
    }

    xRoi_noir = 4;
    xRoi_blanc = 4;
    yRoi_noir = 7;
    yRoi_blanc = 0;
}

entier Echiquier::get_xRoi(bool co) const
{
    if (co)
        return xRoi_noir;
    else
        return xRoi_blanc;
}

entier Echiquier::get_yRoi(bool co) const
{
    if (co)
        return yRoi_noir;
    else
        return yRoi_blanc;
}

type_piece Echiquier::get_id_Piece(entier x, entier y) const
{
    if (presence_piece(x, y))
        return plateau[x][y]->get_id();
    return vide;
}

bool Echiquier::get_couleur_Piece(entier x, entier y) const
{
    return plateau[x][y]->get_couleur();
}

bool Echiquier::est_dans_Echiquier(entier x, entier y) const
{
    return ((x < 64 && x >= 0) && (y < 64 && y >= 0));
}

bool Echiquier::presence_piece(entier x, entier y) const
{

    return (plateau[x][y] != nullptr);
}

Piece *Echiquier::get_Piece(entier x, entier y) const
{

    return plateau[x][y];
}

bool Echiquier::coup_valide_diagonal(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup) const
{

    if (((x_actuel - x_coup) * (x_actuel - x_coup)) != ((y_actuel - y_coup) * (y_actuel - y_coup)))
        return false;

    entier sensx, sensy;
    if (x_actuel < x_coup)
        sensx = 1;
    else
        sensx = -1;
    if (y_actuel < y_coup)
        sensy = 1;
    else
        sensy = -1;
    x_actuel += sensx;
    y_actuel += sensy;

    while ((x_actuel != x_coup) && (y_actuel != y_coup))
    {
        if (presence_piece(x_actuel, y_actuel))
            return false;

        x_actuel += sensx;
        y_actuel += sensy;
    }
    return true;
}

bool Echiquier::coup_valide_horizontal(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup) const
{

    if (y_actuel != y_coup)
        return false;

    int sensx;
    if (x_actuel < x_coup)
        sensx = 1;
    else
        sensx = -1;
    x_actuel += sensx;
    while (x_actuel != x_coup)
    {
        if (presence_piece(x_actuel, y_actuel))
            return false;

        x_actuel += sensx;
    }
    return true;
}

bool Echiquier::coup_valide_vertical(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup) const
{

    if (x_actuel != x_coup)
        return false;

    int sensy;
    if (y_actuel < y_coup)
        sensy = 1;
    else
        sensy = -1;
    y_actuel += sensy;
    while (y_actuel != y_coup)
    {
        if (presence_piece(x_actuel, y_actuel))
            return false;

        y_actuel += sensy;
    }
    return true;
}

bool Echiquier::sont_ennemi(entier x_p1, entier y_p1, entier x_p2, entier y_p2) const
{
    return (plateau[x_p1][y_p1]->get_couleur() != plateau[x_p2][y_p2]->get_couleur());
}

bool Echiquier::coup(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, bool couleur)
{
    if (!presence_piece(x_actuel, y_actuel))
    {
        return false;
    }
    if (plateau[x_actuel][y_actuel]->get_couleur()!=couleur){
        return false;
    }
    if (!plateau[x_actuel][y_actuel]->coup_valide(x_actuel, y_actuel, x_coup, y_coup, *this))
    {
        cout << "oui" << endl; // TODO c'est quoi ça ??
        return false;
    }
    if (presence_piece(x_coup, y_coup))
    {

        if (sont_ennemi(x_actuel, y_actuel, x_coup, y_coup))
        {
            delete plateau[x_coup][y_coup];
            plateau[x_coup][y_coup] = plateau[x_actuel][y_actuel];
            plateau[x_actuel][y_actuel] = nullptr;
            // information sur la pièce prise revenir plus tard retourner l'ientifiant/type de la piece
            return true;
        }

        // condition du else ils st pas ennemi ptet faut renvoyer un msg
        else
        {
            
            return false;
        }
    }
    else
    {
        plateau[x_coup][y_coup] = plateau[x_actuel][y_actuel];
        plateau[x_actuel][y_actuel] = nullptr;
        return true;
    }

    return false;
}

bool Echiquier::Roi_en_echec(entier x_roi, entier y_roi) const
{
    bool couleur_Roi = plateau[x_roi][y_roi]->get_couleur();
    for (entier i = 0; i < 8; i++)
        for (entier j = 0; j < 8; j++)
            if (presence_piece(i, j))
            {
                if ((plateau[i][j]->get_couleur() != couleur_Roi) && (plateau[i][j]->coup_valide(i, j, x_roi, y_roi, *this)))
                {
                    return true;
                }
            }

    return false;
}