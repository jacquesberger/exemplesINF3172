Création de processus
=====================

Un shell doit créer et gérer la communication entre processus en dirigeant leurs
streams vers d'autres processus ou vers des fichiers. Cet atelier mettra
l'accent sur la création de processus et l'attente de processus enfants.

Au début de l'atelier, le moniteur présentera les programmes `ps` et `kill` de
`bash`. Ils servent notamment à dresser les listes des processus et de terminer
leur exécution.

Pour réaliser cet atelier, vous allez devoir utiliser les fonctions suivantes :
* `fork`
* `getpid`
* `getppid`
* `waitpid`
* `kill`
* `sleep`

Objectifs
=========

* Créer des processus
* Attendre des processus enfants

Exercices
=========

Après chaque exercice, utilisez les commandes `ps` et `kill` pour terminer les
processus qui sont encore actifs.

1. Créez un programme qui crée un processus enfant. Aucun traitement
   supplémentaire ne doit être fait dans le parent, ni l'enfant. Une fois le
   programme lancé, que voyez-vous avec `ps`?

2. Créez un programme qui crée un processus enfant. Les deux processus doivent
   écrire à la console leur numéro de processus et le numéro de leur processus
   parent.

3. Créez un programme qui crée un processus zombie. Le parent peut faire une
   boucle infinie et l'enfant doit se terminer normalement. Lancez le programme
   en arrière plan (avec `&`). Que voyez-vous avec `ps`?

4. Créez un programme qui crée un processus enfant et qui attend la fin de son
   exécution. L'enfant doit faire un calcul (ex. afficher la factorielle de 6)
   et le parent doit attendre la fin de l'exécution de son processus enfant
   avant de terminer sa propre exécution.

5. Créez un programme qui crée un processus enfant et le tue. L'enfant exécute une
   boucle infinie. La parent attend 5 secondes et tue son processus enfant avant de
   se terminer normalement.
