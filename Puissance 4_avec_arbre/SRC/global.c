// -------------------------------------------------------- 
// AUTEUR : REYNAUD Nicolas				    |
// FICHIER : global.c                          		    |
// DATE : 09/01/13					    |
//							    |
// - Définition des fonctions de global.g	            |
// -------------------------------------------------------- 


#include <stdio.h>
#include <stdlib.h>

#include "../INC/global.h"

//Fait un CTRL + L pour néttoyer l'ecran
void _clean()
{
  system("clear");
}

// Reinitialise l'écran
void _reset_term()
{
  system("reset");
}

//vide le buffer
void videbuffer()
{
  char videbuffer = 'a';
  while( (videbuffer=getchar()) != '\0' && videbuffer != '\n'); // on vide le buffer

}

// Fait une pause et attend Entrée pour continuer
void do_pause()
{
  int c; // on prend un int pour economiser de la place
  
  printf("Appuyer sur entrée pour continuer...");

  while(getchar() != '\n'); // On commence par vider le bufffer

  while ((c = getchar()) != '\n' && c != '\0') 
    ;//instruction vide

  _reset_term();
}

