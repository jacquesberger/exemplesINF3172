Fichiers binaires
=================

Dans vos cours de programmation, vous avez souvent utilisé des fichiers textes
mais peut-être jamais de fichiers binaires. Dans cet atelier, vous allez créer
et lire des fichiers binaires.

Vous voudrez probablement consulter la documentation des fonctions suivantes :
* `fopen` pour les modes d'ouverture `rb` et `wb`;
* `fclose`;
* `fread`;
* `fwrite`;
* `fseek`;
* `feof`.

Pour chaque appel à une fonction qui manipule un fichier, la fonction pourrait
retourner un code d'erreur. Le cas échéant, il est possible aussi que la
fonction place une valeur dans `errno`. Vous devez gérer les erreurs possibles
dans vos programmes (ex. fermer les fichiers ouverts et terminer l'exécution du
programme avec un message d'erreur). Importez `errno.h` pour l'utilisation de la
variable `errno`.

Lorsqu'on manipule des fichiers binaires, on place les données dans une
structure (`struct`) et c'est cette structure qu'on va lire ou écrire dans le
fichier binaire. Pour les chaînes de caractères, on place toujours des tailles
statiques, pas de chaînes allouées dynamiquement.

Objectifs
---------

* Manipuler des fichiers binaires.
* Rafraîchir un peu le langage C.

Exercices
---------

1. Écrivez un programme qui permet à l'utilisateur de saisir au clavier les
   données d'un animal de compagnie :
   * un nom;
   * un sexe;
   * un âge;
   * un poids.

   Pour chaque animal saisie, on écrit les données dans un fichier binaire.
   D'une exécution à l'autre du programme, les données du fichier binaire
   doivent être persistentes, c'est-à-dire que le programme ajoute toujours à la
   fin du fichier, sans jamais écraser le fichier ou effacer des données.

2. Écrivez un programme qui affiche à l'écran la liste des animaux contenus dans
   le fichier de l'exercice #1.
