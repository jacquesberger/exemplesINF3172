Threads
=======

Cet atelier est une introduction à la programmation multi-thread en langage C.
On crée les threads avec la fonction `pthread_create` et on les termine avec
`pthread_exit`. Dans un thread, assurez-vous de toujours utiliser des
fonctions _thread-safe_. La documentation des fonctions devrait vous l'indiquer.

Objectifs
---------

* Créer et supprimer des threads.
* Synchroniser des threads.

Exercices
---------

1. Écrivez un programme qui crée 5 threads en parallèle qui vont calculer et
   afficher à la console les éléments suivants :
   * la factorielle de 4;
   * la factorielle de 5;
   * le 5ème nombre de fibonacci;
   * le 7ème nombre de fibonacci;
   * le 9ème nombre de fibonacci.

2. Modifiez le programme du numéro 1 afin que les threads se synchronisent.
   C'est-à-dire que :
   * le main lance les 5 threads;
   * le thread 1 s'exécute immédiatement;
   * le thread 2 attend la fin de l'exécution du thread 1 avant de commencer son
     travail;
   * le thread 3 attend la fin de l'exécution du thread 2 avant de commencer son
     travail;
   * le thread 4 attend la fin de l'exécution du thread 3 avant de commencer son
     travail;
   * le thread 5 attend la fin de l'exécution du thread 4 avant de commencer son
     travail.
   Regardez la fonction `pthread_join` pour la synchronisation des threads.
