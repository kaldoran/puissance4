//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas				    |
// FICHIER : affiche.h                   		    |
// DATE : 09/01/13					    |
//							    |
// - Prototypes des fonctions de global.c                   |
// - Défini tout les parametres du jeu                      |
// - Fonction de reset du terminal                          |
// - Fonction pour nettoyer le terminal                     |
// - Fonction pour vider le buffer                          |
// - Fonction pour faire une pause pendant le jeu           |
//   (Attendre la touche entrer pour continuer)             |
//----------------------------------------------------------


#ifndef GLOBAL_H
#define GLOBAL_H

#define NB_COLONNE 7
#define NB_LIGNE 6
#define NB_PION_A_ALIGNER 4
#define TAILLE_TAB (NB_LIGNE * NB_COLONNE)
#define CASE(LIGNE,COLONNE) (LIGNE*NB_COLONNE+COLONNE) // permet de trouver une case du tableau en entrant la colonne et la ligne que l'on cherche a avoir
#define PION_J1 'X'
#define PION_J2 'O'

void _clean();

void _reset_term();

void videbuffer();

void do_pause();


#endif // GLOBAL_H inclu
