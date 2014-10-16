// -------------------------------------------------------- 
// AUTEUR : REYNAUD Nicolas				    |
// FICHIER : humain.c	                  		    |
// DATE : 09/01/13					    |
//							    |
// - Définition des fonctions de humain.h                   |
// - pour plus d'info voir humain.h		            |
// -------------------------------------------------------- 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../INC/humain.h"

int humain_IA(char *grille) 
{
  int colonne = 0;
  do
    {
      do
	{
	  printf("\nDans quel colonne voulez vous jouer ? ");
	  colonne = verif_choix("Dans quel colonne voulez vous jouer ? ",7);
	  if(colonne == -1)
	    return -1;
	  if(colonne == 777)
	    printf("\tVous devriez essayer de jouer en %d.\n",IA_jouer(grille,5,PION_J1));
	  if(colonne == 666)
	    printf("\tAucun easter eggs avec 666 ici .\n");
	}while(colonne_pleine(grille,colonne) || colonne == 666); 
	
      inserer(grille,colonne,PION_J1);
      

      if(verif_grille(grille,PION_J1))
	return 1;
      else
	return 0;
      
    
    }while(1);
}





void humain(int mode) // 0 mode normal - 1 mode continuer partie
{
  _clean();

  char *grille = (char*) allocation(TAILLE_TAB+1,sizeof(char)); // +1 pour '\0'
  init_grille(grille);
  char *pseudo1 = (char*) allocation(TAILLE_MAX_PSEUDO,sizeof(char));
  char *pseudo2 = (char*) allocation(TAILLE_MAX_PSEUDO,sizeof(char));

  int colonne = 0,gagnant = 0;
  char pion = PION_J1; // Les X commencerons toujours :)
  msg_H_vs_H();
  directive_H();

  if(mode == 1)
    {
      liste_sv();
      if(charger_grille(grille,pseudo1,pseudo2,&pion) == 0)
	return;
      printf("\nDebut de la partie dans %ds ... \n",DELAY/1000);
    }

  if(mode == 0)  
    {
      do
	{
	  printf("Joueur 1 entrer votre pseudo [max 20 caracteres - Min 3 caracteres] : \n");
	  scanf("%s",pseudo1);
	}while(strlen(pseudo1) > TAILLE_MAX_PSEUDO || strlen(pseudo1) < TAILLE_MIN_PSEUDO);
      printf("%s vous aurez les X.\n",pseudo1);
      do
	{
	  printf("Joueur 2 entrer votre pseudo [max 20 caracteres]: \n");
	  scanf("%s",pseudo2);
	  }while(strlen(pseudo2) > TAILLE_MAX_PSEUDO || strlen(pseudo2) < TAILLE_MIN_PSEUDO);
      printf("%s vous aurez les O.\n",pseudo2);
      printf("\nDebut de la partie dans %ds ... \n",DELAY/1000);
    }
 
  pause_ms(DELAY);
  _clean();
  do
    {
      msg_H_vs_H();
      affichage(grille);
      
      if(pion == 'X')
	printf("%s [Possédant les X] a vous.\nDans quel colonne voulez vous jouer ? ",pseudo1);
      if(pion == 'O')
	printf("%s [Possédant les O] a vous.\nDans quel colonne voulez vous jouer ? ",pseudo2);
      colonne = verif_choix("Dans quel colonne voulez vous jouer ? ",8);
      while(colonne == 666 || colonne == 777)
	{
	  if(colonne == 777) // on lui donne un coup l'aidant
	    printf("Vous devriez essayer de jouer en colonne : %d.\n",IA_jouer(grille,5,pion));
	  else
	    printf("\tAucun easter eggs avec 666 ici .\n");
	  printf("Dans quel colonne voulez vous jouer ? ");
	  colonne = verif_choix("Dans quel colonne voulez vous jouer ? ",8);
	}


      if(colonne != -1 && colonne != 8)
	{

	  if(colonne_pleine(grille,colonne))
	    {
	      _clean();
	      printf("\n\t-- Erreur -- La colonne dans laquel vous essayer de jouer est pleine.\n");
	    }
	  else
	    {
	      _clean();
	      inserer(grille,colonne,pion);
	      if(verif_grille(grille,pion))
		gagnant = 1;
	      else
		(pion == PION_J1) ? (pion = PION_J2) : (pion = PION_J1);

	    }
	}  

    }while(colonne != -1 && colonne != 8 &&  gagnant != 1 && !(grille_pleine(grille)));


  _clean();
  if(colonne == -1)// le joueur a fait -1
    return;
  if(colonne == 8)
    {
   
	if(sv_plateau(grille,pseudo1,pseudo2,pion))
	  printf("\tVotre partie a bien été sauvegarder");
      else
	printf("\tUn erreur s'est produite, Merci de me contacter");
    }
  else
    {
      if(gagnant == 0)
	printf("\n\t-- Fin de partie --\n\n Match null !\n");
      else
	{
	  if(pion == 'X')
	    printf("\n\t-- Fin de partie --\n\nLe joueur \"%s\" possédant les %c a gagner.\n",pseudo1,pion);
	  if(pion == 'O')
	    printf("\n\t-- Fin de partie --\n\nLe joueur \"%s\" possédant les %c a gagner.\n",pseudo2,pion);
	}
    }
  affichage(grille);

  free(grille); // on libere la grille allouée

  do_pause();
  
}
