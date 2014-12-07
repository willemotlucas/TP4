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

int charger_fichier(ArbreABR * arbre, char * filename)
{
	FILE * fichier = NULL;
	
	char ligne[TAILLE_LIGNE] = "";
	char mot[TAILLE_MOT] = "";
	char curseur;
	
	int position_curseur = 0;
	int nbmot = 0;
	int num_ligne = 1;
	int ordre = 1;
	int num_phrase = 1;
	int i = 0;

	fichier = fopen(filename, "r");

	if(fichier != NULL)
	{
		while(fgets(ligne, TAILLE_LIGNE, fichier) != NULL)
		{
			while(ligne[position_curseur] != '\n')
			{
				while(ligne[position_curseur] != ' ' && ligne[position_curseur] != '.')
				{
					mot[i] = ligne[position_curseur];
					i++;
					position_curseur++;
				}

				nbmot ++;
				// ListePosition * listeP = creer_liste_positions();
				// ajouter_position(listeP, num_ligne, ordre, num_phrase);
				// NoeudABR * n = creer_noeud(mot, listeP);
				// ajouter_noeud(arbre, n);

				printf("%s ", mot);

				if(ligne[position_curseur] == '.')
				{
					printf(".");
					num_phrase++;
				}

				for(i = 0; i < TAILLE_MOT; i++)
				{
					mot[i] = '\0';
				}

				i = 0;
				position_curseur++;
				ordre++;
			}

			i = 0;
			num_ligne++;
			position_curseur = 0;
			printf("\n");
		}

		fclose(fichier);
	}

	return nbmot;
}