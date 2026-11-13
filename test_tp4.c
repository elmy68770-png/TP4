#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "abr.h"
#include "hash.h"
int main() {
    printf("=== TEST ABR ===\n");
    struct NoeudABR *racine = NULL;
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    int i; for (i=0;i<7;i++) racine = abr_inserer(racine, vals[i]);
    printf("Parcours infixe : "); abr_infixe(racine); printf("\n");
    printf("Hauteur : %d (attendu 3)\n", abr_hauteur(racine));
    printf("Recherche 40 : %d (attendu 1)\n", abr_rechercher(racine, 40));
    printf("Recherche 99 : %d (attendu 0)\n", abr_rechercher(racine, 99));
    abr_liberer(racine);
    printf("\n=== TEST HASH ===\n");
    TableHachage t; hash_init(&t);
    hash_inserer(&t, "bonjour"); hash_inserer(&t, "bonjour"); hash_inserer(&t, "monde");
    printf("bonjour : %d (attendu 2)\n", hash_rechercher(&t, "bonjour"));
    printf("monde : %d (attendu 1)\n", hash_rechercher(&t, "monde"));
    hash_liberer(&t);
    printf("\n=== COMPARAISON 10000 CLES ===\n");
    struct NoeudABR *abr = NULL;
    TableHachage th; hash_init(&th);
    char cle[20]; clock_t debut, fin;
    debut = clock(); for (i=0;i<10000;i++) abr = abr_inserer(abr, i); fin = clock();
    printf("Insertion ABR 10000 : %f s\n", (double)(fin-debut)/CLOCKS_PER_SEC);
    debut = clock(); for (i=0;i<10000;i++) { sprintf(cle, "mot%d", i); hash_inserer(&th, cle); } fin = clock();
    printf("Insertion HASH 10000 : %f s\n", (double)(fin-debut)/CLOCKS_PER_SEC);
    debut = clock(); for (i=0;i<10000;i++) abr_rechercher(abr, i); fin = clock();
    printf("Recherche ABR 10000 : %f s\n", (double)(fin-debut)/CLOCKS_PER_SEC);
    debut = clock(); for (i=0;i<10000;i++) { sprintf(cle, "mot%d", i); hash_rechercher(&th, cle); } fin = clock();
    printf("Recherche HASH 10000 : %f s\n", (double)(fin-debut)/CLOCKS_PER_SEC);
    printf("Conclusion : hachage O(1) en moyenne, ABR O(log n) si equilibre.\n");
    abr_liberer(abr); hash_liberer(&th);
    return 0;
}
