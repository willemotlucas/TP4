#include "arbre.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ArbreABR * creer_abr()
{
	ArbreABR * abr = malloc(sizeof(ArbreABR));
	
	if(abr != NULL)
	{
		abr->racine = NULL;
		abr->nb_mots_differents = 0;
		abr->nb_mots_total = 0;
	}

	return abr;
}

NoeudABR * creer_noeud(char * mot)
{
	NoeudABR * noeud = malloc(sizeof(NoeudABR));

	if(noeud != NULL)
	{
		char * motmin = formatage_mot(mot);
		noeud->mot = malloc(strlen(motmin) + 1 * sizeof(char));
		strcpy(noeud->mot, motmin);
		noeud->positions = NULL;
		noeud->filsGauche = NULL;
		noeud->filsDroit = NULL;
	}

	return noeud;
}

int ajouter_noeud(ArbreABR * arbre, NoeudABR * noeud)
{
	if(arbre->racine == NULL)
	{
		arbre->racine = noeud;
	}

	NoeudABR * racine = arbre->racine;
	NoeudABR * pere = arbre->racine;
	
	while(racine != NULL)
	{
		pere = racine;

		if(strcmp(noeud->mot, racine->mot) > 0)
		{
			racine = racine->filsDroit;
		}
		else if(strcmp(noeud->mot, racine->mot) < 0)
		{
			racine = racine->filsGauche;
		}
	}

	if(pere != NULL)
	{
		if(strcmp(noeud->mot, racine->mot) > 0)
		{
			pere->filsDroit = noeud;
			arbre->nb_mots_differents++;
		}
		else if(strcmp(noeud->mot, racine->mot) < 0)
		{
			pere->filsGauche = noeud;
			arbre->nb_mots_differents;
		}
		else
		{
			//Le mot à ajouter existe déjà
			//Il faut mettre à jour sa liste position en ajoutant la position actuelle	
		}

		arbre->nb_mots_total++;

		return 1;
	}
	else
		return 0;
}