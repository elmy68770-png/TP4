#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
unsigned int hash_fonction(char *cle) {
    unsigned int h = 5381; int i = 0;
    while (cle[i] != '\0') { h = h * 33 + (unsigned char)cle[i]; i++; }
    return h % TAILLE_HASH;
}
char* mon_strdup(char *s) { char *c = malloc(strlen(s)+1); strcpy(c, s); return c; }
void hash_init(TableHachage *t) { int i; for (i=0;i<TAILLE_HASH;i++) t->table[i]=NULL; }
void hash_inserer(TableHachage *t, char *cle) {
    unsigned int idx = hash_fonction(cle);
    struct Entree *e = t->table[idx];
    while (e != NULL) { if (strcmp(e->cle, cle)==0) { e->valeur++; return; } e = e->suivant; }
    struct Entree *n = malloc(sizeof(struct Entree));
    n->cle = mon_strdup(cle); n->valeur = 1; n->suivant = t->table[idx]; t->table[idx] = n;
}
int hash_rechercher(TableHachage *t, char *cle) {
    unsigned int idx = hash_fonction(cle);
    struct Entree *e = t->table[idx];
    while (e != NULL) { if (strcmp(e->cle, cle)==0) return e->valeur; e = e->suivant; }
    return 0;
}
void hash_afficher(TableHachage *t) {
    int i; for (i=0;i<TAILLE_HASH;i++) { struct Entree *e = t->table[i]; while (e != NULL) { printf("%s : %d\n", e->cle, e->valeur); e = e->suivant; } }
}
void hash_liberer(TableHachage *t) {
    int i; for (i=0;i<TAILLE_HASH;i++) { struct Entree *e = t->table[i]; while (e != NULL) { struct Entree *tmp = e; e = e->suivant; free(tmp->cle); free(tmp); } t->table[i]=NULL; }
}
