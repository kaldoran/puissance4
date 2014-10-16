//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas				    |
// FICHIER : IA.h                          		    |
// DATE : 09/01/13					    |
//							    |
// - Prototypes des fonctions de IA.c                       |
// - Fonction de jeu Ordinateur contre humain               |
// - Fonction de jeu Ordinateur contre Ordinateur           |
//   [ Mode de démo ]                                       |
// - Fonction qui retourne la colonne qui doit etre jouée   |
// - Fonction qui retourne le MAX [principe minmax, avec    |
//   Elagage Alpha beta ]                                   |
// - Fonction qui retourne le MIN [principe minmax, avec    |
//   Elagage Alpha beta ]                                   |
// - Fonction d'évaluation de la grille                     |
// - Fonction retournant un nombre au hasard entre 0 et max |
//----------------------------------------------------------


#ifndef IA_H
#define IA_H

#include "global.h"
#include "delay_sleep.h"
#include "verif.h"
#include "modif_grille.h"
#include "eval.h"
#include "humain.h"
#include "allocation.h"

#define COEF_NB_SERIE_4 10000

//definie le jeu -le tour - le gagnant de l'humain contre l'humain
void IA_vs_H(int niveau);

//definie le jeu - le tour - le gagnant du mode Ordinateur contre ordinateur
void IA_vs_IA(int niveau_IA_1,int niveau_IA_2);

//Retourne la colonne ou doit jouer l'IA
//Si profondeur < 1 'ia joue au hasard
int IA_jouer(char* grid,int profondeur,char pion);

//Retourne la valeur max des evaluations
int Max(char* grid,int profondeur_max,int profondeur,int alpha,int beta,char pion);

//retourne la valuer min des evaluations
int Min(char* grid,int profondeur_max,int profondeur,int alpha,int beta,char pion);

//retourne le score assosier a une grille en fonction du pion donner en parametre
int eval(char *grille,char pion);

//Retourne un nombre aléatoire entre 0 et max
int hasard(int max);

#endif // IA_H inclu
