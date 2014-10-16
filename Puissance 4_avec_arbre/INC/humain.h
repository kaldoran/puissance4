//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas				    |
// FICHIER : humain.h                   		    |
// DATE : 09/01/13					    |
//							    |
// - Prototypes des fonctions de humain.c                   |
// - Fonction humain en rapport a Humain contre ordi        |
// - Fonction de jeu Humain contre Humain                   |
//----------------------------------------------------------

#ifndef HUMAIN_H
#define HUMAIN_H

#define TAILLE_MAX_PSEUDO 20
#define TAILLE_MIN_PSEUDO 3

#define DELAY 5000 // temps en milli seconde avant le debut de la partie

#include "global.h"

#include "gestion_fichier.h"
#include "modif_grille.h"
#include "affichage.h"
#include "verif.h"
#include "allocation.h"
#include "delay_sleep.h"
#include "IA.h"

//retourne 1 si la partie est gagné par l'humain 0 sinon
int humain_IA(char *grille);

//mode 0 ou 1
// mode = 0 pour joueru ne nouvelle partie , 1 pour charger une partie
void humain(int mode);

#endif // HUMAIN_H inclu
