Manipulation du système de fichiers
===================================

Les programmes ont presque toujours besoin de manipuler le système de fichiers
pour créer, accéder ou supprimer des fichiers et/ou des répertoires. Dans cet
atelier, vous manipulerez l'ensembre de ces éléments.

Objectifs
---------

* Manipuler les méta-données d'un fichier.
* Manipuler les fichiers.
* Manipuler les répertoires.

Exercices
---------

1. Écrivez un programme qui ouvre un fichier texte en lecture seule et affiche
   son contenu à l'écran (voir `fopen`, `fscanf` ou `fgets`, `fclose`).

2. Écrivez un programme qui affiche à l'écran la liste de tous les fichiers avec
   l'extension `.txt` dans un répertoire (voir `opendir`, `readdir`,
   `closedir`).

3. Écrivez un programme qui recherche la chaîne `INF3172` dans tous les fichiers
   avec l'extension `.txt` d'un répertoire. Si la chaîne est contenu dans un
   fichier, affichez le chemin absolu du fichier et sa taille à l'écran (voir
   `fstat`).

4. Modifiez le programme de l'exercice #3 pour effectuer la recherche dans les
   sous-répertoires également.
