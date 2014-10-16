//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas				    |
// FICHIER : modif_grille.h                   		    |
// DATE : 09/01/13					    |
//							    |
// - Prototypes des fonctions de modif_grille.h             |
// - Fonction d'insertion dans une colonne donnée           |
//   [ Insertion dans la ligne la plus basse possible ]     |
// - Fonction pour retirer un pion d'une colonne donnée     |
//   [ Insertion dans la ligne la plus basse possible ]     |
//----------------------------------------------------------

#ifndef MODIF_GRILLE_H
#define MODIF_GRILLE_H

#include "global.h"

//Initialise la grille a zero
void init_grille(char *grille);

//retire un pion de la grille
int retirer(char *grille,int num_col,char pion);
// retourne 1 si ok - 0 sinon

//insere un pion dans la colonne la plus basse possible
int inserer(char *grille,int num_col,char pion);
// retourne 1 si ok , 0 sinon

#endif // MODIF_GRILLE_H inclu
