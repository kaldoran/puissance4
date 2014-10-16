//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas				    |
// FICHIER : delay_sleep.h                   		    |
// DATE : 09/01/13					    |
//							    |
// - Definition de la maccro pause_ms en fonction de l'OS   |
// - Fait une pause de X milliseconde passé en parametre    |
//----------------------------------------------------------

#ifndef PAUSE_H
#define PAUSE_H

/* DETECTION DU SYSTEME D'EXPLOITATION TIREE DE http://stackoverflow.com/questions/8666378/detect-windows-or-linux-in-c-c */

#if defined (WIN32) || defined (_WIN32) // si le systeme d'exploitation est windows on inclu le fichier systeme contenant Sleep
#include <windows.h> 

// on définit une maccro 
#define pause_ms(ms) Sleep(ms) 

#elif defined (__linux) || defined (linux) // sinon :  Os = linux on inclu le meme fichier

#include <unistd.h>
// on définit la meme maccro avec le meme nom
#define pause_ms(ms) usleep((ms) * 1000) 

#endif

#endif // PAUSE_H inclu
