#include "IHM_console.h"

void IHM_console::afficher_echiquier() const
{   
    cout << endl << " ";
    for (entier k = 0; k < 8; k++)
        cout << " " << k << " |";
    cout << "\n";
    type_piece id;
    bool couleur;
    for (entier j = 0; j < 8; j++)
    {
        cout << " ";
        for (entier i = 0; i < 8; i++)
        {
            if (!jeu.presence_piece(i, j))
                cout << " " << skin[0][vide] << " |";
            else{
                id = jeu.get_id_Piece(i, j);
                couleur = jeu.get_couleur_Piece(i, j);
                cout << " " << skin[couleur][id] << " |";
                }
        }
        cout << j << endl;
    }
}

void IHM_console::boucle_Jeu()
{
    bool coup, reste = true;
    jeu.initialisation_Echiquier();
    int x_actuel, y_actuel, x_coup, y_coup;
    afficher_echiquier();
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

        jeu.changer_couleur();
        afficher_echiquier();
        cout << "tapez 1 pour continuer ou 0 pour arreter" << endl;
        cin >> reste;
    }
}