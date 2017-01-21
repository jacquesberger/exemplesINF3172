makefiles
=========

Lors des travaux, il sera nécessaire de faire un makefile pour construire vos
logiciels. Cette matière ne sera pas couverte en classe, le moniteur va donc
vous expliquer les concepts relatifs à la création de makefiles :
* le programme make;
* les cibles;
* les dépendances (envers les autres cibles ou envers les fichiers).

Objectifs
---------

* Utiliser le programme `make`.
* Développer des makefiles.

Exercices
---------

1. Créer un makefile pour compiler un programme avec un seul fichier source.

2. Créer un makefile pour compiler un programme avec plusieurs fichiers sources
   et en changeant le nom de l'exécutable.

3. Créer un makefile pour compiler un programme avec plusieurs fichiers sources
   en effectuant la compilation en deux étapes :
   * la compilation (génération des .o);
   * l'édition des liens (production de l'exécutable).
