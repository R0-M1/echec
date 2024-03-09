#include "Dame.h"


Dame::Dame(bool co):Piece(co){
    id = dame;
}

bool Dame::coup_valide(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, const Echiquier& echiquier)const{

    return ((echiquier.est_dans_Echiquier(x_coup, y_coup)) && (echiquier.coup_valide_diagonal(x_actuel, y_actuel, x_coup, y_coup) || 
        echiquier.coup_valide_horizontal(x_actuel, y_actuel, x_coup, y_coup) || echiquier.coup_valide_vertical(x_actuel, y_actuel, x_coup, y_coup)));
}


