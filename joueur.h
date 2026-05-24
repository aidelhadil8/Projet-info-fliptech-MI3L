#ifndef JOUEUR_H
#define JOUEUR_H

#include "types.h"

// demande les pseudos et met les scores a 0 au debut
void initialiserJoueurs(Joueur joueurs[], int nbJoueurs);

// remet a zero les infos de la manche (pas le score total)
void initialiserManche(Joueur joueurs[], int nbJoueurs);

#endif
