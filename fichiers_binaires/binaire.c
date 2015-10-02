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
#include <stdio.h>
#include <stdlib.h>
#include "binaire.h"

int main(int argc, char** argv)
{
  ListePersonnes_t liste;
  genererPersonnes(liste);
  ecrirePersonnes(liste);
  affichagePersonnes();
  return 0;
}

void genererPersonnes(ListePersonnes_t personnes)
{
  int i;
  for (i = 0; i < NB_PERSONNES; i++)
  {
    personnes[i].age = 22 + i;
    personnes[i].sexe = (i % 2) + 1;
    personnes[i].nbEnfants = i % 3;
  }
}

void ecrirePersonnes(ListePersonnes_t personnes)
{
  FILE* fichier;
  int nombreObjets;

  fichier = fopen("personnes.dat", "wb");
  if (fichier == NULL)
  {
    perror("Erreur avec le fichier ");
    exit(1);
  }

  nombreObjets = fwrite(personnes, sizeof(Personne_t), NB_PERSONNES, fichier);
  if (nombreObjets < NB_PERSONNES)
  {
    perror("Erreur lors de l'écriture du fichier ");
  }

  fclose(fichier);
}

void affichagePersonnes()
{
  FILE* fichier;
  Personne_t personne;
  int ok = 1;

  fichier = fopen("personnes.dat", "rb");
  if (fichier == NULL)
  {
    perror("Erreur avec le fichier ");
    exit(1);
  }

  do
  {
    fread(&personne, sizeof(Personne_t), 1, fichier);
    if (ferror(fichier))
    {
      perror("Erreur de lecture du fichier ");
      ok = 0;
    } else if (feof(fichier)) {
      ok = 0;
    } else {
      printf("============== Personne ===============\n");
      printf("age : %d\nsexe : %d\nenfants : %d\n\n", personne.age, personne.sexe, personne.nbEnfants);
    }
  } while (!feof(fichier));

  fclose(fichier);
}
