#include <stdio.h>
#include "types.h"
#include "utils.h"
#include "joueur.h"
#include "pioche.h"
#include "jeu.h"
#include "affichage.h"


int main() {
    Joueur joueurs[MAX_JOUEURS];
    Carte pioche[NB_CARTES];
    int cartesPiochees[NB_NUMEROS];

    int nbJoueurs;
    int indicePioche;
    int i;

    indicePioche = 0;

    // au debut aucune carte n'a ete piochee
    for (i = 0; i < NB_NUMEROS; i++) {
        cartesPiochees[i] = 0;
    }

    printf("============================\n");
    printf("   Bienvenue dans FlipTek   \n");
    printf("============================\n");

    printf("Combien de joueurs ? ");
    nbJoueurs = lireEntierBorne(1, MAX_JOUEURS);

    // on initialise les joueurs
    initialiserJoueurs(joueurs, nbJoueurs);

    // on cree et on melange la pioche
    creerPioche(pioche);
    melangerPioche(pioche);

    // boucle principale : on joue des manches jusqu'a ce que la partie soit finie
    while (partieFinie(joueurs, nbJoueurs, indicePioche) == 0) {
        jouerManche(joueurs, nbJoueurs, pioche, &indicePioche, cartesPiochees);
    }

    // fin de partie
    afficherScoresFinaux(joueurs, nbJoueurs);

    return 0;
}
