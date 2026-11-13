#include <stdio.h>
#include <stdlib.h>
#include "abr.h"
struct NoeudABR* abr_inserer(struct NoeudABR *r, int cle) {
    if (r == NULL) {
        struct NoeudABR *n = malloc(sizeof(struct NoeudABR));
        n->cle = cle; n->gauche = NULL; n->droite = NULL; return n;
    }
    if (cle < r->cle) r->gauche = abr_inserer(r->gauche, cle);
    else if (cle > r->cle) r->droite = abr_inserer(r->droite, cle);
    return r;
}
int abr_rechercher(struct NoeudABR *r, int cle) {
    if (r == NULL) return 0;
    if (cle == r->cle) return 1;
    if (cle < r->cle) return abr_rechercher(r->gauche, cle);
    return abr_rechercher(r->droite, cle);
}
void abr_infixe(struct NoeudABR *r) {
    if (r == NULL) return;
    abr_infixe(r->gauche);
    printf("%d ", r->cle);
    abr_infixe(r->droite);
}
int abr_hauteur(struct NoeudABR *r) {
    if (r == NULL) return 0;
    int g = abr_hauteur(r->gauche);
    int d = abr_hauteur(r->droite);
    if (g > d) return g + 1;
    return d + 1;
}
void abr_liberer(struct NoeudABR *r) {
    if (r == NULL) return;
    abr_liberer(r->gauche);
    abr_liberer(r->droite);
    free(r);
}
