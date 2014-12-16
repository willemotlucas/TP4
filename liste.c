#include "liste.h"

#include <stdlib.h>
#include <stdio.h>

ListePosition * creer_liste_positions()
{
	ListePosition * listeP = malloc(sizeof(ListePosition));

	if(listeP != NULL)
	{
		listeP->debut = NULL;
		listeP->nb_elements = 0;
	}

	return listeP;
}

Position * init_position(int ligne, int ordre, int num_phrase)
{
	Position * p = malloc(sizeof(Position));

	if(p != NULL)
	{
		p->numero_ligne = ligne;
		p->ordre = ordre;
		p->numero_phrase = num_phrase;
		p->suivant = NULL;
	}

	return p;
}

int ajouter_position(ListePosition * listeP, int ligne, int ordre, int num_phrase)
{
	Position * p = init_position(ligne, ordre, num_phrase);

	if(listeP->nb_elements == 0)
	{
		listeP->debut = p;
		listeP->nb_elements++;

		return 1;
	}

	else if(listeP->nb_elements > 0)
	{
		Position * tmp = listeP->debut;
		
		while(tmp->suivant != NULL)
		{
			tmp = tmp->suivant;
		}

		tmp->suivant = p;
		listeP->nb_elements++;

		return 1;
	}

	return 0;
}

void afficher_positions(ListePosition * listeP)
{
	if(listeP->nb_elements > 0)
	{
		Position * p = listeP->debut;

		if(listeP->nb_elements == 1)
		{
			printf("%-10d|", p->numero_ligne);
			printf("%-10d|", p->ordre);
			printf("%-10d|", p->numero_phrase);
		}

		else
		{
			do
			{
				printf("%-10d|", p->numero_ligne);
				printf("%-10d|", p->ordre);
				printf("%-10d|", p->numero_phrase);
				printf("\n");
				printf("%-10s|", "");
				p = p->suivant;
			}while(p != NULL);
		}
	}
}