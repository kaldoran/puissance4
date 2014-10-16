//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas				    |
// FICHIER : gestion_fichier.h                 		    |
// DATE : 09/01/13					    |
//							    |
// - Prototypes des fonctions de gestion_fichier.c          |
//							    |
// - Fonction de verification de la valeur de l'id de la    |
//   partie a charger [ C.F sous menu du menu ordi contre   |
//   humain].                                               |
// - Fonction d'affichage de la liste des parties           |
//   sauvegardée                                            |
// - Fonction de sauvegarde du plateau en cours de parti    |
// - Fonction de chargement d'une grille                    |
// - Fonction d'affichage des regles                        |
// - Fonction de gestion des statistiques                   |
// - Fonction pour reinitialiser les statistiques           |
//----------------------------------------------------------




#ifndef GESTION_FICHIER_H
#define GESTION_FICHIER_H

#include "global.h"
#include "allocation.h"

#define TAILLE_DATE 25 // Taille du tableau pour la date 


#define ADRESSE_STATS "BDD/statistique.txt" // adresse fichier texte des stats
#define ADRESSE_SV "BDD/sv_jeu.txt" // adresse fichier texte de sauvegardes du jeu
#define ADRESSE_REGLES "BDD/regles.txt" // adresse fichier texte des regles

//Verifi que l'ID de la grille que l'utilisateur veut charger est correcte
int verif_id();

//Affiche la liste des parties sauvegardées
void liste_sv();

//Permet de faire une sauvegarde du plateau de jeu 
//Grid -> Grille actuelle - Pseudo1 -> Pseudo du joueur 1 
//Pseudp 2 -> Pseudo du joueur 2 - Pion -> Pion qui devait jouer a se moment la
int sv_plateau(char *grid,char* pseudo1,char* pseudo2,char pion);

//Permet de changer une grille 
//modifie les valeurs de pseudo 1 , pion , grille , pseudo2
int charger_grille(char *grid,char *pseudo1,char* pseudo2,char *pion);

//Affiche les regles presentent dans le fichiers regles.txt
void afficher_regles();

//gere les statistiques.
// 0 pour juste recuperer _ 1 pour recuperer , incrementer et modifier
int gestion_stats(int id,int mode); 

//Reinitialise toutes les stats [ remise a zero ]
int reinit_stats();

#endif // GESTION_FICHIER_H inclu
