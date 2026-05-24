#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "types.h"

// affiche une carte (son type et sa valeur)
void afficherCarte(Carte carte);

// affiche toutes les infos d'un joueur
void afficherJoueur(Joueur joueur);

// affiche quelles cartes numero ont deja ete piochees
void afficherCartesPiochees(int cartesPiochees[]);

// affiche les scores a la fin et dit qui a gagne
void afficherScoresFinaux(Joueur joueurs[], int nbJoueurs);

#endif
