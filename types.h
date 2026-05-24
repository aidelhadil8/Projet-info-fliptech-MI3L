#ifndef TYPES_H
#define TYPES_H

// les cartes numerotees vont de 0 a 12 donc 13 au total
#define NB_NUMEROS 13

// on a compté les cartes du jeu, il y en a 85 en tout
#define NB_CARTES 85

// longueur max du pseudo
#define TAILLE_PSEUDO 50

// on met 20 joueurs max ca devrait suffire
#define MAX_JOUEURS 20

// les 3 types de cartes possibles dans le jeu
typedef enum {
    CARTE_NUMERO,
    CARTE_BONUS_PLUS,
    CARTE_BONUS_X2
} TypeCarte;

// une carte a un type et une valeur
typedef struct {
    TypeCarte type;
    int valeur;
} Carte;

// toutes les infos d'un joueur
typedef struct {
    char pseudo[TAILLE_PSEUDO];

    int scoreTotal;   // score depuis le debut de la partie
    int scoreManche;  // score juste pour la manche en cours

    int cartesNumeros[NB_NUMEROS]; // tableau qui dit quelles cartes le joueur a deja
    int nbCartesDifferentes;       // combien de cartes numero differentes il a

    int bonusAddition;  // somme des bonus +
    int multiplicateur; // le x2 si il en a un

    int actif; // 1 = joue encore, 0 = arrete ou perdu
    int perdu; // 1 si il a eu un doublon
} Joueur;

#endif
