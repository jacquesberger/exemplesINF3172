Shell
=====

Cet atelier vise à mettre en place la mécanique de base d'un shell, c'est-à-dire
de créer un processus enfant et d'attendre la fin de son exécution.

Objectif
--------

* Comprendre comment un shell exécute les programmes

Exercices
---------

1. Trouvez l'emplacement du programme `ls` sur le serveur malt (indice :
   regardez dans `/bin`).

2. Créez un programme qui lance le programme `ls`. Votre programme doit créer un
   processus enfant et attendre la fin de l'exécution du processus enfant. Le
   processus enfant doit se transformer en programme `ls` à l'aide de la
   fonction `execve` ou un autre dérivé de `exec`.

3. Modifiez votre programme afin de saisir des commandes de l'utilisateur à
   console. Votre programme est une boucle infinie qui, à chaque tour de boucle,
   va saisir une commande, et si la commande est valide, il va créer un
   processus enfant qui exécutera la commande, comme le `ls` dans l'exercice
   précédent. Votre programme devrait pouvoir exécuter n'importe quelle commande
   présente dans le répertoire `/bin`.
