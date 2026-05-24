#include <stdio.h>
#include "affichage.h"

// affiche une carte selon son type
void afficherCarte(Carte carte) {
    if (carte.type == CARTE_NUMERO) {
        printf("%d", carte.valeur);
    } else if (carte.type == CARTE_BONUS_PLUS) {
        printf("+%d", carte.valeur);
    } else {
        // forcément c'est un x2
        printf("x2");
    }
}

// affiche les infos du joueur pendant la manche
void afficherJoueur(Joueur joueur) {
    int i;
    int aUneCarte;

    aUneCarte = 0;

    printf("\n----------------------------\n");
    printf("Joueur : %s\n", joueur.pseudo);
    printf("----------------------------\n");
    printf("Score total : %d\n", joueur.scoreTotal);
    printf("Score manche : %d\n", joueur.scoreManche);

    // on affiche les cartes numero que le joueur a deja
    printf("Cartes numero : ");

    for (i = 0; i < NB_NUMEROS; i++) {
        if (joueur.cartesNumeros[i] == 1) {
            printf("%d ", i);
            aUneCarte = 1;
        }
    }

    if (aUneCarte == 0) {
        printf("aucune pour l'instant");
    }

    printf("\n");

    // on affiche les bonus
    printf("Bonus + : %d\n", joueur.bonusAddition);
    printf("Multiplicateur : x%d\n", joueur.multiplicateur);
    printf("Nb cartes differentes : %d / 7\n", joueur.nbCartesDifferentes);
}

// affiche combien de fois chaque carte numero a ete piochee
void afficherCartesPiochees(int cartesPiochees[]) {
    int i;

    printf("\nCartes deja sorties :\n");

    for (i = 0; i < NB_NUMEROS; i++) {
        if (cartesPiochees[i] > 0) {
            printf("  %d : piochee %d fois\n", i, cartesPiochees[i]);
        }
    }
}

// affiche le classement final et le nom du gagnant
void afficherScoresFinaux(Joueur joueurs[], int nbJoueurs) {
    int i;
    int indiceGagnant;

    indiceGagnant = 0;

    printf("\n============================\n");
    printf("   RESULTATS FINAUX\n");
    printf("============================\n");

    for (i = 0; i < nbJoueurs; i++) {
        printf("%s : %d points\n", joueurs[i].pseudo, joueurs[i].scoreTotal);

        // on cherche qui a le plus grand score
        if (joueurs[i].scoreTotal > joueurs[indiceGagnant].scoreTotal) {
            indiceGagnant = i;
        }
    }

    printf("\nFelicitations a %s qui gagne avec %d points !\n",
           joueurs[indiceGagnant].pseudo,
           joueurs[indiceGagnant].scoreTotal);
}
