#include <stdio.h>
#include "joueur.h"
#include "utils.h"

// on demande le pseudo de chaque joueur et on met tout a 0
void initialiserJoueurs(Joueur joueurs[], int nbJoueurs) {
    int i;

    for (i = 0; i < nbJoueurs; i++) {
        printf("Entrez le pseudo du joueur %d : ", i + 1);
        scanf("%49s", joueurs[i].pseudo);
        viderBuffer();

        // au debut tout le monde part a 0
        joueurs[i].scoreTotal = 0;
        joueurs[i].scoreManche = 0;
    }
}

// on remet a zero les infos de manche mais pas le score total
void initialiserManche(Joueur joueurs[], int nbJoueurs) {
    int i;
    int j;

    for (i = 0; i < nbJoueurs; i++) {
        joueurs[i].scoreManche = 0;
        joueurs[i].nbCartesDifferentes = 0;
        joueurs[i].bonusAddition = 0;
        joueurs[i].multiplicateur = 1;  // multiplicateur de base = 1 (pas x2)
        joueurs[i].actif = 1;
        joueurs[i].perdu = 0;

        // on efface toutes les cartes numero du joueur
        for (j = 0; j < NB_NUMEROS; j++) {
            joueurs[i].cartesNumeros[j] = 0;
        }
    }
}
