// -------------------------------------------------------- 
// AUTEUR : REYNAUD Nicolas				    |
// FICHIER : IA.c	                  		    |
// DATE : 09/01/13					    |
//							    |
// - Définition des fonctions de IA.h	                    |
// - pour plus d'info voir IA.h			            |
// -------------------------------------------------------- 


#include <stdio.h>
#include <stdlib.h>

#include "../INC/IA.h"


int hasard(int max) // fonction hasard , donne un nombre compris entre 0 et max de facon aléatoire.
{
  return (int)  ((float) rand() / RAND_MAX * (max + 1));
}


void IA_vs_H(int niveau)
{

  int joue_en = 0,gagnant = 0,commence = 0,niveau_IA = 0;
  char pion = PION_J2;
  char *grille = (char*) allocation(TAILLE_TAB+1,sizeof(char)); // +1 pour '\0'
  init_grille(grille);

  if(niveau != 777 || niveau != 666)
    gestion_stats(3+(niveau-1),1); // on incremente la stats en rapport avec le niveau de l'IA


  switch(niveau)
    {
    case 1:
      niveau_IA = 1;
      break;
    case 2:
      niveau_IA = 3;
      break;
    case 3:
      niveau_IA = 5;
      break;
    case 4:
      niveau_IA = 7;
      break;
    case 5:
      niveau_IA = 9;
      break;
    case 666:
      niveau_IA = 11;
      break;
    case 777:
      niveau_IA = -1;
      break;
    default:
      return;
      break;
    }   
   



  _clean();
  msg_IA_vs_H();
  if(niveau_IA == -1) // EASTER EGGS
    {
      printf("\tL'IA vas vous \" aider \" a gagner ^^\n\n");
      pion = PION_J1;
    }

  commence_IA();
  
  commence = verif_choix("\nQuel est votre choix ? ",2); // demande qui commence
  if(commence == -1)
    return;
  if(commence == 2)
    {
      _clean();
      affichage(grille);
      gagnant = humain_IA(grille); // retourne 1 si il gagne
    }
  if(gagnant == -1)
    return;

  do
    {
      if(commence == -1)
	return ;
	  
      _clean();
      msg_IA_vs_H();
	  
      if(niveau_IA == -1) // Si le mode de triche est activé on joue au hasard que avec des CROIX [ pion joueur ]
	joue_en = IA_jouer(grille,1,pion);
      else
	joue_en = IA_jouer(grille,niveau_IA,pion);
      pause_ms(500);
      _clean();
      msg_IA_vs_H();

      printf("Je joue dans la colonne %d.\n",joue_en);
	  
      inserer(grille,joue_en,pion);
      affichage(grille);
      if(verif_grille(grille,pion))
	gagnant = 2;
	  
      if(!(grille_pleine(grille)) && gagnant != 2 )
	gagnant = humain_IA(grille); // retourne 1 si il gagne
      
      if(gagnant == -1)
	return;
    }while(!(grille_pleine(grille)) && gagnant == 0  );
      
  _clean();
  affichage(grille);
      
  printf("Fin de partie.\n\n");
  if(gagnant == 1 && niveau != -1)
    {
      printf("\tVous avez gagné , bravo ! :)\n");
      gestion_stats(9+(niveau-1),1);
      gestion_stats(14,1);
    }
  else if(gagnant == 2 && niveau != -1)
    {
      printf("\tVous vous êtes bien battu mais j'ai gagné.\n\n");
      gestion_stats(15+(niveau-1),1);
      gestion_stats(20,1);
    }
  else if (niveau_IA != -1)
    printf("\tMatch nul ! ... Belle partie cependant.\n");
  
  if(niveau_IA == -1)
    printf("\tBravo ! Mais je crois que je vous ai un peu trop aidé =D\n");
 

      free(grille); // on libere la grille allouée
      do_pause();
}


void IA_vs_IA(int niveau_IA_1,int niveau_IA_2)
{
  _reset_term();
  int colonne = 0,niveau = niveau_IA_1;
  char pion = PION_J1;

  char *grille = (char*) allocation(TAILLE_TAB+1,sizeof(char));

  init_grille(grille);

  do
    {
      _clean();
      msg_IA_vs_IA();
      colonne = IA_jouer(grille,niveau,pion);
      pause_ms(500);
      _clean();
      msg_IA_vs_IA();
      printf("L'IA [ niveau %d ] possédant les %c joue en %d.\n",niveau,pion,colonne);
      
      inserer(grille,colonne,pion);
      affichage(grille);
      pause_ms(5000); // on fait une pause de 5s [ sinon l'ordi est trop rapide est on voit pas le jeu
      if(verif_grille(grille,pion))
	colonne = -1;
      else
	{
	  (pion == PION_J1) ? (pion = PION_J2) : (pion = PION_J1); // on inverse les pions
	  (niveau == niveau_IA_1) ? (niveau = niveau_IA_2) : (niveau = niveau_IA_1); // et les niveaux des IA
	}
      
    }while(!(grille_pleine(grille)) && colonne != -1);
   printf("Mode démo fini.\n\n");

  if(colonne == -1)
    {
      printf("\tL'IA possédant les '%c' de niveau %d a battu ",pion,niveau);
      (pion == PION_J1) ? (pion = PION_J2) : (pion = PION_J1);
      (niveau == niveau_IA_1) ? (niveau = niveau_IA_2) : (niveau = niveau_IA_1);
      printf("l'IA possédant les '%c' niveau %d.\n\n",pion,niveau);
    }
  else
    printf("\tAucune des deux IA n'a gagnée.\n");

  free(grille); // on libere la grille allouée

  do_pause();
}




int IA_jouer(char* grid,int profondeur,char pion) 
{
  printf("Je refléchis ...\n");
  int alpha = -100000,beta = 100000,tmp = 0,colonne,colonne_a_jouer = 4;

  if(profondeur < 2) 
    {
      do
	{
	    colonne = hasard(7);
	}while(colonne_pleine(grid,colonne));
      return colonne;
    }


  for(colonne=1;colonne<=NB_COLONNE;colonne++)
    {
      if(!colonne_pleine(grid,colonne))
	{
	  inserer(grid,colonne,pion); // on commence par les coups possible par l'ordinateur
	  
	  tmp = Min(grid,profondeur,profondeur-1,alpha,beta,pion);
	  
	  retirer(grid,colonne,pion);
	  
	  
	  if(tmp == COEF_NB_SERIE_4) // Si la colonne est gagnante on joue direct dedans
	    return colonne;
	  
	  
	  
	  if(tmp > alpha || tmp == -COEF_NB_SERIE_4) // si la colonne est perdante
	    {
	      alpha = tmp;
	      colonne_a_jouer = colonne;
	    }
	}
    }
  return colonne_a_jouer;

}




int Min(char* grid,int profondeur_max,int profondeur,int alpha,int beta, char pion)
{
  if(verif_grille(grid,pion))
    return COEF_NB_SERIE_4 - (profondeur_max - profondeur);
    
  if(profondeur == 0)
    return eval(grid,pion);

  (pion == PION_J1) ? (pion = PION_J2) : (pion = PION_J1);
 
  int colonne,tmp;

 
  for(colonne=1;colonne<=NB_COLONNE && alpha < beta;colonne++)
    {
      if(!colonne_pleine(grid,colonne))
	{
	  inserer(grid,colonne,pion); // Min insere les pions de l'ennemie

	  tmp = Max(grid,profondeur_max,profondeur-1,alpha,beta,pion);
	  
	  if(tmp < beta) // on rajoute de l'aléatoire si 2 colonnes sont identiques 
	    beta = tmp;
	     
	  retirer(grid,colonne,pion); // Min insere les pions de l'ennemie
	}
      
    }
  

  return beta;
}


int Max(char* grid,int profondeur_max,int profondeur,int alpha,int beta,char pion)
{

  if(verif_grille(grid,pion))
    return -COEF_NB_SERIE_4 + (profondeur_max - profondeur);

  if(profondeur == 0)
    return eval(grid,pion);

  (pion == PION_J1) ? (pion = PION_J2) : (pion = PION_J1);


  int colonne,tmp;
  for(colonne=1;colonne<=NB_COLONNE && alpha < beta;colonne++)
    {
      if(!colonne_pleine(grid,colonne))
	{
	  inserer(grid,colonne,pion);

	  tmp = Min(grid,profondeur_max,profondeur-1,alpha,beta,pion);
          
	  
	  if(tmp > alpha)
	    alpha = tmp;
	  

	  retirer(grid,colonne,pion);
	  
	    
	}
    }
  
  return alpha; 
}


