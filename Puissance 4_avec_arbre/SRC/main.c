// -------------------------------------------------------- 
// AUTEUR : REYNAUD Nicolas				    |
// FICHIER : main.c	                  		    |
// DATE : 09/01/13					    |
//							    |
// - Définition des fonctions de main.h		            |
// -------------------------------------------------------- 


#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../INC/main.h"

// 6 haute , 7 largeur
int main() // affichage
{
  srand(time(NULL));
  _reset_term();
  int choix = 0,sous_choix = 0,niveau_IA = 0,niveau_IA_2 = 0;
  
  msg_accueil();

  menu_principal();

  do
    {
      
      choix = verif_choix("Quel est votre choix ? ",6);
      switch(choix)
	{
	case -1:
	  printf("\t\tAu revoir et a bientôt\n");
	  pause_ms(1200);
	  _reset_term();// on rend un terminal propre :p
	  exit(EXIT_SUCCESS);
	  break;
	case 1:
	  _clean();

	  msg_H_vs_H();
	  menu_H_vs_H();

	  sous_choix = verif_choix("Quel est votre choix ? ",2);
	  switch(sous_choix)
	    {
	    case -1:
	      _reset_term(); 
	      break;
	    case 1:
	      gestion_stats(1,1);// on incremente le nombre total de partie jouée
	      gestion_stats(2,1); // on incremente le nombre total de partie jouée Humain vs Humain
	      humain(0);
	      _reset_term();
	      break;
	    case 2:
	      humain(1);
	      _reset_term();
	      break;
	    default:
	      _clean();
	      sous_choix = verif_choix("Quel est votre choix ? ",2);
	      break;
	    }// fin switch sous_choix
	  break;// break case 1 - menu_humain
	case 2: 
	  _clean();
	  
	  msg_IA_vs_H();
	  menu_IA_vs_H();
	  

	  niveau_IA = verif_choix("Quel niveau voulez vous ? ",5);
	
	  if(niveau_IA != -1)
   	    IA_vs_H(niveau_IA);
	  
	  

	  _reset_term();
	  break;// break case 2 - menu_humain
	case 3:
	  _clean();
	  msg_IA_vs_IA();
	  menu_IA_vs_IA("1 ère");
	  
	  niveau_IA = verif_choix("Quel niveau voulez vous ? ",9);

	  while(niveau_IA == 666 || niveau_IA == 777)
	    {
	      printf("\t\t-- Erreur -- Aucun easter eggs sur se menu :p.\nQuel niveau voulez vous ? ");
	      niveau_IA = verif_choix("Quel niveau voulez vous ? ",9);
	    }
	  
	  if(niveau_IA != -1)
	    {
	      _clean();
	      msg_IA_vs_IA();
	      printf("La premiere IA aura le niveau %d.\n\n",niveau_IA);
	      printf("Une pause de 5 secondes sera effectuer entre chaque coup de l'IA.\n\n");
	      menu_IA_vs_IA("2 eme");
	      
	      niveau_IA_2 = verif_choix("Quel niveau voulez vous ? ",9);
	      
	      
	      while(niveau_IA_2 == 666 || niveau_IA_2 == 777)
		{
		  printf("\t\t-- Erreur -- Aucun easter eggs sur se menu :p.\nQuel niveau voulez vous ? ");
		  niveau_IA_2 = verif_choix("Quel niveau voulez vous ? ",9);
		}

	      if(niveau_IA_2 != -1)
		{
		  gestion_stats(21,1); // incrementer nb demo vu
		  IA_vs_IA(niveau_IA,niveau_IA_2);
		}
	    }
	  

	  _reset_term();
	  break;// break case 3 - menu_humain
	case 4:
	  _clean();
	  statistiques();
	  do_pause();
	  break;// break case 4 - menu_humain
	case 5:
	  _clean();
	  afficher_regles();
	  do_pause();
	  break;// break case 5 - menu_humain
	case 6:
	  _clean();
	  menu_option();
	  do
	    {
	      sous_choix = verif_choix("Quel est votre choix ? ",2);
	      if(sous_choix == 1)
		{
		  if(reinit_stats() == 1)
		    printf("\t\tLes stats ont bien été remis a zero.\n");
		  else
		    printf("\t\t-- Erreur -- Une erreur s'est produite.\n");
		}
              if(sous_choix != -1)
	         printf("Que voulez vous faire ? ");
	    }while(sous_choix != -1);
	    _reset_term();
	  break;// break case 6 - menu_humain
	case 666:
	  demon();
	  break;
	case 777:
	  ange();
	  break;
	default:
	  _clean();
	  printf("-- Erreur --\tImpossible d'acceder au module %d.\n ",choix);
	  break;
	}
     
      menu_principal();
    }while(1);


  exit(EXIT_SUCCESS);
}
