TP4 - ABR et table de hachage


1. ABR : insertion, recherche, parcours infixe, hauteur, destruction -> dans abr.c / abr.h
2. Table de hachage par chainage, cles = chaines, fonction djb2 -> dans hash.c / hash.h
3. Compteur de mots -> motcompte.c, teste avec texte.txt
4. Bench 10000 cles -> dans main_abr.c

COMPILATION :
gcc -std=c17 -Wall -Wextra -g abr.c hash.c main_abr.c -o test_abr.exe
gcc -std=c17 -Wall -Wextra -g hash.c motcompte.c -o motcompte.exe

EXECUTION :
.\test_abr.exe
.\motcompte.exe texte.txt

RESULTATS (voir resultats_ABR.txt et resultats_motcompte.txt) :
- Infixe TP4 attendu : 20 30 40 50 60 70 80 (trie)
- Hauteur attendue : 2
- Recherche 40 : trouve, Recherche 99 : absent

COMMENTAIRE Q4 - Comparaison 10000 cles :
La table de hachage est plus rapide que l'ABR car elle calcule directement la case avec la fonction de hachage, en O(1) en moyenne, alors que l'ABR doit descendre de la racine aux feuilles en O(log n). Si les cles sont inserees triees, l'ABR degenere en liste chainee et devient O(n), alors que la table reste O(1) tant qu'il y a peu de collisions.

MEMOIRE :
Tous les malloc ont leur free dans abr_detruire et hash_detruire. Aucune fuite.
