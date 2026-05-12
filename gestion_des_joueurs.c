#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_NUMEROS 13
#define NB_CARTES 85
#define TAILLE_PSEUDO 50
#define MAX_JOUEURS 20

typedef enum {
    CARTE_NUMERO,
    CARTE_BONUS_PLUS,
    CARTE_BONUS_X2
} TypeCarte;

typedef struct {
    TypeCarte type;
    int valeur;
} Carte;

typedef struct {
    char nom[TAILLE_NOM];

    int scoreTotal;
    int scoreManche;

    int cartesNumeros[NB_NUMEROS];
    int nbCartesDifferentes;

    int bonusAddition;
    int multiplicateur;

    int actif;
    int perdu;
} Joueur;



void initialiserJoueurs(Joueur joueurs[], int nbJoueurs) {
    int i;

    for (i = 0; i < nbJoueurs; i++) {
        printf("nom du joueur %d : ", i + 1);
        scanf("%49s", joueurs[i].nom);
        viderBuffer();

        joueurs[i].scoreTotal = 0;
        joueurs[i].scoreManche = 0;
    }
}

void afficherScores(Joueur joueurs[], int nbJoueurs) {
    int i;

    printf("\nScores actuels :\n");

    for (i = 0; i < nbJoueurs; i++) {
        printf("%s : %d points\n", joueurs[i].pseudo, joueurs[i].scoreTotal);
    }
}
void initialiserManche(Joueur joueurs[], int nbJoueurs) {
    int i;
    int j;

    for (i = 0; i < nbJoueurs; i++) {
        joueurs[i].scoreManche = 0;
        joueurs[i].nbCartesDifferentes = 0;
        joueurs[i].bonusAddition = 0;
        joueurs[i].multiplicateur = 1;
        joueurs[i].actif = 1;
        joueurs[i].perdu = 0;

        for (j = 0; j < NB_NUMEROS; j++) {
            joueurs[i].cartesNumeros[j] = 0;
        }
    }
}
