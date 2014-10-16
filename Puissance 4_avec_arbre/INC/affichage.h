//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas				    |
// FICHIER : affiche.h                   		    |
// DATE : 09/01/13					    |
//							    |
// - Prototypes des fonctions de affiche.c                  |
// - Fonction d'affichage du titre d'accueil                |
// - Fonction d'affichage du menu                           |
// - Fonction d'affichage du sous menu humain               |
// - Fonction d'affichage du sous menu pour la difficulté   |
//   De l'IA                                                |
// - Fonction d'affichage des statistiques                  |
// - Fonction d'affichage de la grille                      |
//----------------------------------------------------------


#ifndef AFFICHE_H
#define AFFICHE_H

#include "global.h"
#include "gestion_fichier.h"

// Affiche le message d'accueil
void msg_accueil();

//Affiche le menu principal
void menu_principal();

//Affiche l'encadrer Humain contre Humain
void msg_H_vs_H();

//Affiche le indication pour l'humain
void directive_H();

//Affiche le menu de l'humain contre humain
void menu_H_vs_H();

//Affiche l'encadrer Ordinateur contre humain
void msg_IA_vs_H();

//Affiche le menu de l'ordinateur contre l'humain
void menu_IA_vs_H();

//Affiche la demande de qui commence
void commence_IA();

// Affiche l'encadrer Ordinateur contre Ordinateur
void msg_IA_vs_IA();

//Affich le menu ordinateur contre ordinateur
void menu_IA_vs_IA();

//Affiche toute les statistiques
void statistiques();

//Affiche le menu des options
void menu_option();

//Affiche une grille passé en parametre
void affichage(char *grid);

// EASTER EGGS - Demon
void demon();

//EASTER EGGS - Ange
void ange();

#endif // AFFICHAGE_H inclu 
