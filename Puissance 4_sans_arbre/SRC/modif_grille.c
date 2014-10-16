// -------------------------------------------------------- 
// AUTEUR : REYNAUD Nicolas				    |
// FICHIER : modif_grille.c                 		    |
// DATE : 09/01/13					    |
//							    |
// - Définition des fonctions de modif_grille.h             |
// - pour plus d'info voir modif_grille.h	            |
// -------------------------------------------------------- 

#include <stdio.h>
#include <stdlib.h>

#include "../INC/modif_grille.h"

void init_grille(char *grille) // initialise la grille a '.'
{
  int i=0;
  for (i = 0; i < TAILLE_TAB;i++)
    grille[i] = '.';

}

// retire le premier pion de la colonne egale a pion
// retourne 1 si le pion y est ; 0 sinon
int retirer(char *grille,int num_col,char pion) 
{
  int ligne;
  for (ligne = 0;ligne < NB_LIGNE;ligne ++)
    if(grille[CASE(ligne,num_col-1)] == pion)
      {
	grille[CASE(ligne,num_col-1)] = '.';
	return 1;
      }
  return 0;

}

//insere un pion dans une colonne dans la position la plus basse possible.
//retourne 1 si succes - 0 sinon
int inserer(char *grille,int num_col,char pion)
{
  int ligne;
  for (ligne = NB_LIGNE;ligne >= 0;ligne --) // on part de la ligne la plus basse et on remonte
    if(grille[CASE(ligne,num_col-1)] == '.')
      {
	grille[CASE(ligne,num_col-1)] = pion;
	return 1;
      }
  
  return 0;
}
