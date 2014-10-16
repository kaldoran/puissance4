// -------------------------------------------------------- 
// AUTEUR : REYNAUD Nicolas				    |
// FICHIER : affichage.c                  		    |
// DATE : 09/01/13					    |
//							    |
// - Définition des fonctions de affichage.h                |
// - pour plus de detaile C.F affichage.h                   |
// -------------------------------------------------------- 


#include <stdio.h>

#include "../INC/affichage.h"

void msg_accueil()
{
  printf("\t\t -----------------------------------------\n\t\t|    Puissance 4 - Par REYNAUD Nicolas    |\n\t\t -----------------------------------------\n\n");
}

void menu_principal()
{

  printf("Choissisez le type de jeu :\n\n");
  printf("\t[1] Humain Vs Humain\n");
  printf("\t[2] Humain Vs Ordi\n");
  printf("\t[3] Ordi Vs Ordi\n");
  printf("\t[4] Statistiques\n");
  printf("\t[5] Regles\n");
  printf("\t[6] Options\n");
  printf("\t[-1] Quitter\n\n");  

  printf("Quel est votre choix ? ");

}

void msg_H_vs_H()
{
  printf("\t\t\t  ------------------------\n\t\t\t| Jeu humain contre humain |\n\t\t\t  ------------------------\n\n");

}

void directive_H()
{

  printf("En cours de partie :\n");
  printf("\t[-1] Quitter\n");
  printf("\t[Colonne 8] Quitter et sauvegarder [Ne pourrons etre supprimée]\n\n");


}

void menu_H_vs_H()
{

  printf("Que voulez vous faire :\n");
  printf("\t[1] Nouvelle partie\n");
  printf("\t[2] Charger partie precedente\n");
  printf("\t[-1] Retour\n\n");
  printf("Quel est votre choix ? ");

}

void msg_IA_vs_H()
{
  printf("\t\t\t  ----------------------------\n\t\t\t| Jeu Ordinateur contre humain |\n\t\t\t  ----------------------------\n\n");

}


void menu_IA_vs_H()
{

  printf("Choissez une difficulter :\n");
  printf("\t[1] Tres facile \t[L'ordi joue au hasard]\n");
  printf("\t[2] Facile \t\t[Profondeur 3]\n");
  printf("\t[3] Moyen  \t\t[Profondeur 5]\n");
  printf("\t[4] Difficile \t\t[Profondeur 7]\n");
  printf("\t[5] Très Difficile \t[Profondeur 9]\n");
  printf("\t[-1] Retour\n\n");
  printf("Quel niveau voulez vous ? ");

}

void msg_IA_vs_IA()
{
  printf("\t\t\t  ---------------------------------\n\t\t\t| Jeu Ordinateur contre Ordinateur |\n\t\t\t  ---------------------------------\n\n");

}

void menu_IA_vs_IA(char *numero_IA)
{
  printf("Choissez le niveau de la %s IA : \n",numero_IA);  
  printf("\t[1] Randoms ( l'IA joue au hasard )\n");
  printf("\t[2 à 9] Niveau de l'IA possible.\n");
  printf("\t[-1] Retour\n");
  
  printf("\nQuel niveau voulez vous ?  ");
}

void commence_IA()
{
  printf("Qui commence ?\n");
  printf("\t[1] L'Ordinateur.\n");
  printf("\t[2] Le joueur humain\n");
  printf("\t[-1] Retour au menu principal [Marche aussi en cours de partie].\n");
  printf("\nQuel est votre choix ? ");

}

void statistiques()
{
  
  printf("Nombre total de partie : %d\n\n",gestion_stats(1,0)); //ligne 1 , mode de recup 0
  printf("Nombre de partie Humain Vs Humain jouée : %d\n\n",gestion_stats(2,0)); // ligne 2 , mode de recuperation 0 [ juste recuperer valeur ]
  printf("Nombre de partie jouer :\n"); 
  printf("\t\t\tEn tres facile : %d\n",gestion_stats(3,0)); // etc pour toutes les lignes
  printf("\t\t\tEn facile : %d\n",gestion_stats(4,0));
  printf("\t\t\tEn moyen : %d\n",gestion_stats(5,0));
  printf("\t\t\tEn difficile : %d\n",gestion_stats(6,0));
  printf("\t\t\tEn très difficile : %d\n",gestion_stats(7,0));
  printf("\t\t\tTotal des parties jouées : %d\n\n",gestion_stats(8,0));
  
  printf("Nombre de victoire contre l'ordinateur :\n");
  printf("\t\t\tEn tres facile : %d\n",gestion_stats(9,0));
  printf("\t\t\tEn facile : %d\n",gestion_stats(10,0));
  printf("\t\t\tEn moyen : %d\n",gestion_stats(11,0));
  printf("\t\t\tEn difficile : %d\n",gestion_stats(12,0));
  printf("\t\t\tEn très difficile : %d\n",gestion_stats(13,0));
  printf("\t\t\tTotal des victoires : %d\n\n",gestion_stats(14,0));

  printf("Nombre de défaite contre l'ordinateur :\n");
  printf("\t\t\tEn tres facile : %d\n",gestion_stats(15,0));
  printf("\t\t\tEn facile : %d\n",gestion_stats(16,0));
  printf("\t\t\tEn moyen : %d\n",gestion_stats(17,0));
  printf("\t\t\tEn difficile : %d\n",gestion_stats(18,0));
  printf("\t\t\tEn très difficile : %d\n",gestion_stats(19,0));
  printf("\t\t\tTotal des défaites : %d\n\n",gestion_stats(20,0));

  printf("Nombre de démo que vous avez vu : %d\n\n",gestion_stats(21,0));
} 

void menu_option()
{
  printf("\t\t\t  ---------------------------\n\t\t\t|        Menu Option        |\n\t\t\t  ---------------------------\n\n");
  printf("\t[1] Reinitialiser les stats [ Action définitive ]\n");
  printf("\t[2] Supprimer une partie sauvegarder [Non implémenté]\n");
  printf("\t[-1] Retour\n\n");
  
  printf("Que voulez vous faire ? ");


}

void affichage(char *grid)
{
  int colonne,ligne,nb_tire;
  printf("\n");
  for(ligne = 0 ; ligne < NB_LIGNE ; ligne ++)
    {
      printf("%d |",ligne+1);
      
      for( colonne = 0; colonne < NB_COLONNE; colonne++)	
	printf(" %c",grid[CASE(ligne,colonne)]);
      
      printf(" |\n");
    }
  printf("   "); // 3 espaces pour decaler les - de la taille de %d |.

  for(nb_tire = 0; nb_tire < 2*NB_COLONNE;nb_tire++)
    printf("-");

  printf("\n    ");

  for(colonne = 0; colonne < NB_COLONNE;colonne++)
    printf("%d ",colonne+1);

  printf("\n\n");
}

void demon() // EASTER EGGS - Source ascii http://www.geocities.com/spunk1111/haloween.htm
{
  _clean();
  printf("       (\\-\"````\"-/)\n       //^\\    /^\\\\\n      ;/ ~_\\  /_~ \\;\n      |  / \\\\// \\  |\n     (,  \\0/  \\0/  ,)\n      |   /    \\   |\n      | (_\\.__./_) |\n       \\ \\-v..v-/ /\n        \\ `====' /\n         `\\\\\\///'\n          '\\\\//'\n            \\/\n\n");
  printf("Essayer de jouer contre une IA de niveau 666 , ceci pourrait être marrant.\n");

  do_pause();

}

void ange() // EASTER EGGS - Source ascii http://www.ascii-art.de/ascii/ab/angel.txt
{

  _clean();
    
  printf("             -=-\n          (\\  _  /)\n          (`\\(\")/')\n          (`/<v>\\\')\n           \\\\/^\\//\n            /   \\\n           /     \\\n           `-._.-\'\n");
  
  printf("Psiiiit !\nA ce qu'il paraît l'ordi se montre gentil si vous lui dites 777.\nNe dites pas que c'est moi qui nous l'ai dit !\n");
  do_pause();


}
