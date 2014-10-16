// -------------------------------------------------------- 
// AUTEUR : REYNAUD Nicolas				    |
// FICHIER : gestion_fichier.c                 		    |
// DATE : 09/01/13					    |
//							    |
// - Définition des fonctions de gestion_fichier.h          |
// - pour plus de detail C.F gestion_fichier.h              |
// -------------------------------------------------------- 



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../INC/global.h"
#include "../INC/gestion_fichier.h"
#include "../INC/verif.h"

int verif_id()
{
  FILE* fichier = fopen(ADRESSE_SV, "r");
  int compteur = 0,id = 0;
  fscanf(fichier,"COMPTEUR : %d",&compteur);

  printf("Selectionner l'id de la grille a charger : ");
  id = verif_choix("Selectionner l'id de la grille a charger : ",compteur);
  while(id == 666 || id == 777)
    {
      printf("\t-- Erreur -- Arreter de chercher un menu caché de partout.\nSelectionner l'id de la grille a charger : ");
      id = verif_choix("Selectionner l'id de la grille a charger : ",compteur);


    }
  return id;
  fclose(fichier);

}

void liste_sv()
{
  
  char caractereActuel = 'z';
  int compteur = 0;
 
  FILE* fichier = fopen(ADRESSE_SV, "r+");

  printf("Liste des partie :\n");
  fscanf(fichier,"COMPTEUR : %d",&compteur);
  
  if(compteur == 0)
    {
      printf("\tAucune partie sauvegardée.\n");
      printf("\t[-1] Retour menu principal\n\n");
      return;
    }
  compteur = 0;
  while(caractereActuel != '\n')
    caractereActuel =  fgetc(fichier);
  while(caractereActuel != EOF)
    {
      if(caractereActuel == '\n')
	compteur++;

      
      if(compteur%2 == 0)
	printf("%c",caractereActuel);

      caractereActuel = fgetc(fichier);
      
    }
  printf("     [-1] Retour menu principal\n");
  printf("\n");
  fclose(fichier);
  return;

}

int sv_plateau(char *grid,char* pseudo1,char* pseudo2,char pion)
{  
  time_t timestamp = time(NULL);
  char* date_forme = (char*) allocation(TAILLE_DATE,sizeof(char));

   
  strftime(date_forme, TAILLE_DATE , "Le %d/%m/%y à %H;%M;%S" , localtime(&timestamp));
  
  FILE* fichier = fopen(ADRESSE_SV, "r+");

  int compteur = 0;
  fscanf(fichier,"COMPTEUR : %d",&compteur);
  compteur++;
  rewind(fichier);
  
  fprintf(fichier,"COMPTEUR : %d",compteur);
  if(fichier != NULL)
    {
      fseek(fichier, 0, SEEK_END);
      fprintf(fichier,"     [%d] - %s : %s Contre %s  - Tour %c\n%s\n",compteur,date_forme,pseudo1,pseudo2,pion,grid);      
    }
  else
    return 0;

  fclose(fichier);
  
  return 1;
}


int charger_grille(char *grid,char* pseudo1,char* pseudo2,char *pion)
{
  FILE* fichier = fopen(ADRESSE_SV, "r");
  int compteur = -1; // -1 car il y a 2 lignes inutile et que les ids des parties commence a 1.
  char caractereActuel = 'z';
  
  int id = 0;
  id = verif_id();

  if(id == -1)
    return 0;
  while(caractereActuel != EOF && compteur/2 != id)
    {
      caractereActuel = fgetc(fichier);
      if(caractereActuel == '\n')
	compteur ++;
      if(compteur/2 == id-1)
	{
	  fscanf(fichier,": %s Contre %s - Tour %c",pseudo1,pseudo2,pion);
	}
	
    }
  fgets(grid,TAILLE_TAB+1,fichier); 
  

  fclose(fichier);

  return 1;
}



void afficher_regles() // 0 pour juste recuperer - 1 pour recuperer , incrementer et modifier
{                         
  char caractereActuel = 'z';
  FILE* fichier = fopen(ADRESSE_REGLES, "r");
  caractereActuel = fgetc(fichier);

  while(caractereActuel != EOF)
    {
      printf("%c",caractereActuel);
      caractereActuel = fgetc(fichier);
    }
  fclose(fichier);
  return;
}




int gestion_stats(int id,int mode) // 0 pour juste recuperer - 1 pour recuperer , incrementer et modifier
{                         
  if((mode != 0 && mode != 1) || id > 21)
    return 0;
  int compteur = 1,val = 0;
  int caractereActuel; // on met un int pour economiser la mémoire
  FILE* fichier = NULL;
  if(mode == 0)
    fichier = fopen(ADRESSE_STATS, "r");
  else 
    fichier = fopen(ADRESSE_STATS, "r+");

  if(fichier != NULL)
    {
      if(id != 1)
	caractereActuel = fgetc(fichier);
      
      while(compteur != id)
	{
	  caractereActuel = fgetc(fichier);
	  if(caractereActuel == '\n')
	    compteur ++;
	}        
      fscanf(fichier, "%d",&val);
      if(mode == 0)
	{
	  fclose(fichier);
	  return val;
	}
      else
	{
	  val ++;
	  rewind(fichier);
	  if(id != 1)
	    caractereActuel = fgetc(fichier);
	  compteur = 1;
	  while(compteur != id)
	    {
	      caractereActuel = fgetc(fichier);
	      if(caractereActuel == '\n')
		compteur ++;
	    }    
	  fprintf(fichier,"%d", val);
	  fclose(fichier);
	  return 1;
	}
    }
  else
    return 0;
}



int reinit_stats()
{
  int val = 0,compteur = 1,caractereActuel,i = 1;
  FILE* fichier = fopen(ADRESSE_STATS, "r+");
  if(fichier != NULL)
    {
      for(i=1;i<=22;i++) // de 1 jusqu'a 22 soit 21 statistiques reinitialisée	
	{
	  while(compteur != i)
	    {
	      caractereActuel = fgetc(fichier);
	      if(caractereActuel == '\n')
		compteur ++;
	    }
	  fscanf(fichier, "%d",&val);
	
	  val = 0;
	  rewind(fichier);
	  if(i != 1)
	    caractereActuel = fgetc(fichier);
	  compteur = 1;
	  while(compteur != i)
	    {
	      caractereActuel = fgetc(fichier);
	      if(caractereActuel == '\n')
		compteur ++;
	    }    
	  fprintf(fichier,"%d                                                   ", val);
	}
      fprintf(fichier,"\n\n\n\n");
      return 1;
    }
  return 0;


}
