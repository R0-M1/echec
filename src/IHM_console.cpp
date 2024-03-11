#include "IHM_console.h"

void IHM_console::afficherEchiquier() const
{   
    cout << endl << " ";
    for (entier k = 0; k < 8; k++)
        cout << " " << k << " |";
    cout << "\n";
    TypePiece id;
    bool couleur;
    for (entier j = 0; j < 8; j++)
    {
        cout << " ";
        for (entier i = 0; i < 8; i++)
        {
            if (!jeu.presencePiece(i, j))
                cout << " " << symbole[0][vide] << " |";
            else{
                id = jeu.getTypePiece(i, j);
                couleur = jeu.getCouleurPiece(i, j);
                cout << " " << symbole[couleur][id] << " |";
                }
        }
        cout << j << endl;
    }
}

void IHM_console::boucleJeu()
{
    bool coup, reste = true;
    jeu.initialisation();
    int x_actuel, y_actuel, x_coup, y_coup;
    afficherEchiquier();
    while (reste)
    {
        do
        {
            
            cout << "entrez les coordonnées de la piece: " << endl;
            cin >> x_actuel >> y_actuel;
            cout << "entrez les coordonnées du coup: " << endl;
            cin >> x_coup >> y_coup;
            coup = jeu.coup(x_actuel, y_actuel, x_coup, y_coup);
            cout << coup << endl;
        } while (!coup);

        jeu.changerCouleur();
        afficherEchiquier();
        cout << "tapez 1 pour continuer ou 0 pour arreter" << endl;
        cin >> reste;
    }
}