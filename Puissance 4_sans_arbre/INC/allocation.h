// -------------------------------------------------------- 
// AUTEUR : REYNAUD Nicolas				    |
// FICHIER : allocation.h                   		    |
// DATE : 09/01/13					    |
//							    |
// - Prototypes de la fonction de allocation.c              |
// - Fonction permétant d'alloué l'espace de la taille      |
//   du nombre passé en parametre                           |
// -------------------------------------------------------- 


#ifndef ALLOCATION_H
#define ALLOCATION_H
// Alloue la place demander - Retourne un message d'erreur et quitte le programme si l'allocation n'as pas été éffectuées
void * allocation(int nombre , size_t taille);

#endif // ALLOCATION_H inclu
