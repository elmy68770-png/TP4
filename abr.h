#ifndef ABR_H
#define ABR_H
struct NoeudABR { int cle; struct NoeudABR *gauche; struct NoeudABR *droite; };
struct NoeudABR* abr_inserer(struct NoeudABR *r, int cle);
int abr_rechercher(struct NoeudABR *r, int cle);
void abr_infixe(struct NoeudABR *r);
int abr_hauteur(struct NoeudABR *r);
void abr_liberer(struct NoeudABR *r);
#endif
