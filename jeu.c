#include <stdio.h>
#include "jeu.h"
#include "joueur.h"
#include "affichage.h"
#include "utils.h"

// calcule les scores de fin de manche pour tous les joueurs
void calculerScoresFinManche(Joueur joueurs[], int nbJoueurs) {
    int i;

    printf("\n============================\n");
    printf("Fin de la manche\n");
    printf("============================\n");

    for (i = 0; i < nbJoueurs; i++) {

        // si le joueur n'a pas eu de doublon on lui applique ses bonus
        if (joueurs[i].perdu == 0) {
            joueurs[i].scoreManche = joueurs[i].scoreManche + joueurs[i].bonusAddition;
            joueurs[i].scoreManche = joueurs[i].scoreManche * joueurs[i].multiplicateur;
        } else {
            // doublon = score de manche = 0
            joueurs[i].scoreManche = 0;
        }

        // on ajoute le score de la manche au total
        joueurs[i].scoreTotal = joueurs[i].scoreTotal + joueurs[i].scoreManche;

        printf("%s : +%d points cette manche (total : %d)\n",
               joueurs[i].pseudo,
               joueurs[i].scoreManche,
               joueurs[i].scoreTotal);
    }
}

// gere tout le deroulement d'une manche
void jouerManche(Joueur joueurs[], int nbJoueurs, Carte pioche[], int *indicePioche, int cartesPiochees[]) {
    int mancheFinie;
    int joueurActuel;
    int choix;
    int nbInactifs;
    int i;
    Carte carte;

    mancheFinie = 0;

    initialiserManche(joueurs, nbJoueurs);

    printf("\n============================\n");
    printf("Debut d'une nouvelle manche\n");
    printf("============================\n");

    while (mancheFinie == 0) {

        for (joueurActuel = 0; joueurActuel < nbJoueurs; joueurActuel++) {

            // on passe le tour si le joueur est sorti ou a perdu
            if (joueurs[joueurActuel].actif == 1 && mancheFinie == 0) {

                afficherJoueur(joueurs[joueurActuel]);
                afficherCartesPiochees(cartesPiochees);

                printf("\n%s, que voulez-vous faire ?\n", joueurs[joueurActuel].pseudo);
                printf("1 - Piocher une carte\n");
                printf("0 - S'arreter\n");
                printf("Votre choix : ");

                choix = lireEntierBorne(0, 1);

                if (choix == 0) {
                    // le joueur choisit de s'arreter, il garde son score
                    joueurs[joueurActuel].actif = 0;
                    printf("%s s'arrete et garde ses points.\n", joueurs[joueurActuel].pseudo);

                } else {

                    // on verifie qu'il reste des cartes
                    if (*indicePioche >= NB_CARTES) {
                        printf("Plus de cartes dans la pioche !\n");
                        mancheFinie = 1;
                    } else {

                        // on prend la prochaine carte de la pioche
                        carte = pioche[*indicePioche];
                        *indicePioche = *indicePioche + 1;

                        printf("%s pioche : ", joueurs[joueurActuel].pseudo);
                        afficherCarte(carte);
                        printf("\n");

                        if (carte.type == CARTE_NUMERO) {

                            cartesPiochees[carte.valeur]++;

                            // si le joueur a deja cette carte numero c'est un doublon
                            if (joueurs[joueurActuel].cartesNumeros[carte.valeur] == 1) {
                                printf("Doublon ! %s perd tous ses points de la manche.\n", joueurs[joueurActuel].pseudo);
                                joueurs[joueurActuel].perdu = 1;
                                joueurs[joueurActuel].actif = 0;
                                joueurs[joueurActuel].scoreManche = 0;

                            } else {
                                // carte nouvelle, on l'ajoute au joueur
                                joueurs[joueurActuel].cartesNumeros[carte.valeur] = 1;
                                joueurs[joueurActuel].scoreManche = joueurs[joueurActuel].scoreManche + carte.valeur;
                                joueurs[joueurActuel].nbCartesDifferentes++;

                                // si le joueur a 7 cartes differentes c'est le Flip 7 !
                                if (joueurs[joueurActuel].nbCartesDifferentes == 7) {
                                    printf("FLIP 7 !!! %s a 7 cartes differentes et gagne 15 points bonus !\n", joueurs[joueurActuel].pseudo);
                                    joueurs[joueurActuel].scoreManche = joueurs[joueurActuel].scoreManche + 15;
                                    mancheFinie = 1;
                                }
                            }

                        } else if (carte.type == CARTE_BONUS_PLUS) {
                            // carte bonus +, on l'ajoute aux bonus du joueur
                            joueurs[joueurActuel].bonusAddition = joueurs[joueurActuel].bonusAddition + carte.valeur;
                            printf("Bonus +%d ajoute a %s.\n", carte.valeur, joueurs[joueurActuel].pseudo);

                        } else {
                            // carte x2
                            joueurs[joueurActuel].multiplicateur = joueurs[joueurActuel].multiplicateur * 2;
                            printf("Multiplicateur x2 ajoute a %s !\n", joueurs[joueurActuel].pseudo);
                        }

                        // si la pioche est vide apres la pioche on arrete la manche
                        if (*indicePioche >= NB_CARTES) {
                            printf("La pioche est vide, fin de la manche.\n");
                            mancheFinie = 1;
                        }
                    }
                }
            }
        }

        // on compte combien de joueurs sont encore actifs
        nbInactifs = 0;
        for (i = 0; i < nbJoueurs; i++) {
            if (joueurs[i].actif == 0) {
                nbInactifs++;
            }
        }

        // si tout le monde est sorti ou a perdu on arrete
        if (nbInactifs == nbJoueurs) {
            mancheFinie = 1;
        }
    }

    calculerScoresFinManche(joueurs, nbJoueurs);
}

// verifie si la partie est finie
int partieFinie(Joueur joueurs[], int nbJoueurs, int indicePioche) {
    int i;

    // fini si plus de cartes
    if (indicePioche >= NB_CARTES) {
        return 1;
    }

    // fini si quelqu'un atteint 200 points
    for (i = 0; i < nbJoueurs; i++) {
        if (joueurs[i].scoreTotal >= 200) {
            return 1;
        }
    }

    return 0;
}
