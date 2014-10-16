        ==================================================
       |              Programme : Puissance4              |
       |             Auteur : REYNAUD Nicolas             |
        ==================================================


--------------------------------------------------------
    INSTALLATION
--------------------------------------------------------

	Pour installer le programme commencer par décompresser 	l'archive 
	dans le dossier de votre choix.
	
	Ensuite a l'aide du terminal accéder au fichier nouvellement crée 
	lors de la décompression.
	Choissisez ensuite si vous voulez la version avec ou sans arbre :
		- avec arbre : cd Puissance4_avec_arbre
		- sans arbre : cd Puissance4_sans_arbre
	
	Une fois dans ce dossier taper la commence "make" ou "make install"
        pour lancer la compilation.

	Un exécutable au nom de "puissance4" sera créé dans le dossier 
	courant.

--------------------------------------------------------
    DESINSTALLATION
--------------------------------------------------------

	Pour désinstaller le programme placer vous dans le dossier
	où le fichier makefile est présent.

	Taper ensuite simplement la commande "make uninstall"

	Cette commande supprimera le contenu du fichier 
	OBJ et l'exécutable "puissance4".

--------------------------------------------------------
    UTILISATION
--------------------------------------------------------

	Pour l'utilisation , placer vous dans le dossier où la commande 
	"make" a été exécuté.
	
	Lancer ensuite le programme a l'aide de la commande :
		./puissance4

	Pour naviguer utiliser les menus prévus dans le jeu.



	
--------------------------------------------------------
    LISTING FICHIER 
--------------------------------------------------------

[Puissance 4_avec_arbre] && [Puissance 4_sans_arbre] ont les memes sous fichiers.

+--- SRC
|   +--- main.c
|   +--- allocation.c
|   +--- global.c
|   +--- affichage.c
|   +--- modif_grille.c
|   +--- eval.c
|   +--- IA.c
|   +--- verif.c
|   +--- gestion_fichier.c
|   +--- humain.c
+--- BDD
|   +--- regles.txt
|   +--- sv_jeu.txt
|   +--- statistique.txt
+--- INC
|   +--- modif_grille.h
|   +--- delay_sleep.h
|   +--- affichage.h
|   +--- eval.h
|   +--- IA.h
|   +--- main.h
|   +--- gestion_fichier.h
|   +--- humain.h
|   +--- verif.h
|   +--- allocation.h
|   +--- global.h
+--- OBJ
+--- makefile
+--- README.txt

--------------------------------------------------------
    CONTACT
--------------------------------------------------------

Pour tout renseignement complementaire me contacter sur : 
	nicolas.reynaud@etu.univ-st-etienne.fr
