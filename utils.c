#include <stdio.h>
#include "utils.h"

// on vide le buffer pour eviter les problemes avec scanf
// sans ca le programme lit des trucs qu'on a pas tapé
void viderBuffer() {
    int c;
    c = getchar();
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

// cette fonction lit un nombre et recommence si c'est pas bon
int lireEntierBorne(int min, int max) {
    int valeur;
    int verif;

    valeur = 0;
    verif = 0;

    do {
        verif = scanf("%d", &valeur);
        viderBuffer();

        // si c'est pas un nombre ou pas dans les bornes on redemande
        if (verif != 1 || valeur < min || valeur > max) {
            printf("Valeur incorrecte, entrez un nombre entre %d et %d : ", min, max);
        }

    } while (verif != 1 || valeur < min || valeur > max);

    return valeur;
}
