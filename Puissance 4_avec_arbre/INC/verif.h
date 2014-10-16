//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas				    |
// FICHIER : verif.h                    		    |
// DATE : 09/01/13					    |
//							    |
// - Prototypes des fonctions de verif.c                    |
// - Fonction de verification de la grille , verifie si     |
//   les NB_PION_A_ALIGNER [ C.F global.h ] sont alignés    |
// - Fonction verifiant si la grille est pleine             |
// - Fonction verifiant si la colonne passée en parametre   |
//   est pleine                                             |
// - Fonction de sécurité sur le scanf et de verification   |
//----------------------------------------------------------


#ifndef VERIF_H
#define VERIF_H

#include "global.h"

// Verifie l'alignement de NB_PION_ALIGNER pour un pion donner 
// Ex : 4 pion alignées pour les X dans la grille
// retourne 1 si ils sont aligné - 0 sinon
char verif_grille(char * grille , char pion_a_verif);

//Retourne 1 si la grille est pleine 0 sinon
int grille_pleine(char* grille);

//retourne 1 si la colonne est pleine 0 sinon
int colonne_pleine(char * grille,int num_col);

//Verifie le choix donner en parametre 
//Inférieur a val_mal , supérieur a 0 ou egale a -1 puis le retourne
int verif_choix(char *phrase,int val_max);

#endif //VERIF_H inclu
