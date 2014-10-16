// -------------------------------------------------------- 
// AUTEUR : REYNAUD Nicolas				    |
// FICHIER : verif.c	                 		    |
// DATE : 09/01/13					    |
//							    |
// - Définition des fonctions de verif.h	            |
// - pour plus d'info voir verif.h		            |
// -------------------------------------------------------- 

#include <stdio.h>
#include <stdlib.h>

#include "../INC/verif.h"


int colonne_pleine(char *grille,int num_col) // retourne 1 si la colonne est pleine , 0 sinon
{
  if(grille[CASE(0,num_col-1)] == '.') // on verifit que le haut de la colonne
    return 0;
  return 1;
  
}


char verif_grille(char * grille , char pion_a_verif) // verifie que apres avoir jouer un couip si le coup est gagnant
{

  int ligne,colonne=0,pion=0;
  
  // verification de l'alignement de 4 piont a l'horizontal
  
  for(ligne = 0;ligne < NB_LIGNE;ligne++)
    {
      for(colonne = 0;NB_COLONNE-colonne+pion >= NB_PION_A_ALIGNER;colonne++)
	{
	  //printf("ligne : %d,colonne : %d\n",ligne,colonne);
	  if(grille[CASE(ligne,colonne)] == pion_a_verif)
	    {
	      pion++;
	      if(pion == NB_PION_A_ALIGNER)
		return 1;
	    }
	  else
	    pion = 0;
	  
	}
    }
  // Verifie la vertical
  for(colonne = 0;colonne < NB_COLONNE;colonne++)
    {
      for(ligne = 0;NB_LIGNE-ligne+pion >= NB_PION_A_ALIGNER;ligne++)
	{
	  // printf("ligne2 : %d,colonne : %d\n",ligne,colonne);
	  if(grille[CASE(ligne,colonne)] == pion_a_verif)
	    {
	      pion++;
	      if(pion == NB_PION_A_ALIGNER)
		return 1;
	    }
	  else
	    pion = 0;
	}
    }
  

  // verification grille diagonal , on part de en haut a gauche de la grille 
  for(ligne = 0;NB_LIGNE - ligne >= NB_PION_A_ALIGNER;ligne++)
    for (colonne = 0;NB_COLONNE-colonne >= NB_PION_A_ALIGNER;colonne++)
      if(grille[CASE(ligne,colonne)] == pion_a_verif && grille[CASE((ligne+1),(colonne+1))] == pion_a_verif && grille[CASE((ligne+2),(colonne+2))] == pion_a_verif && grille[CASE((ligne+3),(colonne+3))] == pion_a_verif)
	  return 1;
  
  // verification grille diagonal , on part de en haut a droite
  for(ligne = 0;NB_LIGNE-ligne >= NB_PION_A_ALIGNER;ligne++)
    for(colonne = NB_PION_A_ALIGNER-1;colonne < NB_COLONNE;colonne++)
      {
	if(grille[CASE(ligne,colonne)] == pion_a_verif && grille[CASE((ligne+1),(colonne-1))] == pion_a_verif && grille[CASE((ligne+2),(colonne-2))] == pion_a_verif && grille[CASE((ligne+3),(colonne-3))] == pion_a_verif)
	return 1;
      }

  // on retourne 0 si on a jamais trouver 4 pion aligné
  return 0;    
    
}


int verif_choix(char *phrase,int val_max)
{

  int choix;
  while(1)
    {   
      while(scanf("%d",&choix) == 0) // Si l'utilisateur entre autre chose qu'un nombre
	printf("\t-- Erreur --\tLa valeur entrée n'est pas un nombre.\n%s",phrase); 
      if(choix == -1 || choix == 666 || choix == 777)
	return choix;
      if(choix > val_max || choix < 1)
	printf("\t-- Erreur --\tLa valeur entrée est soit trop grande soit trop petite.\n%s",phrase);
      else
	return choix;
  
      videbuffer();
    }
  return -1;
}
  


int grille_pleine(char* grille) // retourne 1 si la grille est pleine
{
  int colonne;

  for(colonne = 0 ; colonne < NB_COLONNE ; colonne++)
    if(grille[CASE(0,colonne)] == '.') // on verifi que la grille est pleine pour se faire on verifie que la premiere ligne ; Si la premier ligne est pleine alors la grille est pleine elle aussi.
	return 0;
  return 1; 
}
