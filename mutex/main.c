/*
 * Copyright 2015 Jacques Berger
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

const int EXIT_CODE = 1;
const int THREAD_COUNT = 8;

int executionsAvecSucces = 0;
int executionsAvecErreur = 0;

pthread_mutex_t mutexSucces;
pthread_mutex_t mutexErreur;

void start(void*);
void lancerThreads(pthread_t threads[THREAD_COUNT], int resultats[THREAD_COUNT]);
void attendreThreads(pthread_t threads[THREAD_COUNT], int resultats[THREAD_COUNT]);
void initialiserMutexes();
void detruireMutexes();
void incrementerNombreSucces();
void incrementerNombreErreur();

int main(int argc, char** argv)
{
  pthread_t threads[THREAD_COUNT];
  int resultats[THREAD_COUNT];

  initialiserMutexes();
  lancerThreads(threads, resultats);
  attendreThreads(threads, resultats);
  detruireMutexes();

  printf("Nombre d'exécutions avec erreur : %d\nNombre d'exécutions sans erreur : %d\n",
      executionsAvecErreur, executionsAvecSucces);

  return 0;
}

void incrementerNombreSucces()
{
  if (pthread_mutex_lock(&mutexSucces) != 0)
  {
    printf("Erreur avec le mutex succes.\n");
    return;
  }

  executionsAvecSucces++;

  if (pthread_mutex_unlock(&mutexSucces) != 0)
  {
    printf("Erreur avec le mutex succes.\n");
  }
}

void incrementerNombreErreur()
{
  if (pthread_mutex_lock(&mutexErreur) != 0)
  {
    printf("Erreur avec le mutex erreur.\n");
    return;
  }

  executionsAvecErreur++;

  if (pthread_mutex_unlock(&mutexErreur) != 0)
  {
    printf("Erreur avec le mutex erreur.\n");
  }
}

void initialiserMutexes()
{
  if (pthread_mutex_init(&mutexSucces, NULL) != 0)
  {
    printf("Erreur d'initialisation d'un mutex.\n");
    exit(1);
  }
  if (pthread_mutex_init(&mutexErreur, NULL) != 0)
  {
    printf("Erreur d'initialisation d'un mutex.\n");
    exit(1);
  }
}

void detruireMutexes()
{
  if (pthread_mutex_destroy(&mutexSucces) != 0)
  {
    printf("Erreur de destruction d'un mutex.\n");
    exit(1);
  }
  if (pthread_mutex_destroy(&mutexErreur) != 0)
  {
    printf("Erreur de destruction d'un mutex.\n");
    exit(1);
  }
}

void start(void* args)
{
  const int TAILLE_BUFFER = 60;
  FILE* entree;
  char buffer[TAILLE_BUFFER];

  entree = fopen("fichier", "r");
  if (entree == NULL)
  {
    incrementerNombreErreur();
  } else {
    while (fgets(buffer, TAILLE_BUFFER - 1, entree) != NULL)
    {
      printf("%s", buffer);
    }

    if (feof(entree))
    {
      incrementerNombreSucces();
    } else {
      incrementerNombreErreur();
    }
    fclose(entree);
  }

  pthread_exit((void*) &EXIT_CODE);
}

void lancerThreads(pthread_t threads[THREAD_COUNT], int resultats[THREAD_COUNT])
{
  int i;

  for (i = 0; i < THREAD_COUNT; i++)
  {
    resultats[i] = pthread_create(&(threads[i]), NULL, (void*) &start, NULL);
    if (resultats[i] != 0) {
      fprintf(stderr, "Erreur de création de thread, annulation de l'exécution du programme.\n");
    }
  }
}

void attendreThreads(pthread_t threads[THREAD_COUNT], int resultats[THREAD_COUNT])
{
  int i;
  int resultat;
  void* retourThread;

  for (i = 0; i < THREAD_COUNT; i++)
  {
    if (resultats[i] == 0)
    {
      resultat = pthread_join(threads[i], &retourThread);
      if (resultat != 0)
      {
        fprintf(stderr, "Erreur avec l'exécution d'un thread.\n");
        // Comme le programme se termine immédiatement après cette fonction,
        // inutile de tuer le thread.
      }
      else if (*((int*) retourThread) != EXIT_CODE)
      {
        fprintf(stderr, "Valeur de retour non attendue.\n");
      }
    }
  }
}
