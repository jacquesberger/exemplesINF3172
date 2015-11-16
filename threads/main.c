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

int factorielle(int);
void start(void*);
void initialiserParams(int params[THREAD_COUNT]);
void lancerThreads(pthread_t threads[THREAD_COUNT], int params[THREAD_COUNT]);
void attendreThreads(pthread_t threads[THREAD_COUNT]);

int main(int argc, char** argv)
{
  pthread_t threads[THREAD_COUNT];
  int params[THREAD_COUNT];

  initialiserParams(params);
  lancerThreads(threads, params);
  attendreThreads(threads);

  return 0;
}

int factorielle(int facto)
{
  if (facto <= 1)
  {
    return 1;
  } else {
    return facto * factorielle(facto - 1);
  }
}

void start(void* args)
{
  int valeur;
  valeur = *((int*) args);
  printf("La factorielle de %d est : %d\n", valeur, factorielle(valeur));
  pthread_exit((void*) &EXIT_CODE);
}

void initialiserParams(int params[THREAD_COUNT])
{
  int i;
  for (i = 0; i < THREAD_COUNT; i++)
  {
    params[i] = i + 1;
  }
}

void lancerThreads(pthread_t threads[THREAD_COUNT], int params[THREAD_COUNT])
{
  int i;
  int resultat;

  for (i = 0; i < THREAD_COUNT; i++)
  {
    resultat = pthread_create(&(threads[i]), NULL, (void*) &start, (void*) &(params[i]));
    if (resultat != 0) {
      fprintf(stderr, "Erreur de création de thread, annulation de l'exécution du programme.\n");
      exit(1);
    }
  }
}

void attendreThreads(pthread_t threads[THREAD_COUNT])
{
  int i;
  int resultat;

  for (i = 0; i < THREAD_COUNT; i++)
  {
    resultat = pthread_join(threads[i], NULL);
    if (resultat != 0)
    {
      fprintf(stderr, "Erreur avec l'exécution d'un thread.\n");
      // Comme le programme se termine immédiatement après cette fonction,
      // inutile de tuer le thread.
    }
  }
}
