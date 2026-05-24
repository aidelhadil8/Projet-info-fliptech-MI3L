#include <stdlib.h>
#include <time.h>
#include "pioche.h"

// on remplit le tableau avec toutes les cartes du jeu
// il y a 85 cartes en tout (on a verifié avec les regles)
void creerPioche(Carte pioche[]) {
    int indice;
    int valeur;
    int repetition;

    indice = 0;

    // la carte 0 (il y en a qu'une seule)
    pioche[indice].type = CARTE_NUMERO;
    pioche[indice].valeur = 0;
    indice++;

    // la carte 1 (il y en a qu'une seule aussi)
    pioche[indice].type = CARTE_NUMERO;
    pioche[indice].valeur = 1;
    indice++;

    // pour les cartes 2 a 12 : la carte N apparait N fois
    // donc 2 cartes "2", 3 cartes "3", etc jusqu'a 12 cartes "12"
    for (valeur = 2; valeur <= 12; valeur++) {
        for (repetition = 0; repetition < valeur; repetition++) {
            pioche[indice].type = CARTE_NUMERO;
            pioche[indice].valeur = valeur;
            indice++;
        }
    }

    // la carte bonus x2
    pioche[indice].type = CARTE_BONUS_X2;
    pioche[indice].valeur = 2;
    indice++;

    // les cartes bonus +
    pioche[indice].type = CARTE_BONUS_PLUS;
    pioche[indice].valeur = 2;
    indice++;

    pioche[indice].type = CARTE_BONUS_PLUS;
    pioche[indice].valeur = 4;
    indice++;

    pioche[indice].type = CARTE_BONUS_PLUS;
    pioche[indice].valeur = 6;
    indice++;

    pioche[indice].type = CARTE_BONUS_PLUS;
    pioche[indice].valeur = 8;
    indice++;

    pioche[indice].type = CARTE_BONUS_PLUS;
    pioche[indice].valeur = 10;
    // on incremente plus indice ici car c'est la derniere carte
}

// on melange la pioche avec rand()
// on utilise srand avec le temps pour que ce soit different a chaque partie
void melangerPioche(Carte pioche[]) {
    int i;
    int j;
    Carte temp;

    srand(time(NULL));

    // algorithme de melange simple : on echange chaque carte avec une autre au hasard
    for (i = 0; i < NB_CARTES; i++) {
        j = rand() % NB_CARTES;

        temp = pioche[i];
        pioche[i] = pioche[j];
        pioche[j] = temp;
    }
}
