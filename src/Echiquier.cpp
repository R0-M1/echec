#include "Echiquier.h"


Echiquier::Echiquier() {
    for (entier i = 0; i < 8; i++) {
        for (entier j = 0; j < 8; j++) {
            plateau[i][j] = nullptr;
        }
    }
}

Echiquier::~Echiquier() {
    for (entier i = 0; i < 8; i++) {
        for (entier j = 0; j < 8; j++) {
            delete plateau[i][j];
            plateau[i][j] = nullptr;
        }
    }
}

void Echiquier::initialisation() {
    for(int col = 0; col < 8; col++) {
        plateau[1][col] = new Pion(blanc, {1,col});
        plateau[6][col] = new Pion(noir, {6,col});
    }
    //blanc
    plateau[0][0] = new Tour(blanc, {0,0});
    plateau[0][1] = new Cavalier(blanc, {0,1});
    plateau[0][2] = new Fou(blanc, {0,2});
    plateau[0][3] = new Dame(blanc, {0,3});
    plateau[0][4] = new Roi(blanc, {0,4});
    plateau[0][5] = new Fou(blanc, {0,5});
    plateau[0][6] = new Cavalier(blanc, {0,6});
    plateau[0][7] = new Tour(blanc, {0,7});

    //noir
    plateau[7][0] = new Tour(noir, {7,0});
    plateau[7][1] = new Cavalier(noir, {7,1});
    plateau[7][2] = new Fou(noir, {7,2});
    plateau[7][3] = new Dame(noir, {7,3});
    plateau[7][4] = new Roi(noir, {7,4});
    plateau[7][5] = new Fou(noir, {7,5});
    plateau[7][6] = new Cavalier(noir, {7,6});
    plateau[7][7] = new Tour(noir, {7,7});
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




