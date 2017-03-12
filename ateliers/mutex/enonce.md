Mutex
=====

Lorsque les threads doivent manipuler des ressources communes, il faut les
protéger avec des mutex. Dans ce cas, il faut utiliser la structure
`pthread_mutex_t` et les fonctions `pthread_mutex_init`, `pthread_mutex_lock`,
`pthread_mutex_unlock` et `pthread_mutex_destroy`.

Objectifs
---------

* Identifier les sections critiques.
* Protéger les sections critiques avec des mutex.

Exercices
---------

1) Construisez un logiciel qui va lire un fichier d'entrée contenant des sigles
de cours avec des titres de cours :

```
INF4170 - Architecture des ordinateurs
INF2005 - Programmation web
INF1120 - Programmation 1
INF2120 - Programmation 2
INF1256 - Informatique pour les sciences de la gestion
```

Le fichier d'entrée ne doit contenir que 5 cours. Évitez les caractères
accentués. Le programme doit créer 5 threads. Chacun des threads doit lire une ligne dans
le fichier d'entrée et produire une lire équivalente dans un fichier de sortie
mais ne contenant que le titre du cours, sans le sigle :

```
Programmation web
Architecture des ordinateurs
Programmation 1
Informatique pour les sciences de la gestion
Programmation 2
```

L'ordre des cours peut changer.

2) Identifiez les sections critiques du programme.

3) Protégez les sections critiques avec des mutex.
