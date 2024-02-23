
#include "Echiquier.h"


Echiquier::Echiquier(){

    for (entier i = 0; i < 8; i++)
        for (entier j = 0; j < 8; j++)
            plateau[i][j] = nullptr;
            
}

Echiquier::~Echiquier(){

    //libearttion de la memoire des 32 pièces faut surtout pas oublier
}

bool Echiquier::est_dans_Echiquier(entier x, entier y)const{
    return (x<64 && x>=0) && (y<64 && y>=0);
}

bool Echiquier::presence_piece(entier x, entier y)const{

    return (plateau[x][y] != nullptr);
}

bool Echiquier::coup_valide_diagonal(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup)const{

    if (((x_actuel - x_coup)*(x_actuel - x_coup)) != ((y_actuel - y_coup)*(y_actuel - y_coup)))
        return false;

    entier sensx, sensy;
    if (x_actuel < x_coup ) sensx = 1; else sensx = -1;
    if (y_actuel < y_coup ) sensy = 1; else sensy = -1;
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

bool Echiquier::coup_valide_horizontal(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup)const{

    if (y_actuel != y_coup)
        return true;

    int sensx;
    if (x_actuel < x_coup ) sensx = 1; else sensx = -1;

    while (x_actuel != x_coup)
    {
        if (presence_piece(x_actuel, y_actuel))
            return false;
        
        x_actuel += sensx;
    }
    return true;
    
}


bool Echiquier::coup_valide_vertical(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup)const{

    if (x_actuel != x_coup)
        return true;

    int sensy;
    if (y_actuel < y_coup ) sensy = 1; else sensy = -1;

    while (y_actuel != y_coup)
    {
        if (presence_piece(x_actuel, y_actuel))
            return false;
        
        y_actuel += sensy;
    }
    return true;
    
}




