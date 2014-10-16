// -------------------------------------------------------- 
// AUTEUR : REYNAUD Nicolas				    |
// FICHIER : eval.c                      		    |
// DATE : 09/01/13					    |
//							    |
// - Définition des fonctions de eval.h                     |
// - Pour plus d'info C.F eval.h	                    |
// -------------------------------------------------------- 

#include <stdio.h>
#include <stdlib.h>

#include "../INC/eval.h"

int eval(char *grille,char pion)
{
  int nb_serie_2X = 0,nb_serie_2O = 0,nb_serie_3X = 0,nb_serie_3O = 0,compteurO = 0,compteurX = 0,ligne,colonne;
  
  //verification  horizontale
  for(ligne = 0;ligne < NB_LIGNE ; ligne++)
    {
      compteurX = 0;
      compteurO = 0;
      for(colonne = 0;colonne < NB_COLONNE;colonne++)
	{
	  if(grille[CASE(ligne,colonne)] == PION_J1)
	    {
	      
	      compteurX++;
	      compteurO = 0;
	    }
	  else if(grille[CASE(ligne,colonne)] == PION_J2){
	    compteurO++;
	    compteurX = 0;
	  }
	  else{
	    compteurX = 0;
	    compteurO = 0;
	  }
	  
	  if(compteurX == 2)
	    nb_serie_2X++;
	  
	  if(compteurO == 2)
	    nb_serie_2O++;
	  
	  if(compteurO == 3){
	    nb_serie_2O--;
	    nb_serie_3O++;
	  }
	  
	  if(compteurX == 3){
	    nb_serie_2X--;
	    nb_serie_3X++;
	  }
	}
    }
  

  
  //vertical
  for(colonne = 0;colonne < NB_COLONNE;colonne++)
    {
      compteurX = 0;
      compteurO = 0;
      for(ligne = 0;ligne < NB_LIGNE ; ligne++)	
	{
	  if(grille[CASE(ligne,colonne)] == PION_J1)
	    {
	      compteurX++;
	      compteurO = 0;
	    }
	  else if(grille[CASE(ligne,colonne)] == PION_J2){
	    compteurO++;
	    compteurX = 0;
	  }
	  else{
	    compteurX = 0;
	    compteurO = 0;
	  }
	  
	  if(compteurX == 2)
	    nb_serie_2X++;
	  
	  if(compteurO == 2)
	    nb_serie_2O++;
	  
	  if(compteurO == 3){
	    nb_serie_2O--;
	    nb_serie_3O++;
	  }
	  
	  if(compteurX == 3){
	    nb_serie_2X--;
	    nb_serie_3X++;
	  }
	}
    }
  

  
  /* Diagonal sens : "\" */
  for(ligne = 0;ligne < NB_LIGNE-1;ligne++) // -1 on verifi la case (i,colonne) et (i+1,colonne+1)
    for (colonne = 1;colonne < NB_COLONNE;colonne++)
      {

	if(grille[CASE(ligne,colonne)] == PION_J1 && grille[CASE((ligne+1),(colonne+1))] == PION_J1 )
	  {
	    if( grille[CASE((ligne+2),(colonne+2))] == PION_J1 && colonne+2 < 7 && ligne+2 < 6)
	      {
		nb_serie_3X++;
		nb_serie_2X--;
	      }
	    else
	      nb_serie_2X++;
	  }

	if(grille[CASE(ligne,colonne)] == PION_J2 && grille[CASE((ligne+1),(colonne+1))] == PION_J2)
	  {
	    if( grille[CASE((ligne+2),(colonne+2))] == PION_J2 && colonne+2 < 7 && ligne+2 < 6)
	      {
		nb_serie_3O++;
		nb_serie_2O--;
	      }
	    else
	      nb_serie_2O++;
	  }
      }

  /* Diagonal sens : "/" */
  for(ligne = 0;ligne < NB_LIGNE-1;ligne++)
    for (colonne = 0;colonne < NB_COLONNE-1;colonne++)
      {
	
	if(grille[CASE(ligne,colonne)] == PION_J1 && grille[CASE((ligne+1),(colonne-1))] == PION_J1 )
	  {
	    if( grille[CASE((ligne+2),(colonne-2))] == PION_J1 && ligne+2 < 6 && colonne-2 >= 0)
	      {	       
		nb_serie_3X++;
		nb_serie_2X--;
	      }
	    else
	      nb_serie_2X++;
	  }
	    
	if(grille[CASE(ligne,colonne)] == PION_J2 && grille[CASE((ligne+1),(colonne-1))] == PION_J2)
	  {
	    if( grille[CASE((ligne+2),(colonne-2))] == PION_J2 && colonne-2 >= 0 && ligne+2 < 6)
	      {
		nb_serie_3O++;
		nb_serie_2O--;
	      }
	    else
	      nb_serie_2O++;
	  }
      }
  if(pion == PION_J2)
    return ((COEF_NB_SERIE_2*nb_serie_2O + COEF_NB_SERIE_3*nb_serie_3O) - (COEF_NB_SERIE_2*nb_serie_2X + COEF_NB_SERIE_3*nb_serie_3X));  
  else
    return ((COEF_NB_SERIE_2*nb_serie_2X + COEF_NB_SERIE_3*nb_serie_3X) - (COEF_NB_SERIE_2*nb_serie_2O + COEF_NB_SERIE_3*nb_serie_3O));
  
}
