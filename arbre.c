#include "liste.h"
#include "arbre.h"
#include "outils.h"
#include "pile.h"

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

NoeudABR * creer_noeud(char * mot, ListePosition * listeP)
{
	NoeudABR * noeud = malloc(sizeof(NoeudABR));

	if(noeud != NULL)
	{
		noeud->mot = formatage_mot(mot);
		noeud->positions = listeP;
		noeud->filsGauche = NULL;
		noeud->filsDroit = NULL;
	}

	return noeud;
}

int ajouter_noeud(ArbreABR * arbre, NoeudABR * noeud)
{
	//Si l'arbre est vide
	if(arbre->racine == NULL)
	{
		arbre->racine = noeud;
	}

	//Si l'arbre contient des éléments
	else
	{

		NoeudABR * racine = arbre->racine;
		NoeudABR * pere = arbre->racine;
		
		while(racine != NULL)
		{
			pere = racine;

			if(strcmp(noeud->mot, racine->mot) > 0)
			{
				if(racine->filsDroit != NULL)
					racine = racine->filsDroit;
				else
					racine = NULL;
			}
			else if(strcmp(noeud->mot, racine->mot) < 0)
			{
				if(racine->filsGauche != NULL)
					racine = racine->filsGauche;
				else
					racine = NULL;
			}
			else
				break;
		}


		if(pere != NULL)
		{
			if(strcmp(noeud->mot, pere->mot) > 0)
			{
				pere->filsDroit = noeud;
				arbre->nb_mots_differents++;
			}

			else if(strcmp(noeud->mot, pere->mot) < 0)
			{
				pere->filsGauche = noeud;
				arbre->nb_mots_differents++;
			}

			else
			{
				//Le mot à ajouter existe déjà
				//Il faut mettre à jour sa liste position en ajoutant la position actuelle	
				ajouter_position(pere->positions, noeud->positions->debut->numero_ligne, noeud->positions->debut->ordre, noeud->positions->debut->numero_phrase);
			}

			arbre->nb_mots_total++;

			return 1;
		}
		else
			return 0;
	}
}

void afficher_arbre(ArbreABR * arbre)
{
	//Ici on choisit d'effectuer un parcours de type infixe pour 
	//afficher les mots par ordre alphabétique
	NoeudABR * racine = arbre->racine;
	Pile * p = creer_pile();

	while(racine != NULL || pile_vide(p) == 0)
	{
		while(racine != NULL)
		{
			empiler(p,racine);
			racine = racine->filsGauche;
		}

		racine = depiler(p);
		printf("%s ", racine->mot);
		afficher_positions(racine->positions);
		printf("\n");
		racine = racine->filsDroit;
	}
}