// -------------------------------------------------------- 
// AUTEUR : REYNAUD Nicolas				    |
// FICHIER : allocation.c                  		    |
// DATE : 09/01/13					    |
//							    |
// - Définition des fonctions de allocation.h               |
// - Pour plus d'info C.F allocation.h                      |
// -------------------------------------------------------- 

#include <stdio.h>
#include <stdlib.h>

#include "../INC/allocation.h"

// module allocation.c

void * allocation(int nombre , size_t taille)
{
  void *pointeur = NULL;
  pointeur = calloc(nombre,taille);
  if (pointeur == NULL)
    {
      fprintf(stderr,"Probleme d'allocation mémoire");
      exit(EXIT_FAILURE);
    }
  return pointeur; 
}

