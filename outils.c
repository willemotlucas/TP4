#include "liste.h"
#include "arbre.h"
#include "outils.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE_LIGNE 1000
#define TAILLE_MOT 20

char * formatage_mot(char * chaine)
{
	char * copy = malloc(strlen(chaine)+1 * sizeof(char));

	if(copy != NULL)
	{
		int i;
		strcpy(copy,chaine);

		for(i = 0; i < strlen(chaine); i++)
		{
			copy[i] = tolower(chaine[i]);
		}

		return copy;
	}

	free(copy);
	return NULL;		
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int charger_fichier(ArbreABR * arbre, char * filename)
{
	FILE * fichier = NULL;

	char ligne[TAILLE_LIGNE] = "";
	char mot[TAILLE_MOT] = "";

	fichier = fopen(filename, "r");

	char c = '\0'; //caractère lu par le curseur
	int i = 0; //curseur qui parcourt toute une ligne
	int j = 0; //curseur d'un mot
	int k = 0; //pour la remise à zero de mot[]

	int ordre = 1; //compteur de position dans une phrase
	int num_ligne = 1; //numéro de la ligne lu
	int num_phrase = 1; //numéro de la phrase lu
	int nbmot = 0; 

	if(fichier != NULL)
	{
		//On isole les lignes une par une
		while(fgets(ligne, TAILLE_LIGNE, fichier) != NULL)
		{
			//Puis on lit chaque caractère de cette ligne
			for(i = 0; i < strlen(ligne); i++)
			{
				c = ligne[i];

				//Si le caractère lu n'est ni un point ni un espace
				//Alors on est toujours en train de parcourir un 
				//même mot que l'on enregistre
				if(c != ' ' && c != '.' && c != '\n') 
				{
					// printf("%c", c);
					mot[j] = c;
					j++;
				}

				//Si le caractere est un . ou un ' ' alors on change de mot
				//On enregistre la position du mot qu'on vient de lire
				//On créé le noeud avec le mot + sa position
				//On ajoute le noeud dans l'arbre
				else if(c != '\n')
				{
					
					// printf("mot ajouté : %s\n", mot);
					ListePosition * listeP = creer_liste_positions();
					if(ajouter_position(listeP, num_ligne, ordre, num_phrase))
					{
						NoeudABR * n = creer_noeud(mot, listeP);
						if(ajouter_noeud(arbre, n));
						{
							//On remet à zéro le tableau qui sert à stocker
							//le mot qui est lu
							for(k = 0; k < TAILLE_MOT; k++)
								mot[k] = '\0';
							
							j = 0;
							ordre++;
							nbmot++;
						}
					}

				}

				//Si le caractère lu est un point, on change de phrase
				if(c == '.')
				{
					// printf(".");
					num_phrase++;
				}
			}

			num_ligne++;
			ordre = 1;
		}

		return nbmot;
	}

	return 0;
}