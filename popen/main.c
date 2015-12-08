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
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_BUFFER 50

int main(int argc, char** argv)
{
  FILE* stream;
  FILE* output;
  char buffer[TAILLE_BUFFER];

  stream = popen("ls -al", "r");
  if (stream == NULL)
  {
    fprintf(stderr, "Erreur lors du popen.\n");
    return EXIT_FAILURE;
  }

  output = fopen("resultat.txt", "w");
  if (output == NULL)
  {
    fprintf(stderr, "Erreur lors de l'ouverture du fichier de sortie : %s\n", strerror(errno));
    pclose(stream);
    return EXIT_FAILURE;
  }

  fprintf(stdout, "Affichage sur stdout qui va sur la console.\n");
  fprintf(stderr, "Affichage sur stderr qui va sur la console.\n");

  while (!feof(stream))
  {
    if (fgets(buffer, TAILLE_BUFFER - 1, stream) != NULL)
    {
      fprintf(output, "%s", buffer);
    }
  }

  pclose(stream);
  fclose(output);

  return 0;
}
