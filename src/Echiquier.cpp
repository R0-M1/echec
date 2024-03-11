
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
            if (presencePiece(i, j))
                delete plateau[i][j];
}

void Echiquier::initialisation() //a corriger (new utilisé plusieurs fois sur la meme piece)
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

entier Echiquier::getXRoi(bool co) const
{
    if (co)
        return xRoi_noir;
    else
        return xRoi_blanc;
}

entier Echiquier::getYRoi(bool co) const
{
    if (co)
        return yRoi_noir;
    else
        return yRoi_blanc;
}

TypePiece Echiquier::getTypePiece(entier x, entier y) const
{
    if (presencePiece(x, y))
        return plateau[x][y]->getType();
    return vide;
}

bool Echiquier::getCouleurPiece(entier x, entier y) const
{
    return plateau[x][y]->getCouleur();
}

bool Echiquier::estDansEchiquier(entier x, entier y) const
{
    return ((x < 64 && x >= 0) && (y < 64 && y >= 0));
}

bool Echiquier::presencePiece(entier x, entier y) const
{

    return (plateau[x][y] != nullptr);
}

Piece *Echiquier::getPiece(entier x, entier y) const
{

    return plateau[x][y];
}

bool Echiquier::coupValideDiagonal(entier xActuel, entier yActuel, entier xCoup, entier yCoup) const
{

    if (((xActuel - xCoup) * (xActuel - xCoup)) != ((yActuel - yCoup) * (yActuel - yCoup)))
        return false;

    entier sensx, sensy;
    if (xActuel < xCoup)
        sensx = 1;
    else
        sensx = -1;
    if (yActuel < yCoup)
        sensy = 1;
    else
        sensy = -1;
    xActuel += sensx;
    yActuel += sensy;

    while ((xActuel != xCoup) && (yActuel != yCoup))
    {
        if (presencePiece(xActuel, yActuel))
            return false;

        xActuel += sensx;
        yActuel += sensy;
    }
    return true;
}

bool Echiquier::coupValideHorizontal(entier xActuel, entier yActuel, entier xCoup, entier yCoup) const
{

    if (yActuel != yCoup)
        return false;

    int sensx;
    if (xActuel < xCoup)
        sensx = 1;
    else
        sensx = -1;
    xActuel += sensx;
    while (xActuel != xCoup)
    {
        if (presencePiece(xActuel, yActuel))
            return false;

        xActuel += sensx;
    }
    return true;
}

bool Echiquier::coupValideVertical(entier xActuel, entier yActuel, entier xCoup, entier yCoup) const
{

    if (xActuel != xCoup)
        return false;

    int sensy;
    if (yActuel < yCoup)
        sensy = 1;
    else
        sensy = -1;
    yActuel += sensy;
    while (yActuel != yCoup)
    {
        if (presencePiece(xActuel, yActuel))
            return false;

        yActuel += sensy;
    }
    return true;
}

bool Echiquier::sontEnnemi(entier xP1, entier yP1, entier xP2, entier yP2) const
{
    return (plateau[xP1][yP1]->getCouleur() != plateau[xP2][yP2]->getCouleur());
}

bool Echiquier::coup(entier xActuel, entier yActuel, entier xCoup, entier yCoup, bool couleur)
{
    if (!presencePiece(xActuel, yActuel))
    {
        return false;
    }
    if (plateau[xActuel][yActuel]->getCouleur() != couleur){
        return false;
    }
    if (!plateau[xActuel][yActuel]->coupValide(xActuel, yActuel, xCoup, yCoup, *this))
    {
        cout << "oui" << endl; // TODO c'est quoi ça ??
        return false;
    }
    if (presencePiece(xCoup, yCoup))
    {

        if (sontEnnemi(xActuel, yActuel, xCoup, yCoup))
        {
            delete plateau[xCoup][yCoup];
            plateau[xCoup][yCoup] = plateau[xActuel][yActuel];
            plateau[xActuel][yActuel] = nullptr;
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
        plateau[xCoup][yCoup] = plateau[xActuel][yActuel];
        plateau[xActuel][yActuel] = nullptr;
        return true;
    }

    return false;
}

bool Echiquier::roiEnEchec(entier xRoi, entier yRoi) const
{
    bool couleur_Roi = plateau[xRoi][yRoi]->getCouleur();
    for (entier i = 0; i < 8; i++)
        for (entier j = 0; j < 8; j++)
            if (presencePiece(i, j))
            {
                if ((plateau[i][j]->getCouleur() != couleur_Roi) && (plateau[i][j]->coupValide(i, j, xRoi, yRoi,
                                                                                               *this)))
                {
                    return true;
                }
            }

    return false;
}