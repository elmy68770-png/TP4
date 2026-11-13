#ifndef HASH_H
#define HASH_H
#define TAILLE_HASH 101
struct Entree { char *cle; int valeur; struct Entree *suivant; };
typedef struct { struct Entree *table[TAILLE_HASH]; } TableHachage;
unsigned int hash_fonction(char *cle);
void hash_init(TableHachage *t);
void hash_inserer(TableHachage *t, char *cle);
int hash_rechercher(TableHachage *t, char *cle);
void hash_afficher(TableHachage *t);
void hash_liberer(TableHachage *t);
char* mon_strdup(char *s);
#endif
