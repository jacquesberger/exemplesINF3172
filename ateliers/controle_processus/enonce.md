Contrôle de processus
=====================

Mettre fin à l'exécution d'un processus est une opération fréquente. De plus, un
programme peut utiliser le shell qui l'a invoqué et manipuler son environnement.

Objectifs
=========

* Explorer certaines fonctionnalités pour terminer l'exécution d'un processus.
* Explorer certaines fonctionnalités pour manipuler l'environnement d'un
  processus.

Exercices
=========

1. Regardez la documentation de la fonction `abort` (`man abort`). Écrivez un
   programme qui prend en paramètre (à la console) un nom de fichier et qui
   termine son exécution avec `abort` si le fichier n'existe pas.

2. Regardez la documentation de la fonction `exit` (`man stdlib.h`). Écrivez un
   programme qui prend en paramètre (à la console) un nom de fichier et qui
   termine son exécution avec `exit` si le fichier n'existe pas.

3. Regardez la documentation de la fonction `atexit` (`man atexit`). Modifiez le
   programme au no.2 pour assigner une fonction (avec `atexit`) qui affichera un message
   d'erreur à la console en cas d'arrêt du processus avec la fonction `exit`.

4. Regardez la documentation des fonctions `getenv` et `setenv`. Écrivez un
   programme qui affiche à la console la variable d'environnement `PATH`.
   Ensuite, modifier la variable d'environnement `PATH` pour y ajouter le
   répertoire courant.

5. Regardez la documentation de la fonction `system` (`man system`). Écrivez un
   programme qui crée un nouveau répertoire contenant un fichier vide à l'aide
   de la fonction `system`. Vous pouvez faire plus d'un appel à la fonction.
