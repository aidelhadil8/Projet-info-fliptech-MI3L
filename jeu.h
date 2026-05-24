#ifndef JEU_H
#define JEU_H

#include "types.h"

// calcule les scores a la fin d'une manche et les affiche
void calculerScoresFinManche(Joueur joueurs[], int nbJoueurs);

// fait jouer une manche complete
void jouerManche(Joueur joueurs[], int nbJoueurs, Carte pioche[], int *indicePioche, int cartesPiochees[]);

// renvoie 1 si la partie est terminee, 0 sinon
int partieFinie(Joueur joueurs[], int nbJoueurs, int indicePioche);

#endif
