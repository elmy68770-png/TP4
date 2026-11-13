#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hash.h"
int main(int argc, char *argv[]) {
    char *nom = "texte.txt";
    if (argc > 1) nom = argv[1];
    FILE *f = fopen(nom, "r");
    if (f == NULL) { printf("Impossible d ouvrir %s\n", nom); return 1; }
    TableHachage t; hash_init(&t);
    char mot[100]; int j = 0; int c;
    while ((c = fgetc(f)) != EOF) {
        if (isalpha(c)) { mot[j] = tolower(c); j++; if (j>=99) j=99; }
        else { if (j > 0) { mot[j] = '\0'; hash_inserer(&t, mot); j = 0; } }
    }
    if (j > 0) { mot[j] = '\0'; hash_inserer(&t, mot); }
    fclose(f);
    printf("=== Nombre d occurrences ===\n");
    hash_afficher(&t);
    hash_liberer(&t);
    return 0;
}
